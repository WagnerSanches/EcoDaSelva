#include <AL_MAPA.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <FICHARIO.h>
#include <PLAYER.h>
#include <DESENHA_FICHARIO.h>
#include <DIALOGO_CONFIG.h>
#include <DESENHA_AJUDANTE.H>

void desenhar_box(struct Fichario* fichario, struct Player* player, struct DialogoConfig* dialogoConfig) {

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

	char* text = "voce precisa coletar informacoes sobre um animal desconhecido para sua producao cientifica, atualmente este animal nao possui classificacoes sobre sua natureza feitas por voce,  interaja com os nativos e os ajudem em suas tarefas diarias para obter as informacoes necessarias para sua pesquisa.";
	int x_text = x_pgone_line_i + (PIXEL_SIZE / 2);
	int y_text = y_paper_i + (PIXEL_SIZE ) + (PIXEL_SIZE * 2) + 10;
	int size_text = PIXEL_SIZE * 13;
	al_draw_multiline_text(
		fichario->posicoes->font,
		al_map_rgb(50, 62, 168),
		x_text,
		y_text,
		size_text,
		space_line,
		ALLEGRO_ALIGN_LEFT,
		text
	);
	al_draw_multiline_text(
		fichario->posicoes->font,
		al_map_rgb(191, 122, 33),
		x_text,
		y_text + PIXEL_SIZE * 10,
		size_text,
		space_line,
		ALLEGRO_ALIGN_LEFT,
		"Dica: Os nativos que possuem informacoes uteis sao marcados por um ponto de exclamacao."
	);


	int middle_pgtwo = (x_pgtwo_i + x_pgtwo_f) / 2;
	int size_image = PIXEL_SIZE * 5;

	int x_photo_arrow = x_pgtwo_line_i + (PIXEL_SIZE / 2);
	int y_photo_arrow = y_paper_i + (PIXEL_SIZE * 2) + 10;;

	al_draw_text( 
		fichario->posicoes->font,
		al_map_rgb(50, 62, 168), 
		x_photo_arrow, 
		y_photo_arrow,
		ALLEGRO_ALIGN_LEFT, 
		"Uma \"quase\" foto"
	); 

	al_draw_text( 
		fichario->posicoes->font,
		al_map_rgb(50, 62, 168), 
		x_photo_arrow,
		y_photo_arrow + PIXEL_SIZE, 
		ALLEGRO_ALIGN_LEFT,
		" do animal"
	);

	al_draw_bitmap(fichario->posicoes->arrow, x_photo_arrow + PIXEL_SIZE * 2, y_photo_arrow + PIXEL_SIZE + 10 , 0);

	int x_image_i = PIXEL_SIZE * 3 + middle_pgtwo - (size_image / 2);
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
	int x_image_in_i = PIXEL_SIZE * 3 + middle_pgtwo - (size_image_in / 2) - space_image;
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

	al_draw_bitmap(fichario->posicoes->resize, x_image_in_i, y_image_in_i, 0);


	int x_size_tape = PIXEL_SIZE / 2;
	int y_size_tape = 20;

	int x_tape_i = PIXEL_SIZE * 3 + middle_pgtwo - (x_size_tape / 2);
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

	ALLEGRO_COLOR cores[7] = {
			al_map_rgb(191, 0, 0),
			al_map_rgb(191, 0, 108),
			al_map_rgb(105, 0, 191),
			al_map_rgb(0, 156, 191),
			al_map_rgb(0, 191, 70),
			al_map_rgb(191, 121, 0),
			al_map_rgb(188, 191, 0)
	};

	if (fichario->selecao->grupo_selecionado) {

		int x_category = middle_pgtwo;
		int y_category = y_paper_i + (PIXEL_SIZE * 7) + (PIXEL_SIZE * 2) + 10;

		for (int i = 0; i < 3; i++) {


			int x_circle = x_pgtwo_line_i + PIXEL_SIZE * 4; 
			if (fichario->selecao->classe == 3) {
				x_circle -= PIXEL_SIZE * 1.5;
			}

			int y_circle = y_paper_i + (PIXEL_SIZE * 7) + (PIXEL_SIZE * 2) + 18 + (PIXEL_SIZE * fichario->selecao->grupo); 
			al_draw_filled_circle(  
				x_circle, 
				y_circle, 
				5,
				cores[fichario->selecao->classe + 3]
			);

			al_draw_text(fichario->posicoes->subtitulo,
				cores[fichario->selecao->classe + 3],
				x_category,
				y_category,
				ALLEGRO_ALIGN_CENTER,
				fichario->classe[fichario->selecao->classe]->groupo[i]->titulo);

			y_category += PIXEL_SIZE;
		}

		if (fichario->classe[fichario->selecao->classe]->groupo[fichario->selecao->grupo]->mostrar_opcoes) {
			desenhar_ajudante(fichario->classe[fichario->selecao->classe]->groupo[fichario->selecao->grupo]->ajudante, dialogoConfig);
		}
	
	}
	else {
		int x_category = x_pgtwo_line_i + (PIXEL_SIZE * 2);
		int y_category = y_paper_i + (PIXEL_SIZE * 7) + (PIXEL_SIZE * 2) + 10;

		char* categoria[7] = {
			"Reino:",
			"Filo:",
			"Classe:",
			"Ordem:",
			"Familia:",
			"Genero:",
			"Especie:"
		};

		for (int i = 0; i < 7; i++) {
			al_draw_text(
				fichario->posicoes->font,
				al_map_rgb(50, 62, 168),
				x_category,
				y_category,
				ALLEGRO_ALIGN_LEFT,
				categoria[i]
			);

			y_category += PIXEL_SIZE;
		}

		char* respostas[3] = {
			"Animalia",
			"Chordata",
			"Amphibia "
		};

		x_category += PIXEL_SIZE * 4;
		y_category = y_paper_i + (PIXEL_SIZE * 7) + (PIXEL_SIZE * 2) + 10;
		for (int i = 0; i < 3; i++) {
			al_draw_text(
				fichario->posicoes->font,
				cores[i],
				x_category,
				y_category,
				ALLEGRO_ALIGN_LEFT,
				respostas[i]
			);

			y_category += PIXEL_SIZE;
		}

		y_category = y_paper_i + (PIXEL_SIZE * 10) + (PIXEL_SIZE * 2) + 10;
		for (int i = 0; i < 4; i++) {
			al_draw_text(
				fichario->posicoes->font,
				strcmp(player->respostas[i]->grupo, "Nao classificado") == 0 ? al_map_rgb(0, 0, 0) : cores[i + 3],
				x_category,
				y_category,
				ALLEGRO_ALIGN_LEFT,
				player->respostas[i]->grupo
			);

			y_category += PIXEL_SIZE;
		}

		int x_circle = x_pgtwo_line_i + PIXEL_SIZE * 1.5;
		int y_circle = y_paper_i + (PIXEL_SIZE * 10) + (PIXEL_SIZE * 2) + 18 + (PIXEL_SIZE * fichario->selecao->classe);

		if (fichario->selecao->classe == 4) {
			y_circle += PIXEL_SIZE;
			x_circle += PIXEL_SIZE * 3.5;
		}

		if (fichario->todas_respostas_selecionadas) {
			int x_final = x_pgtwo_line_i + PIXEL_SIZE * 6 - (PIXEL_SIZE/2);
			int y_final = y_paper_i + (PIXEL_SIZE * 15) + (PIXEL_SIZE * 2) + 8;

			al_draw_text(
				fichario->posicoes->font,
				al_map_rgb(50, 62, 168),
				x_final,
				y_final,
				ALLEGRO_ALIGN_LEFT,
				"FINALIZAR"
			);
		}

		al_draw_filled_circle(
			x_circle,
			y_circle,
			5,
			al_map_rgb(50, 62, 168)
		);
	}

}