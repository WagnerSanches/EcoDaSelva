#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
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
#include <DESENHA_FINAL.h>
#include <DIALOGO_CONFIG.h>


void desenha_background(struct al_mapa* mapa) {
	al_draw_bitmap(mapa->background, 0, 0, 0);
}

void desenha_npc(struct al_mapa* mapa, int layer) {
	for (int i = 0; i < mapa->quantidade_npc; i++) {
		if (mapa->npc[i]->matriz_position_y == layer) {

			if (mapa->npc[i]->npc_quest == true && mapa->npc[i]->quest_terminada == false) {
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

void desenha_fichario(struct Player* player, struct Fichario* fichario, struct DialogoConfig* dialogoConfig) {

	desenhar_box(fichario, player, dialogoConfig);

	/*
	desenhar_informacoes(fichario, player);
	desenhar_opcoes(fichario);
	*/

	if (fichario->ajudante->ajudou == false) {
		desenhar_ajudante(fichario->ajudante, dialogoConfig);
	}
}

void desenhar_jogo(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, struct Pausa* pausa, struct DialogoConfig* dialogoConfig) {
	desenha_background(mapa);

	// layers
	for (int layer = 0; layer < WINDOW_SIZE_PIXEL_Y; layer++) {
		desenha_personagem(player, layer);
		desenha_npc(mapa, layer);
		desenha_items(mapa, layer);
	}

	switch(player->status){
	case FICHARIO:
		desenha_fichario(player, fichario, dialogoConfig);
		break;
	case CONVERSANDO:
		desenhar_caixa_dialogo(player, mapa, dialogoConfig);
		break;
	case INTERAGINDO:
		desenhar_ajudante(mapa->item[player->indice_objeto_interacao]->ajudante, dialogoConfig);
		break;
	case PARADO:
		if (player->ajudante->ajudou == false) {
			desenhar_ajudante(player->ajudante, dialogoConfig);
		}
		break;
	case FINAL:
		desenhar_final(player);
		break;
	}

	if (pausa->pausado) {
		desenhar_pausa(pausa);
	}

}