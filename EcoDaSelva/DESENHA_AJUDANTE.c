#include <AJUDANTE.h>
#include <config.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <DIALOGO_CONFIG.h>

void desenhar_ajudante(struct Ajudante* ajudante, struct DialogoConfig* dialogoConfig) {

	al_draw_filled_rectangle(
		0,
		0,
		WINDOW_SIZE_PIXEL_X * PIXEL_SIZE,
		WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE,
		al_map_rgba_f(0, 0, 0, 0.5)
	);

	int meio_tela = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2;
	int spacing_between_text = dialogoConfig->dialogue_text_size + 10;

	int spacing = 4;
	if (ajudante->opcao)
		spacing = 7;

	int dialogue_box_size = meio_tela;
	int inner_dialogue_spacing = PIXEL_SIZE;

	int x_dialogue_box_initial = meio_tela - (dialogue_box_size / 2);
	int y_dialogue_box_initial = PIXEL_SIZE * 3;
	int x_dialogue_box_final = x_dialogue_box_initial + dialogue_box_size;

	int y_dialogue_box_final = y_dialogue_box_initial
		+ spacing_between_text * (strlen(ajudante->texto) / 40)
		+ inner_dialogue_spacing * spacing;

	al_draw_filled_rectangle(
		x_dialogue_box_initial,
		y_dialogue_box_initial,
		x_dialogue_box_final,
		y_dialogue_box_final,
		al_map_rgb(255, 243, 212)
	);

	char* nome = "Dr. Mary Anning";
	int size_dialogue_box_name = 15 * strlen(nome);

	int x_dialogue_box_name_initial = x_dialogue_box_initial + inner_dialogue_spacing - PIXEL_SIZE / 2;
	int y_dialogue_box_name_initial = y_dialogue_box_initial - PIXEL_SIZE / 4;
	int x_dialogue_box_name_final = x_dialogue_box_name_initial + size_dialogue_box_name;
	int y_dialogue_box_name_final = y_dialogue_box_name_initial + 8 + dialogoConfig->dialogue_text_size;

	al_draw_filled_rectangle(
		x_dialogue_box_name_initial,
		y_dialogue_box_name_initial,
		x_dialogue_box_name_final,
		y_dialogue_box_name_final,
		al_map_rgb(181, 102, 27)
	);

	int x_dialogue_name = x_dialogue_box_name_initial + size_dialogue_box_name / 2;
	int y_dialogue_name = y_dialogue_box_name_initial + 4;

	al_draw_text(
		dialogoConfig->dialogue16,
		al_map_rgb(255, 255, 255),
		x_dialogue_name,
		y_dialogue_name,
		ALLEGRO_ALIGN_CENTER,
		nome
	);

	int x_dialogue_text = x_dialogue_box_initial + inner_dialogue_spacing * 2;
	int y_dialogue_text = y_dialogue_box_initial + inner_dialogue_spacing + 16;
	int x_dialogue_text_final = dialogue_box_size - inner_dialogue_spacing * 5;

	al_draw_multiline_text(
		dialogoConfig->dialogue16,
		al_map_rgb(0, 0, 0),
		x_dialogue_text,
		y_dialogue_text,
		x_dialogue_text_final,
		spacing_between_text,
		ALLEGRO_ALIGN_INTEGER,
		ajudante->texto
	);

	int image_dialogue_size = PIXEL_SIZE * 4;

	int x_image_dialogue_initial = x_dialogue_box_final - (image_dialogue_size / 2);
	int y_image_dialogue_initial = y_dialogue_box_initial + PIXEL_SIZE / 2;

	al_draw_bitmap(
		dialogoConfig->imagem_doutura,
		x_image_dialogue_initial,
		y_image_dialogue_initial,
		0
	);


	int image_size = 256;
	int x_info_image_1 = x_dialogue_box_initial - image_size / 2 - PIXEL_SIZE * 1.5;
	int y_info_image_1 = y_dialogue_box_initial + PIXEL_SIZE * 2;

	int x_info_image_2 = x_dialogue_box_final - PIXEL_SIZE * 3;
	int y_info_image_2 = y_dialogue_box_final - (image_size / 2);

	for (int i = 0; i < ajudante->quantiade_imagem; i++) {
		al_draw_bitmap(
			ajudante->image[i],
			x_info_image_1,
			y_info_image_1,
			0
		);

	}

	if (ajudante->opcao) {



		int selecionado = ajudante->opcao_selecionada;
		int raio = dialogoConfig->dialogue_text_size / 2;
		int x_press_key_circle = x_dialogue_box_initial + inner_dialogue_spacing * 3;
		int y_press_key_circle = y_dialogue_box_final + raio - (inner_dialogue_spacing * 3);

		if (ajudante->tipo_pergunta == PERGUNTA_INFORMACAO) {
			int y_press_key_question = y_press_key_circle - PIXEL_SIZE - PIXEL_SIZE / 4;
			al_draw_text(
				dialogoConfig->dialogue16,
				al_map_rgb(0, 0, 0),
				x_press_key_circle - raio * 2,
				y_press_key_question,
				0,
				"Selecionar categoria ?"
			);
		}
		else {
			int y_press_key_question = y_press_key_circle - PIXEL_SIZE - PIXEL_SIZE / 4;
			al_draw_text(
				dialogoConfig->dialogue16,
				al_map_rgb(0, 0, 0),
				x_press_key_circle - raio * 2,
				y_press_key_question,
				0,
				"Pegar item ?"
			);
		}

		al_draw_filled_circle(
			x_press_key_circle,
			y_press_key_circle + 1,
			raio,
			selecionado == 0 ? al_map_rgb(255, 161, 0) : al_map_rgb(180, 180, 180)
		);

		int x_press_key_text = x_press_key_circle + dialogoConfig->dialogue_text_size;
		int y_press_key_text = y_press_key_circle - raio;
		al_draw_text(
			dialogoConfig->dialogue16,
			selecionado == 0 ? al_map_rgb(255, 161, 0) : al_map_rgb(180, 180, 180),
			x_press_key_text,
			y_press_key_text,
			0,
			"Sim."
		);

		int y_press_key_circle_2 = y_press_key_circle + dialogoConfig->dialogue_text_size * 2;
		al_draw_filled_circle(
			x_press_key_circle,
			y_press_key_circle_2,
			raio,
			selecionado == 1 ? al_map_rgb(255, 161, 0) : al_map_rgb(180, 180, 180)
		);

		int y_press_key_text_2 = y_press_key_circle_2 - raio;
		al_draw_text(
			dialogoConfig->dialogue16,
			selecionado == 1 ? al_map_rgb(255, 161, 0) : al_map_rgb(180, 180, 180),
			x_press_key_text,
			y_press_key_text_2,
			0,
			"Nao."
		);

	}
	else {

		ALLEGRO_FONT* dialogue15 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 15, 0);

		int y_press_key = y_dialogue_box_final - spacing_between_text - PIXEL_SIZE / 2;
		al_draw_text(
			dialogue15,
			al_map_rgb(190, 190, 190),
			meio_tela,
			y_press_key,
			ALLEGRO_ALIGN_CENTER,
			"Aperte 'espaco' para continuar"
		);

		al_destroy_font(dialogue15);
	}

}