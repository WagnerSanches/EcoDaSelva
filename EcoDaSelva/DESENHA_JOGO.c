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
#include <DESENHA_FICHARIO.h>
#include <DESENHA_FICHARIO_INFO.h>
#include <DESENHA_FICHARIO_OPCOES.h>
#include <DESENHA_DIALOGO_NPC.h>
#include <string.h>
#include <AJUDANTE.h>
#include <DESENHA_AJUDANTE.H>
#include <PAUSA.h>
#include <DESENHA_PAUSA.h>

void desenha_background(struct al_mapa* mapa) {
	al_draw_bitmap(mapa->background, 0, 0, 0);
}

void desenha_npc(struct al_mapa* mapa, int layer) {
	for (int i = 0; i < mapa->quantidade_npc; i++) {
		if (mapa->npc[i]->matriz_position_y == layer) {

			if(mapa->npc[i]->npc_quest) {
				ALLEGRO_BITMAP* b = al_load_bitmap("assets/npc/exclamation.png");
				if (b == NULL) return;
				al_draw_bitmap(b, mapa->npc[i]->matriz_position_x * PIXEL_SIZE, (mapa->npc[i]->matriz_position_y - 1) * PIXEL_SIZE, 0);
				al_destroy_bitmap(b);
			}

			al_draw_scaled_bitmap(mapa->npc[i]->image[mapa->npc[i]->direcao], 0, 0, 16, 16, mapa->npc[i]->matriz_position_x * PIXEL_SIZE, mapa->npc[i]->matriz_position_y * PIXEL_SIZE, 32, 32, 0);
			//al_draw_rectangle(mapa->npc[i]->matriz_position_x * PIXEL_SIZE, mapa->npc[i]->matriz_position_y * PIXEL_SIZE, mapa->npc[i]->matriz_position_x * PIXEL_SIZE + PIXEL_SIZE, mapa->npc[i]->matriz_position_y * PIXEL_SIZE + PIXEL_SIZE, al_map_rgb(186, 181, 93),0);
		}
	}
}

void desenha_personagem(struct Player* player, int layer) {
	if (player->matriz_position_y == layer) {
		al_draw_scaled_bitmap(player->image, 0, 0, 16, 16, player->map_position_x + player->sum_x_pixel, player->map_position_y + player->sum_y_pixel, 32, 32, 0);
	}
}

void desenha_items(struct al_mapa* mapa, int layer) {
	for (int i = 0; i < mapa->quantidade_item; i++) {
		if (mapa->item[i]->matriz_position_y == layer) {
			if (mapa->item[i]->item_pegado == false)
				al_draw_scaled_bitmap(mapa->item[i]->image, 0, 0, 64, 64, mapa->item[i]->matriz_position_x * PIXEL_SIZE - PIXEL_SIZE / 2, mapa->item[i]->matriz_position_y * PIXEL_SIZE - PIXEL_SIZE / 2 , 64, 64, 0);
		}
	}
}

void desenha_fichario(struct Player* player, struct Fichario* fichario) {
	
	int space_out = PIXEL_SIZE * 3;

	int x_fichario_i = space_out + PIXEL_SIZE;
	int y_fichario_i = space_out;
	int x_fichario_f = WINDOW_SIZE_PIXEL_X * PIXEL_SIZE - space_out - PIXEL_SIZE;
	int y_fichario_f = WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE - space_out;
	al_draw_filled_rectangle(x_fichario_i, y_fichario_i, x_fichario_f,	y_fichario_f, al_map_rgb(255, 233, 162));

	// opcoes
	int x_opcoes_i = x_fichario_i;
	int y_opcoes_i = y_fichario_i;
	int x_opcoes_f = x_opcoes_i + (PIXEL_SIZE * 10);
	int y_opcoes_f = y_fichario_f;
	al_draw_filled_rectangle(x_opcoes_i, y_opcoes_i, x_opcoes_f, y_opcoes_f, al_map_rgb(248, 215, 117));

	// opcao
	int opcoes_m = (x_opcoes_i + x_opcoes_f) / 2;
	int opcao_s_x = x_opcoes_f - x_opcoes_i - PIXEL_SIZE * 2;
	int opcao_s_y = PIXEL_SIZE + PIXEL_SIZE / 2 + PIXEL_SIZE / 4;
	int space_opcao = PIXEL_SIZE / 2;

	int x_opcao = opcoes_m - (opcao_s_x / 2);
	int x_opcao_f = x_opcao + opcao_s_x;
	int y_opcao = y_fichario_i + PIXEL_SIZE;
	
	char* textos[7] = {
		"Reino",
		"Filo",
		"Classe",
		"Ordem",
		"Familia",
		"Genero",
		"Especie"
	};

	int x_class_i = x_opcao + PIXEL_SIZE; 
	int x_class_f = x_opcao_f - PIXEL_SIZE;

	int font_size = 11;
	ALLEGRO_FONT* font = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size, 0);

	for (int i = 0; i < 7; i++) {
		int y_opcao_i = y_opcao + (i * (opcao_s_y + space_opcao));
		int y_opcao_f = y_opcao_i + opcao_s_y;
		al_draw_filled_rectangle(x_opcao, y_opcao_i, x_opcao_f, y_opcao_f, al_map_rgb(48, 96, 255));

		int y_class_i = y_opcao_f - PIXEL_SIZE / 2 - PIXEL_SIZE / 4;
		int y_class_f = y_class_i + PIXEL_SIZE / 2;
		al_draw_filled_rectangle(x_class_i, y_class_i, x_class_f, y_class_f, al_map_rgb(211, 223, 255));
		
		int y_tittle = y_opcao_i + PIXEL_SIZE / 4;
		al_draw_text(font, al_map_rgb(211, 223, 255), opcoes_m, y_tittle, ALLEGRO_ALIGN_CENTER, textos[i]);
	}

	//desenhar_box(fichario);
	//desenhar_informacoes(fichario, player);
	//desenhar_opcoes(fichario);

	if (fichario->ajudante->ajudou == false) {
		desenhar_ajudante(fichario->ajudante);
	}

	al_destroy_font(font);
}

void desenhar_jogo(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, struct Pausa* pausa) {
	desenha_background(mapa);

	// layers
	for (int layer = 0; layer < WINDOW_SIZE_PIXEL_Y; layer++) {
		desenha_personagem(player, layer);
		desenha_npc(mapa, layer);
		desenha_items(mapa, layer);
	}

	switch(player->status){
	case FICHARIO:
		desenha_fichario(player, fichario);
		break;
	case CONVERSANDO:
		desenhar_caixa_dialogo(player, mapa);
		break;
	case INTERAGINDO:
		desenhar_ajudante(mapa->item[player->indice_objeto_interacao]->ajudante);
		break;
	case PARADO:
		if (player->ajudante->ajudou == false) {
			desenhar_ajudante(player->ajudante);
		}
		break;
	}

	if (pausa->pausado) {
		desenhar_pausa(pausa);
	}

}