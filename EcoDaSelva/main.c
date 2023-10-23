#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <time.h>
#include <eventos.h>
#include <animation.h>
#include <PLAYER.h>
#include <config.h>
#include <string.h>
#include <AL_MAPA.h>
#include <MAPA_CENTRO.h>
#include <MAPA.h>
#include <stdbool.h>
#include <ACTION.h>
#include <STATUS.h>

int main() {
	
#pragma region "inicializacao allegro"
	ALLEGRO_DISPLAY* window = NULL;
	ALLEGRO_EVENT_QUEUE* events_queue = NULL;
	bool jogando = true;
	bool redraw = true;

	if (!al_init()) {
		fprintf(stderr, "Falha");
		return -1;
	}

	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();

	window = al_create_display(PIXEL_SIZE * WINDOW_SIZE_PIXEL_X, PIXEL_SIZE * WINDOW_SIZE_PIXEL_Y);

	if (!window) {
		fprintf(stderr, "Falha");
		return -1;
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
		return 1;
	}


	struct Player* player = malloc(sizeof(struct Player));

	if (player == NULL) {
		perror("Falha na alocação de memória");
		return 1;
	}

#pragma endregion 

	init_player(player);
	init_mapa(mapa);

	while (jogando) {

		while (!al_is_event_queue_empty(events_queue)) {
			ALLEGRO_EVENT event;
			al_wait_for_event(events_queue, &event);
		
			switch (event.type) {
			case ALLEGRO_EVENT_KEY_UP:
				tecla_levantada(player, event.keyboard.keycode);
				break;
			case ALLEGRO_EVENT_KEY_DOWN:
				tecla_presionado(player, event.keyboard.keycode);
				break;
			case ALLEGRO_EVENT_TIMER:

				switch (player->status) {
				case PARADO:
					// menu
					break;
				case ANDANDO: case CORRENDO:
					andar(player, mapa);
					break;
				case INTERAGINDO:
					interagir(player, mapa);
					break;
				}

				redraw = true;
				break;
			case ALLEGRO_EVENT_DISPLAY_CLOSE:
				jogando = false;
				return;
			}

			if (redraw) {
				desenha_jogo(player, mapa);

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