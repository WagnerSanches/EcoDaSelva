#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <config.h>
#include <PLAYER.h>

void desenhar_menu_inicial(struct Menu* menu) {

	int font_size = 20;
	ALLEGRO_FONT* menu22 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size, 0);

	int meio_tela = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2;
	int x_menu_size = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) - (PIXEL_SIZE * 24);
	int y_menu_size = PIXEL_SIZE * 3;
	int spacing = PIXEL_SIZE;

	al_draw_bitmap(menu->background, 0, 0, 0);

	int x_menu_initial = meio_tela - (x_menu_size / 2);
	int y_menu_initial = y_menu_size;
	int x_menu_final = x_menu_initial + x_menu_size;
	int y_menu_final = (WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE) - y_menu_size;

	al_draw_filled_rectangle(
		x_menu_initial,
		y_menu_initial,
		x_menu_final,
		y_menu_final,
		al_map_rgb(246, 238, 227)
	);

	int x_logo_size = PIXEL_SIZE * 12;
	int y_logo_size = PIXEL_SIZE * 6;

	int x_logo_initial = meio_tela - (x_logo_size / 2);
	int y_logo_initial = y_menu_initial + spacing;
	int x_logo_final = x_logo_initial + x_logo_size;
	int y_logo_final = y_logo_initial + y_logo_size;

	al_draw_filled_rectangle(
		x_logo_initial,
		y_logo_initial,
		x_logo_final,
		y_logo_final,
		al_map_rgb(255, 255, 170)
	);

	int x_button_size = PIXEL_SIZE * 6;
	int y_button_size = font_size + font_size / 2;

	int x_button_initial = meio_tela - (x_button_size / 2);
	int y_button_initial = (y_logo_final + spacing * 2);

	char* textos[2] = {
		"JOGAR",
		"SAIR"
	};

	int thickness = 4;
	int x_button_selected_initial = x_button_initial - thickness / 2;
	int y_button_selected_initial = (y_button_initial + (menu->opcao * (y_button_size + spacing / 4))) - thickness / 2;
	int x_button_selected_final = x_button_selected_initial + x_button_size + thickness ;
	int y_button_selected_final = y_button_selected_initial + y_button_size + thickness ;

	al_draw_rectangle(
		x_button_selected_initial,
		y_button_selected_initial,
		x_button_selected_final,
		y_button_selected_final,
		al_map_rgb(31, 63, 43),
		thickness
	);

	for (int i = 0; i < 2; i++) {

		int y_button = y_button_initial + (i * (y_button_size + spacing / 4));
		int x_button_final = x_button_initial + x_button_size;
		int y_button_final = y_button + y_button_size;

		al_draw_filled_rectangle(
			x_button_initial,
			y_button,
			x_button_final,
			y_button_final,
			al_map_rgb(82, 132, 60)
		);

		int y_button_text_initial = (font_size / 4) + y_button;

		al_draw_text(
			menu22,
			al_map_rgb(255, 255, 255),
			meio_tela,
			y_button_text_initial,
			ALLEGRO_ALIGN_CENTER,
			textos[i]
		);
	}
	
	al_destroy_font(menu22);
}