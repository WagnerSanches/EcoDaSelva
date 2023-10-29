#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <FICHARIO.h>
#include <DESENHA_FICHARIO.h>


void desenhar_box(struct Fichario* fichario) {

	fichario->posicoes->espacamento_fichario_fora = (PIXEL_SIZE * 2);
	fichario->posicoes->espacamento_fichario_dentro = PIXEL_SIZE;
	fichario->posicoes->size_font_titulo = 28;
	fichario->posicoes->size_font_subtitulo = 22;
	fichario->posicoes->size_font_description = 18;
	fichario->posicoes->size_font_tag = 16;

	int x_box_final = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) - fichario->posicoes->espacamento_fichario_fora;
	int y_box_final = (WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE) - fichario->posicoes->espacamento_fichario_fora;
	al_draw_filled_rectangle(fichario->posicoes->espacamento_fichario_fora, fichario->posicoes->espacamento_fichario_fora, x_box_final, y_box_final, al_map_rgb(186, 181, 93));

	int x_box_title = (x_box_final / 2) + fichario->posicoes->espacamento_fichario_dentro;
	int y_box_title = fichario->posicoes->espacamento_fichario_fora + fichario->posicoes->espacamento_fichario_dentro;
	al_draw_text(fichario->posicoes->titulo28, al_map_rgb(135, 121, 55), x_box_title, y_box_title, ALLEGRO_ALIGN_CENTER, "Fichario");

	int x_box_subtitle = (x_box_final / 2) + fichario->posicoes->espacamento_fichario_dentro;
	int y_box_subtitle = fichario->posicoes->espacamento_fichario_fora + fichario->posicoes->espacamento_fichario_dentro + (30) /*espacamento entre as letras*/;
	al_draw_text(fichario->posicoes->descricao18, al_map_rgb(145, 135, 86), x_box_subtitle, y_box_subtitle, ALLEGRO_ALIGN_CENTER, "Classifique o animal desconhecido com base nas informacoes.");

	int x_box_line_initial = fichario->posicoes->espacamento_fichario_fora + fichario->posicoes->espacamento_fichario_dentro * 3;
	int x_box_line_final = x_box_final - fichario->posicoes->espacamento_fichario_dentro * 3;
	int y_box_line = y_box_subtitle + fichario->posicoes->espacamento_fichario_dentro;
	al_draw_line(x_box_line_initial, y_box_line, x_box_line_final, y_box_line, al_map_rgb(145, 135, 50), 1);

	/* SUBBOX */
	fichario->posicoes->x_subbox_initial = x_box_line_initial;
	fichario->posicoes->y_subbox_initial = y_box_line;
	fichario->posicoes->x_subbox_final = x_box_line_final;
	fichario->posicoes->y_subbox_final = y_box_final - fichario->posicoes->espacamento_fichario_dentro;
	//al_draw_filled_rectangle(x_subbox_initial, y_subbox_initial, x_subbox_final, y_subbox_final, al_map_rgb(67, 161, 53));

}