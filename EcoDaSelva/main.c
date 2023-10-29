#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro_font.h>
#include <time.h>
#include <eventos.h>
#include <animation.h>
#include <PLAYER.h>
#include <config.h>
#include <string.h>
#include <AL_MAPA.h>
#include <MAPA_CENTRO.h>
#include <DESENHA_JOGO.h>
#include <stdbool.h>
#include <ACTION.h>
#include <FICHARIO.h>
#include <DESENHA_MENU_INICIAL.h>
#include <PAUSA.h>

int main() {

#pragma region "inicializacao allegro"
	ALLEGRO_DISPLAY* window = NULL;
	ALLEGRO_EVENT_QUEUE* events_queue = NULL;
	bool jogando = true;
	bool redraw = false;

	if (!al_init()) {
		fprintf(stderr, "Falha");
		return -1;
	}

	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();	
	al_init_font_addon();
	al_init_ttf_addon();
	
	bool fullscreen = true;

	if (fullscreen) {

		ALLEGRO_MONITOR_INFO monitor_info;
		int screen_res_x, screen_res_y;
		al_get_monitor_info(0, &monitor_info);

		screen_res_x = monitor_info.x2 - monitor_info.x1;
		screen_res_y = monitor_info.y2 - monitor_info.y1;

		al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
		window = al_create_display(screen_res_x, screen_res_y);

		if (!window) {
			fprintf(stderr, "Falha");
			return -1;
		}

		float rx = screen_res_x / (float)(WINDOW_SIZE_PIXEL_X * PIXEL_SIZE);
		float ry = screen_res_y / (float)(WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE);

		ALLEGRO_TRANSFORM transformar;
		al_identity_transform(&transformar);
		al_scale_transform(&transformar, rx, ry);
		al_use_transform(&transformar);
	}
	else {
		window = al_create_display(
			(WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) - PIXEL_SIZE * 4,
			(WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE) - PIXEL_SIZE * 4
		);
		if (!window) {
			fprintf(stderr, "Falha");
			return -1;
		}
	}

	al_set_window_title(window, "Eco da Selva");

	events_queue = al_create_event_queue();
	if (!events_queue) {
		fprintf(stderr, "Falha");
		al_destroy_display(window);

		return -1;
	}

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	if (!timer)
	{
		printf("couldn't initialize timer\n");
		return 1;
	}

	al_register_event_source(events_queue, al_get_keyboard_event_source());
	al_register_event_source(events_queue, al_get_timer_event_source(timer));
	al_register_event_source(events_queue, al_get_display_event_source(window));

	al_start_timer(timer);

	struct al_mapa* mapa = malloc(sizeof(struct al_mapa));
	if (mapa == NULL) {
		return -1;
	}

	struct Player* player = malloc(sizeof(struct Player));
	if (player == NULL) {
		perror("Falha na alocação de player");
		return -1;
	}

	struct Fichario* fichario = malloc(sizeof(struct Fichario));
	if (fichario == NULL) {
		printf("Falha na alocação de fichario.\n");
		return -1;
	}

	struct Pausa* pausa = malloc(sizeof(struct Pausa));
	if (pausa == NULL) {
		printf("Falha na alocação de pausa.\n");
		return -1;
	}
	pausa->opcao = 0;
	pausa->pausado = false;
	pausa->reiniciar = false;
	pausa->encerrar = false;

#pragma endregion 

	init_player(player);
	init_mapa(mapa);
	init_fichario(fichario);

	while (jogando) {

		while (!al_is_event_queue_empty(events_queue)) {
			ALLEGRO_EVENT event;
			al_wait_for_event(events_queue, &event);

			if (pausa->encerrar) {
				player->menu->ativo = true;
				pausa->encerrar = false;
				continue;
			}

			switch (event.type) {
			case ALLEGRO_EVENT_KEY_UP:
				tecla_levantada(player, mapa, fichario, pausa, event.keyboard.keycode);
				break;
			case ALLEGRO_EVENT_KEY_DOWN:
				tecla_presionado(player, mapa, fichario, pausa, event.keyboard.keycode);
				break;
			case ALLEGRO_EVENT_TIMER:

				switch (player->status) {
				case PARADO:
					// menu
					break;
				case ANDANDO: 
				case CORRENDO:
					andar(player, mapa);
					break;
				case INTERAGINDO:
					interagir(player, mapa);
					break;
				case FICHARIO:
					acessar(player, fichario);
					break;
				case CONVERSANDO:
					conversar(player, mapa);
					break;
				case MENU:
					if(player->menu->encerrar)
						jogando = false;
					break;
				}

				redraw = true;
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				jogando = false;
				return;
			}

			if (redraw) {

				if (player->menu->ativo)
					desenhar_menu_inicial(player->menu);
				else 
					desenhar_jogo(player, mapa, fichario, pausa);
				

				al_flush_event_queue(events_queue);
				al_flip_display();
				al_clear_to_color(al_map_rgb(85, 173, 120));

				redraw = false;
			}
		}
	}

	al_destroy_timer(timer);
	al_destroy_event_queue(events_queue);
	return 0;
}