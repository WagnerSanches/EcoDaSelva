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
	desenhar_box(fichario);
	desenhar_informacoes(fichario, player);
	desenhar_opcoes(fichario);
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