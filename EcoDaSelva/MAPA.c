#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <MAPA_CENTRO.h>
#include <MAPA_1.h>
#include <MAPA_2.h>
#include <MAPA_3.h>
#include <MAPA_4.h>
#include <player.h>
#include <FICHARIO.h>

void excluir_mapa(struct al_mapa* mapa) {
	if(mapa->criado) {

		al_destroy_bitmap(mapa->background);

		for (int i = 0; i < mapa->quantidade_npc; i++) {
			al_destroy_bitmap(mapa->NPC_IMAGES[i]);

			al_destroy_bitmap(mapa->npc[i].image[0]);
			al_destroy_bitmap(mapa->npc[i].image[1]);
			al_destroy_bitmap(mapa->npc[i].image[2]);
			al_destroy_bitmap(mapa->npc[i].image[3]);

		}

		// excluir os items
		for (int i = 0; i < mapa->quantidade_item; i++) {

		}

		free(mapa);
		
		mapa = malloc(sizeof(struct al_mapa));

		if (mapa == NULL) {
			printf("Erro ao tentar\n");
			return 1;
		}

		for (int k = 0; k < WINDOW_SIZE_PIXEL_Y; k++) {
			for (int j = 0; j < WINDOW_SIZE_PIXEL_X; j++) {
				mapa->matriz[k][j] = 0;
			}
		}

		mapa->next_mapa.pra_cima = 0;
		mapa->next_mapa.pra_baixo = 0;
		mapa->next_mapa.pra_esquerda = 0;
		mapa->next_mapa.pra_direita = 0;

		mapa->criado = false;
	}
}

void carregar_mapa(struct al_mapa* mapa, int next_mapa) {

	excluir_mapa(mapa);

	switch (next_mapa) {
	case 0:
		carregar_mapa_centro(mapa);
		break;
	case 1:
		carregar_mapa_centro_cima(mapa);
		break;
	case 2:
		carregar_mapa_centro_baixo(mapa);
		break;
	case 3:
		carregar_mapa_centro_esquerda(mapa);
		break;
	case 4:
		carregar_mapa_centro_direita(mapa);
		break;
	}
}

void desenha_background(struct al_mapa* mapa) {
	al_draw_bitmap(mapa->background, 0, 0, 0);
}

void desenha_npc(struct al_mapa* mapa, int layer) {
	for (int i = 0; i < mapa->quantidade_npc; i++) {
		if (mapa->npc[i].matriz_position_y == layer) {
			al_draw_scaled_bitmap(mapa->npc[i].image[mapa->npc[i].direcao], 0, 0, 16, 16, mapa->npc[i].matriz_position_x * PIXEL_SIZE, mapa->npc[i].matriz_position_y * PIXEL_SIZE, 32, 32, 0);
			al_draw_rectangle(mapa->npc[i].matriz_position_x * PIXEL_SIZE, mapa->npc[i].matriz_position_y * PIXEL_SIZE, mapa->npc[i].matriz_position_x * PIXEL_SIZE + PIXEL_SIZE, mapa->npc[i].matriz_position_y * PIXEL_SIZE + PIXEL_SIZE, al_map_rgb(186, 181, 93),0);
		}
	}
}

void desenha_personagem(struct Player* player, int layer) {
	if(player->matriz_position_y == layer)
		al_draw_scaled_bitmap(player->image, 0, 0, 16, 16, player->map_position_x + player->sum_x_pixel, player->map_position_y + player->sum_y_pixel, 32, 32, 0);
}

void desenha_items(struct al_mapa* mapa, int layer) {

}

void desenha_fichario(struct Player* player, struct Fichario* fichario) {

	int espacamento_fichario_fora = (PIXEL_SIZE * 2);
	int espacamento_fichario_dentro = PIXEL_SIZE;
	int size_font_titulo = 28;
	int size_font_subtitulo = 22;
	int size_font_description = 18;
	int size_font_tag = 16;

	
	int x_box_final = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) - espacamento_fichario_fora;
	int y_box_final = (WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE) - espacamento_fichario_fora;
	al_draw_filled_rectangle(espacamento_fichario_fora, espacamento_fichario_fora, x_box_final, y_box_final, al_map_rgb(186, 181, 93));

	int x_box_title = (x_box_final / 2) + espacamento_fichario_dentro;
	int y_box_title =espacamento_fichario_fora + espacamento_fichario_dentro;
	al_draw_text(fichario->titulo28, al_map_rgb(135, 121, 55), x_box_title, y_box_title, ALLEGRO_ALIGN_CENTER, "Fichario");

	int x_box_subtitle = (x_box_final / 2) + espacamento_fichario_dentro;
	int y_box_subtitle = espacamento_fichario_fora + espacamento_fichario_dentro + (30) /*espacamento entre as letras*/;
	al_draw_text(fichario->descricao18, al_map_rgb(145, 135, 86), x_box_subtitle, y_box_subtitle, ALLEGRO_ALIGN_CENTER, "Classifique o animal desconhecido com base nas informacoes.");

	int x_box_line_initial = espacamento_fichario_fora + espacamento_fichario_dentro * 3;
	int x_box_line_final = x_box_final - espacamento_fichario_dentro * 3;
	int y_box_line = y_box_subtitle + espacamento_fichario_dentro;
	al_draw_line(x_box_line_initial, y_box_line, x_box_line_final, y_box_line, al_map_rgb(145, 135, 50), 1);

	/* SUBBOX */
	int x_subbox_initial = x_box_line_initial;
	int y_subbox_initial = y_box_line;
	int x_subbox_final = x_box_line_final;
	int y_subbox_final = y_box_final - espacamento_fichario_dentro;
	//al_draw_filled_rectangle(x_subbox_initial, y_subbox_initial, x_subbox_final, y_subbox_final, al_map_rgb(67, 161, 53));

	/*tamanho da tela: 1088*/

	/* SUBBOX INFO */
	int x_subbox_info_size = 352;
	int x_subbox_info_initial = x_subbox_initial;
	int x_subbox_info_final = x_subbox_info_initial + x_subbox_info_size;
	int meio_subbox_info = x_subbox_info_initial + (x_subbox_info_final - x_subbox_info_initial) / 2;
	//al_draw_filled_rectangle(x_subbox_info_initial, y_subbox_initial, x_subbox_info_final, y_subbox_final, al_map_rgb(161, 53, 80));

	int box_size_image = 128;
	int x_box_image_initial = meio_subbox_info - (box_size_image / 2);
	//int x_box_image_initial = x_box_line_initial + espacamento_fichario_dentro;
	int x_box_image_final = x_box_image_initial + box_size_image;
	int y_box_image_initial = y_box_line + espacamento_fichario_dentro * 2;
	int y_box_image_final = y_box_image_initial + box_size_image;
	al_draw_filled_rectangle(x_box_image_initial, y_box_image_initial, x_box_image_final, y_box_image_final, al_map_rgb(170, 170, 170));

	/* INICIO CLASSIFICACAO */

	/*		Classificao 1		*/	

	int x_box_1_class_title = x_box_image_initial + box_size_image / 2;
	int y_box_1_class_title = y_box_image_final + espacamento_fichario_dentro;
	al_draw_text(fichario->descricao18, al_map_rgb(145, 135, 86), x_box_1_class_title, y_box_1_class_title, ALLEGRO_ALIGN_CENTER, "Ordem");
	
	int x_box_size_tag = 224;
	int y_box_size_tag = size_font_tag + 4;
	int espacamento_text_tag = 25;
	int x_box_1_class_tag_initial = x_box_1_class_title - x_box_size_tag / 2;
	int y_box_1_class_tag_initial = y_box_1_class_title + espacamento_text_tag;
	int x_box_1_class_tag_final = x_box_1_class_tag_initial + x_box_size_tag;
	int y_box_1_class_tag_final = y_box_1_class_tag_initial + y_box_size_tag;
	al_draw_filled_rectangle(x_box_1_class_tag_initial, y_box_1_class_tag_initial, x_box_1_class_tag_final, y_box_1_class_tag_final, al_map_rgb(170, 170, 170));

	// verificacao se o usuario ja nao colocou alguma classificacao
	int x_box_1_class_text = x_box_1_class_title;
	int y_box_1_class_text = y_box_1_class_title + espacamento_text_tag + (y_box_size_tag - size_font_tag) / 4;
	al_draw_text(fichario->tag16, al_map_rgb(255, 255, 255), x_box_1_class_text, y_box_1_class_text, ALLEGRO_ALIGN_CENTER, "Nao classificado");

	/*		Classificao 2		*/

	int espacamento_class_class = 20;

	int x_box_2_class_title = x_box_image_initial + box_size_image / 2;
	int y_box_2_class_title = y_box_1_class_tag_final + espacamento_class_class;
	al_draw_text(fichario->descricao18, al_map_rgb(145, 135, 86), x_box_2_class_title, y_box_2_class_title, ALLEGRO_ALIGN_CENTER, "Familia");

	int x_box_2_class_tag_initial = x_box_2_class_title - x_box_size_tag / 2;
	int y_box_2_class_tag_initial = y_box_2_class_title + espacamento_text_tag;
	int x_box_2_class_tag_final = x_box_2_class_tag_initial + x_box_size_tag;
	int y_box_2_class_tag_final = y_box_2_class_tag_initial + y_box_size_tag;
	al_draw_filled_rectangle(x_box_2_class_tag_initial, y_box_2_class_tag_initial, x_box_2_class_tag_final, y_box_2_class_tag_final, al_map_rgb(170, 170, 170));

	// verificacao se o usuario ja nao colocou alguma classificacao
	int x_box_2_class_text = x_box_2_class_title;
	int y_box_2_class_text = y_box_2_class_title + espacamento_text_tag + (y_box_size_tag - size_font_tag) / 4;
	al_draw_text(fichario->tag16, al_map_rgb(255, 255, 255), x_box_2_class_text, y_box_2_class_text, ALLEGRO_ALIGN_CENTER, "Nao classificado");

	/*		Classificao 3		*/

	int x_box_3_class_title = x_box_image_initial + box_size_image / 2;
	int y_box_3_class_title = y_box_2_class_tag_final + espacamento_class_class;
	al_draw_text(fichario->descricao18, al_map_rgb(145, 135, 86), x_box_3_class_title, y_box_3_class_title, ALLEGRO_ALIGN_CENTER, "Genero");

	int x_box_3_class_tag_initial = x_box_3_class_title - x_box_size_tag / 2;
	int y_box_3_class_tag_initial = y_box_3_class_title + espacamento_text_tag;
	int x_box_3_class_tag_final = x_box_3_class_tag_initial + x_box_size_tag;
	int y_box_3_class_tag_final = y_box_3_class_tag_initial + y_box_size_tag;
	al_draw_filled_rectangle(x_box_3_class_tag_initial, y_box_3_class_tag_initial, x_box_3_class_tag_final, y_box_3_class_tag_final, al_map_rgb(170, 170, 170));

	// verificacao se o usuario ja nao colocou alguma classificacao
	int x_box_3_class_text = x_box_3_class_title;
	int y_box_3_class_text = y_box_3_class_title + espacamento_text_tag + (y_box_size_tag - size_font_tag) / 4;
	al_draw_text(fichario->tag16, al_map_rgb(255, 255, 255), x_box_3_class_text, y_box_3_class_text, ALLEGRO_ALIGN_CENTER, "Nao classificado");

	/*		Classificao 4		*/

	int x_box_4_class_title = x_box_image_initial + box_size_image / 2;
	int y_box_4_class_title = y_box_3_class_tag_final + espacamento_class_class;
	al_draw_text(fichario->descricao18, al_map_rgb(145, 135, 86), x_box_4_class_title, y_box_4_class_title, ALLEGRO_ALIGN_CENTER, "Especie");

	int x_box_4_class_tag_initial = x_box_4_class_title - x_box_size_tag / 2;
	int y_box_4_class_tag_initial = y_box_4_class_title + espacamento_text_tag;
	int x_box_4_class_tag_final = x_box_4_class_tag_initial + x_box_size_tag;
	int y_box_4_class_tag_final = y_box_4_class_tag_initial + y_box_size_tag;
	al_draw_filled_rectangle(x_box_4_class_tag_initial, y_box_4_class_tag_initial, x_box_4_class_tag_final, y_box_4_class_tag_final, al_map_rgb(170, 170, 170));

	// verificacao se o usuario ja nao colocou alguma classificacao
	int x_box_4_class_text = x_box_4_class_title;
	int y_box_4_class_text = y_box_4_class_title + espacamento_text_tag + (y_box_size_tag - size_font_tag) / 4;
	al_draw_text(fichario->tag16, al_map_rgb(255, 255, 255), x_box_4_class_text, y_box_4_class_text, ALLEGRO_ALIGN_CENTER, "Nao classificado");

	/* FINAL CLASSIFICACAO */


	/* INICIO OPCOES */

	int x_subbox_options_initial = x_subbox_info_final;
	int y_subbox_options_initial = y_subbox_initial;
	int x_subbox_options_final = x_subbox_final;
	int y_subbox_options_final = y_subbox_final;
	int meio_subbox_options = (x_subbox_options_initial + (x_subbox_options_final - x_subbox_options_initial) / 2);

	al_draw_filled_rectangle(x_subbox_options_initial, y_subbox_options_initial, x_subbox_options_final, y_subbox_options_final, /*al_map_rgb(190, 170, 80)*/ al_map_rgb(186, 181, 93));

	/*	CAIXA DE OPCOES	 */
	
	int espacemento_y_inner_subbox_option = espacamento_fichario_dentro * 3;
	int espacemento_y_subbox_option_option = espacamento_fichario_dentro;

	int x_subbox_size_button_option = 384;
	int y_subbox_size_button_option = size_font_subtitulo + 24;
	
	int x_subbox_button_option_initial = meio_subbox_options - (x_subbox_size_button_option / 2);
	int x_subbox_button_option_final = x_subbox_button_option_initial + x_subbox_size_button_option;
	int y_subbox_button_option_initial = y_subbox_options_initial + espacemento_y_inner_subbox_option;

	/* LINHAS BRANCA OPCAO */
	int line_thickness_button_selected = 4;
	int x_selected_option_initial = x_subbox_button_option_initial - line_thickness_button_selected;
	int y_selected_option_initial = ((y_subbox_button_option_initial + (fichario->classe_selecionada * (y_subbox_size_button_option + espacemento_y_subbox_option_option)) ) - (line_thickness_button_selected ) ) + 2;
	int x_selected_option_final = x_subbox_button_option_final + line_thickness_button_selected;
	int y_selected_option_final = y_selected_option_initial + y_subbox_size_button_option + line_thickness_button_selected;
	al_draw_rectangle(x_selected_option_initial, y_selected_option_initial, x_selected_option_final, y_selected_option_final, al_map_rgb(255, 255, 255), line_thickness_button_selected);
	/* FINAL - LINHAS BRANCA OPCAO */

	/* OPCAO 1 */
	int y_subbox_button_option_1_initial = y_subbox_button_option_initial;
	int y_subbox_button_option_1_final = y_subbox_button_option_1_initial + y_subbox_size_button_option;
	al_draw_filled_rectangle(x_subbox_button_option_initial, y_subbox_button_option_1_initial, x_subbox_button_option_final, y_subbox_button_option_1_final, al_map_rgb(161, 127, 53));

	int y_subbox_1_option_text = y_subbox_button_option_1_initial + (y_subbox_size_button_option / 4);
	al_draw_text(fichario->subtitulo22, al_map_rgb(255, 255, 255), meio_subbox_options, y_subbox_1_option_text, ALLEGRO_ALIGN_CENTER, "Classificar Ordem");

	/* OPCAO 2 */
	int y_subbox_button_option_2_initial = y_subbox_button_option_1_final + espacemento_y_subbox_option_option;
	int y_subbox_button_option_2_final = y_subbox_button_option_2_initial + y_subbox_size_button_option;
	al_draw_filled_rectangle(x_subbox_button_option_initial, y_subbox_button_option_2_initial, x_subbox_button_option_final, y_subbox_button_option_2_final, al_map_rgb(161, 127, 53));

	int y_subbox_2_option_text = y_subbox_button_option_2_initial + (y_subbox_size_button_option / 4);
	al_draw_text(fichario->subtitulo22, al_map_rgb(255, 255, 255), meio_subbox_options, y_subbox_2_option_text, ALLEGRO_ALIGN_CENTER, "Classificar Familia");

	/* OPCAO 3 */
	int y_subbox_button_option_3_initial = y_subbox_button_option_2_final + espacemento_y_subbox_option_option;
	int y_subbox_button_option_3_final = y_subbox_button_option_3_initial + y_subbox_size_button_option;
	al_draw_filled_rectangle(x_subbox_button_option_initial, y_subbox_button_option_3_initial, x_subbox_button_option_final, y_subbox_button_option_3_final, al_map_rgb(161, 127, 53));

	int y_subbox_3_option_text = y_subbox_button_option_3_initial + (y_subbox_size_button_option / 4);
	al_draw_text(fichario->subtitulo22, al_map_rgb(255, 255, 255), meio_subbox_options, y_subbox_3_option_text, ALLEGRO_ALIGN_CENTER, "Classificar Familia");

	/* OPCAO 4 */
	int y_subbox_button_option_4_initial = y_subbox_button_option_3_final + espacemento_y_subbox_option_option;
	int y_subbox_button_option_4_final = y_subbox_button_option_4_initial + y_subbox_size_button_option;
	al_draw_filled_rectangle(x_subbox_button_option_initial, y_subbox_button_option_4_initial, x_subbox_button_option_final, y_subbox_button_option_4_final, al_map_rgb(161, 127, 53));

	int y_subbox_4_option_text = y_subbox_button_option_4_initial + (y_subbox_size_button_option / 4);
	al_draw_text(fichario->subtitulo22, al_map_rgb(255, 255, 255), meio_subbox_options, y_subbox_4_option_text, ALLEGRO_ALIGN_CENTER, "Classificar Familia");


	/* FINAL OPCOES */
}

void desenha_jogo(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario) {
	desenha_background(mapa);

	// layers
	for (int layer = 0; layer < WINDOW_SIZE_PIXEL_Y; layer++) {
		desenha_personagem(player, layer);
		desenha_npc(mapa, layer);
	}

	if (player->status == FICHARIO ) {
		desenha_fichario(player, fichario);
	}
}