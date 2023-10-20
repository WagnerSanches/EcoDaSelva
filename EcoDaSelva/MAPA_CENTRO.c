#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>

void carregar_mapa_centro(struct al_mapa *mapa) {

	for (int k = 0; k < WINDOW_SIZE_Y; k++) {
		for (int j = 0; j < WINDOW_SIZE_X; j++) {
			mapa->matriz[k][j] = 0;
		}
	}
	mapa->background = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\centro.png");

	mapa->quantidade_npc = 3;

	mapa->npc[0].y = 14;
	mapa->npc[0].x = 22;

	mapa->npc[1].y = 8;
	mapa->npc[1].x = 17;

	mapa->npc[2].y = 20;
	mapa->npc[2].x = 6;

	for(int i = 0; i < mapa->quantidade_npc; i ++)
		mapa->matriz[mapa->npc[i].y][mapa->npc[i].x] = 2;

	mapa->matriz[11][WINDOW_SIZE_X - 1] = 3;
	mapa->matriz[12][WINDOW_SIZE_X - 1] = 3;
	mapa->matriz[13][WINDOW_SIZE_X - 1] = 3;

	mapa->matriz[0][11] = 3;
	mapa->matriz[0][12] = 3;
	mapa->matriz[0][13] = 3;

	mapa->matriz[11][0] = 3;
	mapa->matriz[12][0] = 3;
	mapa->matriz[13][0] = 3;

	mapa->matriz[WINDOW_SIZE_Y - 1][11] = 3;
	mapa->matriz[WINDOW_SIZE_Y - 1][12] = 3;
	mapa->matriz[WINDOW_SIZE_Y - 1][13] = 3;

	mapa->next_mapa.pra_cima = 1;
	mapa->next_mapa.pra_baixo = 2;
	mapa->next_mapa.pra_esquerda = 3;
	mapa->next_mapa.pra_direita = 4;
}