#include <PAUSA.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <config.h>

void desenhar_pausa(struct Pausa* pausa) {

	int font_size = 18;
	ALLEGRO_BITMAP* font18 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size, 0);

	al_draw_filled_rectangle(
		0,
		0,
		WINDOW_SIZE_PIXEL_X * PIXEL_SIZE,
		WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE,
		al_map_rgba_f(0, 0, 0, 0.5)
	);

	int meio_tela = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2;
	int size_pause = PIXEL_SIZE * 10;

	int valor_teste = PIXEL_SIZE * 7;

	int x_pause_initial = meio_tela - (size_pause / 2);
	int y_pause_initial = PIXEL_SIZE * 5;
	int x_pause_final = x_pause_initial + size_pause;
	int y_pause_final = y_pause_initial + valor_teste;

	al_draw_filled_rectangle(
		x_pause_initial, 
		y_pause_initial, 
		x_pause_final, 
		y_pause_final, 
		al_map_rgb(246, 238, 227)
	);

	int x_button_size = PIXEL_SIZE * 5;
	int y_button_size = (font_size)+(font_size / 2);
	int x_button = meio_tela - (x_button_size / 2);
	int y_button = y_pause_initial + PIXEL_SIZE * 2;
	int spacing = PIXEL_SIZE / 4;

	char* textos[3] = {
		"VOLTAR",
		"REINICIAR",
		"SAIR"
	};

	int thickness = 2;
	int x_selected_button_initial = x_button - thickness + 1;
	int y_selected_button_initial = (y_button - thickness) + (pausa->opcao * (y_button_size + spacing)) + 1;
	int x_selected_button_final = x_selected_button_initial + x_button_size + thickness;
	int y_selected_button_final = y_selected_button_initial + y_button_size + thickness;

	al_draw_rectangle(
		x_selected_button_initial,
		y_selected_button_initial,
		x_selected_button_final,
		y_selected_button_final,
		al_map_rgb(31, 63, 43),
		thickness
	);

	for (int i = 0; i < 3; i++) {

		int y_button_initial = y_button + (i * (spacing + y_button_size));
		int x_button_final = x_button + x_button_size;
		int y_button_final = y_button_initial + y_button_size;

		al_draw_filled_rectangle(
			x_button,
			y_button_initial,
			x_button_final,
			y_button_final,
			al_map_rgb(118, 197, 100)
		);

		int y_button_text = y_button_initial + (font_size / 4);
		al_draw_text(
			font18,
			al_map_rgb(255, 255, 255),
			meio_tela,
			y_button_text,
			ALLEGRO_ALIGN_CENTER,
			textos[i]
		);

	}

	al_destroy_font(font18);
}