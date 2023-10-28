#include <AJUDANTE.h>
#include <config.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

void desenhar_ajudante(struct Ajudante* ajudante) {

	ALLEGRO_FONT* dialogue16 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 16, 0);
	ALLEGRO_BITMAP* imagem_doutura = al_load_bitmap("assets/personagem/ajudante/doutora_resize.jpg");

	int meio_tela = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2;
	int dialogue_text_size = 16;
	int spacing = 4;
	int spacing_between_text = dialogue_text_size + 6;

	int dialogue_box_size = meio_tela;
	int inner_dialogue_spacing = PIXEL_SIZE;

	int x_dialogue_box_initial = meio_tela - (dialogue_box_size / 2);
	int y_dialogue_box_initial = PIXEL_SIZE * 3;
	int x_dialogue_box_final = x_dialogue_box_initial + dialogue_box_size;

	int y_dialogue_box_final = y_dialogue_box_initial
		+ spacing_between_text * (strlen(ajudante->texto) / 50)
		+ inner_dialogue_spacing * spacing;

	al_draw_filled_rectangle(
		x_dialogue_box_initial,
		y_dialogue_box_initial,
		x_dialogue_box_final,
		y_dialogue_box_final,
		al_map_rgb(255, 255, 255)
	);

	char* nome = "Dr. Mary Anning";
	int size_dialogue_box_name = 12 * strlen(nome);

	int x_dialogue_box_name_initial = x_dialogue_box_initial + inner_dialogue_spacing - PIXEL_SIZE / 2;
	int y_dialogue_box_name_initial = y_dialogue_box_initial - PIXEL_SIZE / 4;
	int x_dialogue_box_name_final = x_dialogue_box_name_initial + size_dialogue_box_name;
	int y_dialogue_box_name_final = y_dialogue_box_name_initial + 8 + dialogue_text_size;

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
		dialogue16,
		al_map_rgb(255, 255, 255),
		x_dialogue_name,
		y_dialogue_name,
		ALLEGRO_ALIGN_CENTER,
		nome
	);

	int x_dialogue_text = x_dialogue_box_initial + inner_dialogue_spacing;
	int y_dialogue_text = y_dialogue_box_initial + inner_dialogue_spacing;
	int x_dialogue_text_final = dialogue_box_size - inner_dialogue_spacing * 4;

	al_draw_multiline_text(
		dialogue16,
		al_map_rgb(0, 0, 0),
		x_dialogue_text,
		y_dialogue_text,
		x_dialogue_text_final,
		spacing_between_text,
		0,
		ajudante->texto
	);

	int image_dialogue_size = PIXEL_SIZE * 4;

	int x_image_dialogue_initial = x_dialogue_box_final - (image_dialogue_size / 2);
	int y_image_dialogue_initial = y_dialogue_box_initial + PIXEL_SIZE / 2;

	al_draw_bitmap(
		imagem_doutura,
		x_image_dialogue_initial,
		y_image_dialogue_initial,
		0
	);

	int y_press_key = y_dialogue_box_final - spacing_between_text - PIXEL_SIZE / 2;
	al_draw_text(
		dialogue16,
		al_map_rgb(200, 200, 200),
		meio_tela,
		y_press_key,
		ALLEGRO_ALIGN_CENTER,
		"Aperte 'espaco' para continuar"
	);

	al_destroy_bitmap(imagem_doutura);
	al_destroy_font(dialogue16);
}