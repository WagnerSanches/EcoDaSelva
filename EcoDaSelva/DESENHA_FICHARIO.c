#include <AL_MAPA.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <FICHARIO.h>
#include <DESENHA_FICHARIO.h>


void desenhar_box(struct Fichario* fichario) {

	al_draw_filled_rectangle(
		0,
		0,
		WINDOW_SIZE_PIXEL_X * PIXEL_SIZE,
		WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE,
		al_map_rgba_f(0, 0, 0, 0.5)
	);

	int size_box = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) - fichario->posicoes->espacamento_fichario_fora * 4;
	
	int x_box_i = ((WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2) - (size_box / 2);
	int x_box_f = x_box_i + size_box;

	int y_box_final = (WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE) - fichario->posicoes->espacamento_fichario_fora;

	int round = 5;

	al_draw_filled_rounded_rectangle( 
		x_box_i,
		fichario->posicoes->espacamento_fichario_fora,  
		x_box_f,
		y_box_final, 
		round,
		round,
		al_map_rgb(128, 93, 91));

	int middle_line_thickness = 1;
	int space_paper = (PIXEL_SIZE);

	int y_paper_i = fichario->posicoes->espacamento_fichario_fora + (space_paper / 2);
	int y_paper_f = y_box_final - (space_paper / 2); // 688

	int x_pgone_i = x_box_i + space_paper;
	int x_pgone_f = ((WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2) - middle_line_thickness;

	al_draw_filled_rounded_rectangle( 
		x_pgone_i,
		y_paper_i,
		x_pgone_f,
		y_paper_f,
		round,
		round,
		al_map_rgb(246, 238, 227));

	int x_pgtwo_i = ((WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2) + middle_line_thickness; 
	int x_pgtwo_f = x_box_f - space_paper;

	al_draw_filled_rounded_rectangle(
		x_pgtwo_i,
		y_paper_i,
		x_pgtwo_f, 
		y_paper_f, 
		round,
		round,
		al_map_rgb(246, 238, 227));


	int x_middle_line = ((WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2);
	al_draw_line(
		x_middle_line,
		y_paper_i + middle_line_thickness * 2,
		x_middle_line,
		y_paper_f - middle_line_thickness * 2,
		al_map_rgba_f(0, 0, 0, 0.2),
		middle_line_thickness
	);

	int y_pgone_line = y_paper_i + PIXEL_SIZE * 2;

	int x_pgone_line_i = x_pgone_i + space_paper;
	int x_pgone_line_f = x_middle_line - space_paper; 

	int x_pgtwo_line_i = x_middle_line + space_paper;
	int x_pgtwo_line_f = x_pgtwo_f - space_paper;

	int space_line = PIXEL_SIZE;

	for (int i = 0; i < 17; i++) {

		al_draw_line(
			x_pgone_line_i,
			y_pgone_line,
			x_pgone_line_f,
			y_pgone_line,
			al_map_rgb(173, 173, 173),
			2
		);
		
		al_draw_line(
			x_pgtwo_line_i,
			y_pgone_line,
			x_pgtwo_line_f,
			y_pgone_line,
			al_map_rgb(173, 173, 173),
			2
		);

		y_pgone_line += space_line;
	}

	ALLEGRO_FONT* font = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 18, 0);
	char* text = "voce precisa coletar informacoes sobre um animal desconhecido para sua producao cientifica, atualmente este animal nao possui classificacoes sobre sua natureza feitas por voce,  interaja com os nativos e os ajudem em suas tarefas diarias para obter as informacoes necessarias para sua pesquisa.\n\nDica: Os nativos que possuem informacoes uteis sao marcados por um ponto de exclamacao";
	int x_text = x_pgone_line_i + (PIXEL_SIZE / 2);
	int y_text = y_paper_i + (PIXEL_SIZE ) + (PIXEL_SIZE * 2) + 10;
	int size_text = PIXEL_SIZE * 13;
	al_draw_multiline_text(
		font,
		al_map_rgb(50, 62, 168),
		x_text,
		y_text,
		size_text,
		space_line,
		ALLEGRO_ALIGN_LEFT,
		text
	);

	int middle_pgtwo = (x_pgtwo_i + x_pgtwo_f) / 2;
	int size_image = PIXEL_SIZE * 5;

	int x_image_i = middle_pgtwo - (size_image / 2);
	int y_image_i = y_paper_i + (PIXEL_SIZE * 2) + 10;
	int x_image_f = x_image_i + size_image;
	int y_image_f = y_image_i + size_image;

	al_draw_filled_rectangle(
		x_image_i,
		y_image_i,
		x_image_f,
		y_image_f,
		al_map_rgb(253, 253, 253)
	);

	int space_image = PIXEL_SIZE / 4;
	int size_image_in = PIXEL_SIZE * 4;
	int x_image_in_i = middle_pgtwo - (size_image_in / 2) - space_image;
	int y_image_in_i = y_paper_i + (PIXEL_SIZE * 2) + 10 + space_image;
	int x_image_in_f = x_image_in_i + size_image_in + space_image * 2;
	int y_image_in_f = y_image_in_i + size_image_in;

	al_draw_filled_rectangle(
		x_image_in_i,
		y_image_in_i,
		x_image_in_f,
		y_image_in_f,
		al_map_rgb(0, 0, 0)
	);

	int x_size_tape = PIXEL_SIZE / 2;
	int y_size_tape = 20;

	int x_tape_i = middle_pgtwo - (x_size_tape / 2);
	int y_tape_i = y_image_i - 6;
	int x_tape_f = x_tape_i + x_size_tape;
	int y_tape_f = y_tape_i + y_size_tape;
	al_draw_filled_rectangle(
		x_tape_i,
		y_tape_i,
		x_tape_f,
		y_tape_f,
		al_map_rgb(201, 136, 60)
	);


	//int x_box_title = (x_box_final / 2) + fichario->posicoes->espacamento_fichario_dentro;
	//int y_box_title = fichario->posicoes->espacamento_fichario_fora + fichario->posicoes->espacamento_fichario_dentro;
	//al_draw_text(fichario->posicoes->titulo, al_map_rgb(135, 121, 55), x_box_title, y_box_title, ALLEGRO_ALIGN_CENTER, "Fichario");

	//int x_box_subtitle = (x_box_final / 2) + fichario->posicoes->espacamento_fichario_dentro;
	//int y_box_subtitle = fichario->posicoes->espacamento_fichario_fora + fichario->posicoes->espacamento_fichario_dentro + (30) /*espacamento entre as letras*/;
	//al_draw_text(fichario->posicoes->descricao, al_map_rgb(145, 135, 86), x_box_subtitle, y_box_subtitle, ALLEGRO_ALIGN_CENTER, "Classifique o animal desconhecido com base nas informacoes coletadas.");

	//int x_box_line_initial = fichario->posicoes->espacamento_fichario_fora + fichario->posicoes->espacamento_fichario_dentro * 3;
	//int x_box_line_final = x_box_final - fichario->posicoes->espacamento_fichario_dentro * 3;
	//int y_box_line = y_box_subtitle + fichario->posicoes->espacamento_fichario_dentro;
	//al_draw_line(x_box_line_initial, y_box_line, x_box_line_final, y_box_line, al_map_rgb(145, 135, 50), 1);

	///* SUBBOX */
	//fichario->posicoes->x_subbox_initial = x_box_line_initial;
	//fichario->posicoes->y_subbox_initial = y_box_line;
	//fichario->posicoes->x_subbox_final = x_box_line_final;
	//fichario->posicoes->y_subbox_final = y_box_final - fichario->posicoes->espacamento_fichario_dentro;
	////al_draw_filled_rectangle(x_subbox_initial, y_subbox_initial, x_subbox_final, y_subbox_final, al_map_rgb(67, 161, 53));

	al_destroy_font(font);
}