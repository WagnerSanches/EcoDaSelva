#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <time.h>

int main() {


	ALLEGRO_DISPLAY* window = NULL;
	ALLEGRO_EVENT_QUEUE* events_queue = NULL;
	ALLEGRO_COLOR wall = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR player = al_map_rgb(0, 255, 0);

	int PIXEL_MAP = 40;

	if (!al_init()) {
		fprintf(stderr, "Falha");
		return -1;
	}

	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();

	window = al_create_display(400, 400);

	if (!window) {
		fprintf(stderr, "Falha");
		return -1;
	}

	al_set_window_title(window, "Teste de janela");

	events_queue = al_create_event_queue();
	if (!events_queue) {
		fprintf(stderr, "Falha");
		al_destroy_display(window);

		return -1;
	}


	int mapa[15][15] = {
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};



	int stopPlaying = 0;
	int nextColumn, nextLine = 0;

	ALLEGRO_KEYBOARD_STATE state;
	
	float personagem_posicao_x = 2 * 40;
	float personagem_posicao_y = 2 * 40;

	int action = 0;
	int andando = 0; 

	float x_destino = 0;
	float y_destino = 0;

	int frame = 1;
	while (stopPlaying == 0) {

		if(frame % 400 == 0) {

			al_get_keyboard_state(&state);
	
			if (action == 1) {
				if (andando == 1) {

					printf("desitno %f\n", x_destino);
					printf("personagem_posicao_x %f\n", personagem_posicao_x);

					if (personagem_posicao_x != x_destino || personagem_posicao_y != y_destino) {

						personagem_posicao_x = personagem_posicao_x - 1;
						if (personagem_posicao_x >= 30 && personagem_posicao_x <= 31) {
							printf("personagem_posicao_x %f\n", personagem_posicao_x);
						}

						al_draw_filled_rectangle(personagem_posicao_x, personagem_posicao_y, personagem_posicao_x + PIXEL_MAP, personagem_posicao_y + PIXEL_MAP, player, 0);
					}
				}
			} else {

				for (int linha = 0; linha < 10; linha++) {
					for (int coluna = 0; coluna < 10; coluna++) {


						if (mapa[linha][coluna] == 1) {

							int y_position = linha * 40;
							int x_position = coluna * 40;

							al_draw_filled_rectangle(x_position, y_position, x_position + PIXEL_MAP, y_position + PIXEL_MAP, wall, 0);
						}

						if (mapa[linha][coluna] == 2) {

							int y_position = linha * 40;
							int x_position = coluna * 40;

							al_draw_filled_rectangle(x_position, y_position, x_position + PIXEL_MAP, y_position + PIXEL_MAP, player, 0);
						}

					}
				}


				if (al_key_down(&state, ALLEGRO_KEY_UP)) {

					mapa[2][2] = 0;
					mapa[1][2] = 2;

					action = 1;
					andando = 1;
			
					x_destino = personagem_posicao_x - 40;
					y_destino = personagem_posicao_y;

				}
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
		frame++;
	}

	return 0;

}