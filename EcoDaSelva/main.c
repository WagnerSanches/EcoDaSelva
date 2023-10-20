#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <time.h>
#include <Direcao.h>
#include <eventos.h>
#include <enum_estados.h>
#include <animation.h>
#include <Direcao.h>
#include <player.h>
#include <enum_maps.h>
#include <config.h>
#include <string.h>
#include <AL_MAPA.h>
#include <MAPA_CENTRO.h>
#include <MAPA.h>


int main() {
	ALLEGRO_DISPLAY* window = NULL;
	ALLEGRO_EVENT_QUEUE* events_queue = NULL;
	ALLEGRO_KEYBOARD_STATE state;

#pragma region MyRegion



	enum Mapas* mapa_indice = malloc(sizeof(enum Mapas));

	if (mapa_indice == NULL) {
		perror("Falha na alocação de memória");
		return 1;
	}
	*mapa_indice = CENTRO;


	enum Estados* estados = malloc(sizeof(enum Estados));

	if (estados == NULL) {
		perror("Falha na alocação de memória");
		return 1;
	}
	*estados = IDLE;

	struct Direcao* direcao = malloc(sizeof(struct Direcao));

	if (direcao == NULL) {
		perror("Falha na alocação de memória");
		return 1;
	}
	direcao->sentido = 0;
	direcao->x = 0;
	direcao->y = 0;

	struct Player* player = malloc(sizeof(struct Player));

	if (player == NULL) {
		perror("Falha na alocação de memória");
		return 1;
	}

	player->position_x = 12;
	player->position_y = 7;


	if (!al_init()) {
		fprintf(stderr, "Falha");
		return -1;
	}

	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();


	window = al_create_display(PIXEL_SIZE * 32, PIXEL_SIZE * 24);

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
#pragma endregion
	int x = 1;
	int y = 1;

	int pressed = 0;

	//struct al_mapa* mapa = malloc(sizeof(struct al_mapa));

	//if (mapa == NULL) {
	//	fprintf(stderr, "Erro ao carregar a imagem.\n");
	//	return 1;
	//}

	struct al_mapa* mapa = malloc(sizeof(struct al_mapa));

	if (mapa == NULL) {
		return 1;
	}
	carregar_mapa(mapa, 0);

	while (1) {

		while (!al_is_event_queue_empty(events_queue)) {

			ALLEGRO_EVENT event;
			al_wait_for_event(events_queue, &event);

			if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;

			printa_mapa(mapa->background);

			if (*estados == IDLE) {
				printa_personagem(player->position_x, player->position_y);
				switch (event.type) {
				case ALLEGRO_EVENT_KEY_DOWN:
					botao_presionado(event.keyboard.keycode, direcao, estados, player);
					pressed = 1;
					break;
				}
			}
			else {

				switch (event.type) {
				case ALLEGRO_EVENT_KEY_UP:
					pressed = 0;
					break;
				}

				switch (*estados) {
				case ANDANDO:
					andar(direcao, estados, player, pressed, mapa);
					break;
				}
			}

			desenha_mapa(mapa);
			al_flush_event_queue(events_queue);
			al_flip_display();
			al_clear_to_color(al_map_rgb(85, 173, 120));
		}
	}

	al_destroy_timer(timer);
	al_destroy_event_queue(events_queue);
	return 0;

}