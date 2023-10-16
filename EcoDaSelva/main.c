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
#include <viewport.h>

#define PIXEL_SIZE 32

int main() {

	ALLEGRO_DISPLAY* window = NULL;
	ALLEGRO_EVENT_QUEUE* events_queue = NULL;
	ALLEGRO_KEYBOARD_STATE state;
	ALLEGRO_BITMAP* background = NULL;


	enum Estados *estados = malloc(sizeof(enum Estados));
	
	if (estados == NULL) {
		perror("Falha na alocação de memória");
		return 1;
	}
	*estados = IDLE;

	struct Direcao *direcao = malloc(sizeof(struct Direcao));

	if (direcao == NULL) {
		perror("Falha na alocação de memória");
		return 1;
	}
	direcao->sentido = 0;
	direcao->x = 0;
	direcao->y = 0;

	struct Player *player = malloc(sizeof(struct Player));

	if (player == NULL) {
		perror("Falha na alocação de memória");
		return 1;
	}

	player->position_x = 12;
	player->position_y = 7;

	struct Viewport *viewport = malloc(sizeof(struct Viewport));

	if (viewport == NULL) {
		perror("Falha na alocação de memória");
		return 1;
	}

	viewport->x = 0;
	viewport->y = 0;


	if (!al_init()) {
		fprintf(stderr, "Falha");
		return -1;
	}

	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();


	window = al_create_display(PIXEL_SIZE * 32, PIXEL_SIZE * 24);

	if (!window) {
		fprintf(stderr, "Falha");
		return -1;
	}

	al_set_window_title(window, "Eco da Selva");


	background = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\mapa32p.png");
	if (!background)
	{
		fprintf(stderr, "failed to load background bitmap!\n");
		return -1;
	}

	events_queue = al_create_event_queue();
	if (!events_queue) {
		fprintf(stderr, "Falha");
		al_destroy_display(window);

		return -1;
	}

	ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
	if (!timer)
	{
		printf("couldn't initialize timer\n");
		return 1;
	}

	al_register_event_source(events_queue, al_get_keyboard_event_source());
	al_register_event_source(events_queue, al_get_timer_event_source(timer));
	int pressed = 0;
	int mexeu = 0;

	al_start_timer(timer);
	while (1) {

		while (!al_is_event_queue_empty(events_queue)) {

			ALLEGRO_EVENT event;
			al_wait_for_event(events_queue, &event);
			
			if (*estados == IDLE) {
				printa_mapa(background, viewport);
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
					andar(direcao, estados, player, pressed, background, viewport);
					break;
				}
			}

			al_flush_event_queue(events_queue);
			al_flip_display();
			al_clear_to_color(al_map_rgb(85, 173, 120));
		}


	}

	al_destroy_timer(timer);
	al_destroy_event_queue(events_queue);
	return 0;

}