#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <PLAYER.h>
#include <AL_MAPA.h>

void desenhar_dialogo_npc(struct Player* player, struct al_mapa* mapa) {

	bool teste = false;


	int meio_tela = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2;

	int dialogue_box_size = meio_tela;
	int inner_dialogue_spacing = PIXEL_SIZE;

	int x_dialogue_box_initial = meio_tela - (dialogue_box_size / 2);
	int y_dialogue_box_initial = PIXEL_SIZE * 3;
	int x_dialogue_box_final = x_dialogue_box_initial + dialogue_box_size;

	int dialogue_text_size = 16;
	int spacing_between_text = dialogue_text_size + 6;

	int indice_bot = player->indice_bot_conversando;

	int spacing = 3;
	if (teste)
		spacing = 7;

	int y_dialogue_box_final = y_dialogue_box_initial
		+ spacing_between_text * (strlen(mapa->npc[indice_bot]->dialogo[mapa->npc[indice_bot]->dialogo_lido]->texto) / 50)
		+ inner_dialogue_spacing * spacing;

	al_draw_filled_rectangle(
		x_dialogue_box_initial,
		y_dialogue_box_initial,
		x_dialogue_box_final,
		y_dialogue_box_final,
		al_map_rgb(255, 255, 255)
	);

	int x_dialogue_name = x_dialogue_box_initial + inner_dialogue_spacing - PIXEL_SIZE / 2;
	int y_dialogue_name = y_dialogue_box_initial + inner_dialogue_spacing - PIXEL_SIZE;
	al_draw_text(
		mapa->dialogue16,
		al_map_rgb(0, 0, 0),
		x_dialogue_name,
		y_dialogue_name,
		0,
		mapa->npc[indice_bot]->nome
	);

	int x_dialogue_text = x_dialogue_box_initial + inner_dialogue_spacing;
	int y_dialogue_text = y_dialogue_box_initial + inner_dialogue_spacing;
	int x_dialogue_text_final = dialogue_box_size - inner_dialogue_spacing * 4;

	al_draw_multiline_text(
		mapa->dialogue16,
		al_map_rgb(0, 0, 0),
		x_dialogue_text,
		y_dialogue_text,
		x_dialogue_text_final,
		spacing_between_text,
		0,
		mapa->npc[indice_bot]->dialogo[mapa->npc[indice_bot]->dialogo_lido]->texto
	);

	int image_dialogue_size = PIXEL_SIZE * 4;

	int x_image_dialogue_initial = x_dialogue_box_final - (image_dialogue_size / 2);
	int y_image_dialogue_initial = y_dialogue_box_initial + PIXEL_SIZE / 2;

	al_draw_bitmap(
		mapa->npc[indice_bot]->foto,
		x_image_dialogue_initial,
		y_image_dialogue_initial,
		0
	);


	if (!teste) {
		int y_press_key = y_dialogue_box_final - spacing_between_text;
		al_draw_text(
			mapa->dialogue16,
			al_map_rgb(200, 200, 200),
			meio_tela,
			y_press_key,
			ALLEGRO_ALIGN_CENTER,
			"Aperte 'espaco' para continuar"
		);
	}
	else {

		int raio = dialogue_text_size / 2;
		int x_press_key_circle = x_dialogue_box_initial + inner_dialogue_spacing * 2;
		int y_press_key_circle = y_dialogue_box_final + raio - (inner_dialogue_spacing * 3);
		al_draw_filled_circle(
			x_press_key_circle,
			y_press_key_circle + 1,
			raio,
			al_map_rgb(255, 161, 0)
		);

		int x_press_key_text = x_press_key_circle + dialogue_text_size;
		int y_press_key_text = y_press_key_circle - raio ;
		al_draw_text(
			mapa->dialogue16,
			al_map_rgb(255, 161, 0),
			x_press_key_text,
			y_press_key_text,
			0,
			"Eu adoraria!"
		);

		int y_press_key_circle_2 = y_press_key_circle + dialogue_text_size * 2;
		al_draw_filled_circle(
			x_press_key_circle,
			y_press_key_circle_2,
			raio,
			al_map_rgb(220, 220, 220)
		);

		int y_press_key_text_2 = y_press_key_circle_2 - raio;
		al_draw_text(
			mapa->dialogue16,
			al_map_rgb(220, 220, 220),
			x_press_key_text,
			y_press_key_text_2,
			0,
			"No momento eu nao consigo."
		);

	}

}