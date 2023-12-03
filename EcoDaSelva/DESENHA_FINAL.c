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

	ALLEGRO_BITMAP* background = al_load_bitmap("assets/jogo/FinalBackground.jpg");
	al_draw_bitmap(background, 0, 0, 0);
	ALLEGRO_FONT* sub_tittle_animal = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 16, 0);


	al_draw_scaled_bitmap(player->animation[1][0], 0, 0, 16, 16, PIXEL_SIZE * 11, PIXEL_SIZE * 11, 32, 32, 0);

	int meio_tela = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2;	
	int meio_box_score = meio_tela + (meio_tela / 2);
	int x_box_score_size = meio_tela - PIXEL_SIZE * 4;
	int y_box_score_size = PIXEL_SIZE * 14;

	int x_score_box_i = meio_box_score - x_box_score_size / 2;
	int y_score_box_i = PIXEL_SIZE * 4;
	int x_score_box_f = x_score_box_i + x_box_score_size;
	int y_score_box_f = y_score_box_i + y_box_score_size;
	al_draw_filled_rounded_rectangle(   
		x_score_box_i,
		y_score_box_i,
		x_score_box_f,
		y_score_box_f,
		5,
		5,
		al_map_rgb(246, 238, 227)
	);

	int img_animal_size = PIXEL_SIZE * 5;
	int spacing = PIXEL_SIZE / 2;
	int x_img_animal_i = x_score_box_f - img_animal_size - spacing;
	int y_img_animal_i = y_score_box_i + spacing * 3.5;

	int tittle_score = y_score_box_i + spacing;
	al_draw_text(
		sub_tittle_animal,
		al_map_rgb(0, 0, 0),
		meio_box_score, 
		tittle_score, 
		ALLEGRO_ALIGN_CENTER,
		"O animal procurado era o..."
	);


	ALLEGRO_BITMAP* animal = al_load_bitmap("assets/jogo/animal.jpg");
	ALLEGRO_BITMAP* resize = al_create_sub_bitmap(animal, PIXEL_SIZE * 6.5, PIXEL_SIZE * 5, img_animal_size, img_animal_size);
	al_draw_bitmap(resize, x_img_animal_i, y_img_animal_i, 0);

	int font_size_tittle_animal = 22;

	ALLEGRO_FONT* tittle_animal = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size_tittle_animal, 0);
	int x_tittle_animal = x_score_box_i + spacing * 2;
	int y_tittle_animal = y_score_box_i + spacing * 3.5;
	al_draw_text(
		tittle_animal,
		al_map_rgb(0, 0, 0),
		x_tittle_animal,
		y_tittle_animal,
		0,
		"Phyllobates terribilis"
	);

	int x_sub_tittle_animal = x_score_box_i + spacing * 2;
	int y_sub_tittle_animal = y_score_box_i + spacing * 5;
	al_draw_text( 
		sub_tittle_animal, 
		al_map_rgba_f(0, 0, 0, 0.5), 
		x_sub_tittle_animal,
		y_sub_tittle_animal,
		0,
		"(Sapo dourado da amazonia)"
	);

	y_tittle_animal += PIXEL_SIZE / 2;


	char* textos[4] = {
		"FILO:",
		"FAMILIA:",
		"GENERO:",
		"ESPECIE:"
	};

	char* respostas[4] = {
		"Anura",
		"Dendrobatidae",
		"Phyllobates",
		"Phyllobates terribilis"
	};

	int font_size_categoria = 16;
	int spacing_categoria = font_size_categoria + font_size_categoria / 2;
	ALLEGRO_FONT* font_categoria = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size_categoria, 0);

	int x_categoria = x_tittle_animal + spacing_categoria / 2;

	int categoria_box_size = PIXEL_SIZE * 7;			//	Mudar depois
	int x_categoria_res_i = x_score_box_i + meio_tela / 5;
	int x_categoria_res_f = x_categoria_res_i + categoria_box_size;
	int sum_pontos = 0;

	for (int i = 0; i < 4; i++) {

		bool resposta = strcmp(player->respostas[i]->grupo, respostas[i]) == 0;

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
			resposta ? al_map_rgb(83, 212, 143) : al_map_rgb(212, 83, 83)
		);

		int x_categoria_res = x_categoria_res_i + (categoria_box_size / 2);
		al_draw_text( 
			font_categoria, 
			resposta ? al_map_rgb(0, 97, 45) : al_map_rgb(97, 0, 0),
			x_categoria_res,
			y_categoria,
			ALLEGRO_ALIGN_CENTER,
			player->respostas[i]->grupo
		);

		sum_pontos += resposta ? 1 : 0; // Coloque a classe certa na ordem certa
	}

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
		al_map_rgb(0, 0, 0),
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

	int thickness = 8;
	int y_sellect_i = (y_score + PIXEL_SIZE * 2) + (player->opcao_final_jogo * PIXEL_SIZE);
	int y_sellect_f = y_sellect_i + y_botao_size;
	al_draw_rounded_rectangle( 
		x_botao_reiniciar_i - 1,
		y_sellect_i + 2,
		x_botao_reiniciar_f - 3,
		y_sellect_f + 1,
		5,
		5,
		al_map_rgb(31, 63, 43),
		thickness / 2
	);

	for (int i = 0; i < 2; i++) {
		int y_botao_reiniciar_i = (y_score + PIXEL_SIZE * 2) + (i * PIXEL_SIZE);
		int y_botao_reiniciar_f = y_botao_reiniciar_i + y_botao_size;
		al_draw_filled_rounded_rectangle( 
			x_botao_reiniciar_i,
			y_botao_reiniciar_i,
			x_botao_reiniciar_f,
			y_botao_reiniciar_f,
			5,
			5,
			al_map_rgb(118, 197, 100)
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

	al_destroy_bitmap(background); 
	al_destroy_bitmap(animal); 
	al_destroy_bitmap(resize); 
	al_destroy_font(font_points); 
	al_destroy_font(font_categoria);
	al_destroy_font(sub_tittle_animal); 
	al_destroy_font(tittle_animal);
}