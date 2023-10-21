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
#include <player.h>
#include <config.h>
#include <string.h>
#include <AL_MAPA.h>
#include <MAPA_CENTRO.h>
#include <MAPA.h>
#include <stdbool.h>
#include <ACTION.h>


int main() {
	ALLEGRO_DISPLAY* window = NULL;
	ALLEGRO_EVENT_QUEUE* events_queue = NULL;
	//ALLEGRO_KEYBOARD_STATE state;

	struct Player* player = malloc(sizeof(struct Player));

	if (player == NULL) {
		perror("Falha na alocação de memória");
		return 1;
	}

	player->matriz_position_x = 12;
	player->matriz_position_y = 7;

	player->map_position_x = player->matriz_position_x * PIXEL_SIZE;
	player->map_position_y = player->matriz_position_y * PIXEL_SIZE;

	player->status = PARADO;

	player->sum_x_pixel = 0;
	player->sum_y_pixel = 0;

	if (!al_init()) {
		fprintf(stderr, "Falha");
		return -1;
	}

	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();

	window = al_create_display(PIXEL_SIZE * WINDOW_SIZE_X, PIXEL_SIZE * WINDOW_SIZE_Y);

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

	ALLEGRO_BITMAP* walk = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_007.png");

	player->animation[0][0] = al_create_sub_bitmap(walk, 4 , 24 * 3 + 7, 16, 16);
	player->animation[0][1] = al_create_sub_bitmap(walk, 24 + 4, 24 * 3 + 7, 16, 16);
	player->animation[0][2] = al_create_sub_bitmap(walk, 4 + (24 * 2), 24 * 3 + 7, 16, 16);
	player->animation[0][3] = al_create_sub_bitmap(walk, 24 * 3 + 4, 24 * 3 + 7, 16, 16);

	player->animation[1][0] = al_create_sub_bitmap(walk, 4, 7, 16, 16);
	player->animation[1][1] = al_create_sub_bitmap(walk, 24 + 4, 7, 16, 16);
	player->animation[1][2] = al_create_sub_bitmap(walk, 24 * 2 + 4, 7, 16, 16);
	player->animation[1][3] = al_create_sub_bitmap(walk, 24 * 3 + 4, 7, 16, 16);

	player->animation[2][0] = al_create_sub_bitmap(walk, 4, 24 + 7, 16, 16);
	player->animation[2][1] = al_create_sub_bitmap(walk, 4 + 24, 24 + 7, 16, 16);
	player->animation[2][2] = al_create_sub_bitmap(walk, 4 + (24 * 2), 24 + 7, 16, 16);
	player->animation[2][3] = al_create_sub_bitmap(walk, 4 + (24 * 3), 24 + 7, 16, 16);

	player->animation[3][0] = al_create_sub_bitmap(walk, 4, 24 * 2 + 7, 16, 16);
	player->animation[3][1] = al_create_sub_bitmap(walk, 4 + 24, 24 * 2 + 7, 16, 16);
	player->animation[3][2] = al_create_sub_bitmap(walk, 4 + (24 * 2), 24 * 2 + 7, 16, 16);
	player->animation[3][3] = al_create_sub_bitmap(walk, 4 + (24 * 3), 24 * 2 + 7, 16, 16);

	mapa->NPC_IMAGES[0] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_001.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_002.png");
	mapa->NPC_IMAGES[2] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_003.png");
	mapa->NPC_IMAGES[3] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_004.png");
	mapa->NPC_IMAGES[4] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_005.png");
	mapa->NPC_IMAGES[5] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_006.png");
	mapa->NPC_IMAGES[6] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_007.png");

	ALLEGRO_BITMAP* tree = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\Vegetation\\Trees.png");

	ALLEGRO_BITMAP* tree_1 = al_create_sub_bitmap(tree, 0, 0, 16 * 3, 16 * 3 + 10);


	carregar_mapa(mapa, 0);

	player->image = player->animation[1][0];
	player->animation_next_image = 0;

	int fps_counter = 0;
	int show_sprite = 0;

	bool jogando = true;
	while (jogando) {

		while (!al_is_event_queue_empty(events_queue)) {
			ALLEGRO_EVENT event;
			al_wait_for_event(events_queue, &event);

			desenha_background(mapa);

			if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				jogando = false;
				break;
			}

			if (player->status == PARADO) {
				desenha_personagem(player, 0, 0);

				if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
					botao_presionado(event.keyboard.keycode, player);
					player->pressing_key = true;
				}
			}
			else {

				switch (player->status) {
				case ANDANDO:
					if(event.type == ALLEGRO_EVENT_KEY_UP) player->pressing_key = false;
					andar(player, mapa);
					break;
				case INTERAGINDO:
					interagir(player, mapa);
					break;

				}

				desenha_personagem(player, player->sum_x_pixel, player->sum_y_pixel);

			}

			desenha_npc(mapa);

			al_draw_scaled_bitmap(tree_1, 0, 0, 16 *3, 16*3+10, 11 * PIXEL_SIZE, 22 * PIXEL_SIZE, 16*3, 16*3, 0);
			
			al_flush_event_queue(events_queue);
			al_flip_display();
			al_clear_to_color(al_map_rgb(85, 173, 120));
		}
	}

	al_destroy_timer(timer);
	al_destroy_event_queue(events_queue);
	return 0;
}