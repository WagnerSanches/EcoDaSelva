#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <stdio.h>
#include <allegro5/allegro_color.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <MAPA_PRAIA.h>
#include <player.h>
#include <FICHARIO.h>
#include <DESENHA_FICHARIO.h>
#include <DESENHA_FICHARIO_INFO.h>
#include <DESENHA_FICHARIO_OPCOES.h>
#include <DESENHA_DIALOGO_NPC.h>
#include <string.h>
#include <AJUDANTE.h>
#include <DESENHA_AJUDANTE.H>
#include <PAUSA.h>
#include <DESENHA_PAUSA.h>

void desenhar_final(struct Player* player) {
	al_draw_filled_rectangle(0, 0, WINDOW_SIZE_PIXEL_X * PIXEL_SIZE, WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE, al_map_rgb(83, 207, 212));

	int meio_tela = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2;
	int meio_box_score = meio_tela + (meio_tela / 2);
	int x_box_score_size = meio_tela - PIXEL_SIZE * 4;
	int y_box_score_size = PIXEL_SIZE * 14;

	int x_score_box_i = meio_box_score - x_box_score_size / 2;
	int y_score_box_i = PIXEL_SIZE * 4;
	int x_score_box_f = x_score_box_i + x_box_score_size;
	int y_score_box_f = y_score_box_i + y_box_score_size;
	al_draw_filled_rectangle(
		x_score_box_i,
		y_score_box_i,
		x_score_box_f,
		y_score_box_f,
		al_map_rgb(255, 255, 170)
	);

	int img_animal_size = PIXEL_SIZE * 5;
	int spacing = PIXEL_SIZE / 2;
	int x_img_animal_i = x_score_box_f - img_animal_size - spacing;
	int y_img_animal_i = y_score_box_i + spacing;
	int x_img_animal_f = x_img_animal_i + img_animal_size;
	int y_img_animal_f = y_img_animal_i + img_animal_size;
	al_draw_filled_rectangle(
		x_img_animal_i,
		y_img_animal_i,
		x_img_animal_f,
		y_img_animal_f,
		al_map_rgb(255, 255, 255)
	);

	int font_size_tittle_animal = 22;

	ALLEGRO_FONT* tittle_animal = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size_tittle_animal, 0);
	int x_tittle_animal = x_score_box_i + spacing * 2;
	int y_tittle_animal = y_score_box_i + spacing * 2;
	al_draw_text(
		tittle_animal,
		al_map_rgb(0, 0, 0),
		x_tittle_animal,
		y_tittle_animal,
		0,
		"Squirtle"
	);

	char* textos[4] = {
		"FILO:",
		"FAMILIA:",
		"GENERO:",
		"ESPECIE:"
	};

	int font_size_categoria = 16;
	int spacing_categoria = font_size_categoria + font_size_categoria / 2;
	ALLEGRO_FONT* font_categoria = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size_categoria, 0);

	int x_categoria = x_tittle_animal + spacing_categoria / 2;

	int categoria_box_size = PIXEL_SIZE * 7;			//	Mudar depois
	int x_categoria_res_i = x_score_box_i + meio_tela / 5;
	int x_categoria_res_f = x_categoria_res_i + categoria_box_size;

	for (int i = 0; i < 4; i++) {
		int y_categoria = y_tittle_animal + font_size_tittle_animal + spacing_categoria + (spacing_categoria * i);
		al_draw_text(
			font_categoria,
			al_map_rgb(0, 0, 0),
			x_categoria,
			y_categoria,
			0,
			textos[i]
		);

		int y_categoria_box_res_f = y_categoria + font_size_categoria;
		al_draw_filled_rectangle(
			x_categoria_res_i,
			y_categoria,
			x_categoria_res_f,
			y_categoria_box_res_f + 2,
			al_map_rgb(83, 212, 143)
		);

		int x_categoria_res = x_categoria_res_i + (categoria_box_size / 2);
		al_draw_text(
			font_categoria,
			al_map_rgb(0, 97, 45),
			x_categoria_res,
			y_categoria,
			ALLEGRO_ALIGN_CENTER,
			player->respostas[i]->grupo
		);
	}

	int sum_pontos = strcmp(player->respostas[0]->grupo, "Arcnidio") == 0 ? 1 : 0; // Coloque a classe certa na ordem certa
	sum_pontos += strcmp(player->respostas[1]->grupo, "Arcnidio") == 0 ? 1 : 0; // Coloque a classe certa na ordem certa
	sum_pontos += strcmp(player->respostas[2]->grupo, "Arcnidio") == 0 ? 1 : 0; // Coloque a classe certa na ordem certa
	sum_pontos += strcmp(player->respostas[3]->grupo, "Arcnidio") == 0 ? 1 : 0; // Coloque a classe certa na ordem certa

	int y_final_score = y_tittle_animal + font_size_tittle_animal + spacing_categoria + (spacing_categoria * 4) + PIXEL_SIZE;
	al_draw_text(
		font_categoria,
		al_map_rgb(0, 0, 0),
		meio_box_score,
		y_final_score,
		ALLEGRO_ALIGN_CENTER,
		"Quantidade de categorias acertadas"
	);

	int font_size_points = 30;
	char pontos[4];
	sprintf(pontos, "%d/4", sum_pontos);

	ALLEGRO_FONT* font_points = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size_points, 0);
	int y_score = y_final_score + 20;
	al_draw_text(
		font_points,
		al_map_rgb(201, 201, 0),
		meio_box_score,
		y_score,
		ALLEGRO_ALIGN_CENTER,
		pontos
	);

	int x_butao_size = PIXEL_SIZE * 5;
	int y_botao_size = font_size_tittle_animal + 2;
	char* textos_b[2] = {
		"Jogar novamente",
		"Sair"
	};
	int x_botao_reiniciar_i = meio_box_score - (x_butao_size / 2);
	int x_botao_reiniciar_f = x_botao_reiniciar_i + x_butao_size;

	int thickness = 6;
	int y_sellect_i = (y_score + PIXEL_SIZE * 2) + (player->opcao_final_jogo * PIXEL_SIZE);
	int y_sellect_f = y_sellect_i + y_botao_size;
	al_draw_rectangle(
		x_botao_reiniciar_i - 1,
		y_sellect_i - 1,
		x_botao_reiniciar_f + 1,
		y_sellect_f + 2,
		al_map_rgb(10, 0, 138),
		thickness / 2
	);

	for (int i = 0; i < 2; i++) {
		int y_botao_reiniciar_i = (y_score + PIXEL_SIZE * 2) + (i * PIXEL_SIZE);
		int y_botao_reiniciar_f = y_botao_reiniciar_i + y_botao_size;
		al_draw_filled_rectangle(
			x_botao_reiniciar_i,
			y_botao_reiniciar_i,
			x_botao_reiniciar_f,
			y_botao_reiniciar_f,
			al_map_rgb(92, 83, 212)
		);

		int x_botao_text = x_botao_reiniciar_f - (x_butao_size / 2);
		al_draw_text(
			font_categoria,
			al_map_rgb(255, 255, 255),
			x_botao_text,
			y_botao_reiniciar_i + 4,
			ALLEGRO_ALIGN_CENTER,
			textos_b[i]
		);
	}

	al_destroy_font(font_points);
	al_destroy_font(font_categoria);
	al_destroy_font(tittle_animal);
}