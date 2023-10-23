#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_centro_cima(struct al_mapa* mapa) {
	for (int k = 0; k < WINDOW_SIZE_PIXEL_Y; k++) {
		for (int j = 0; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[k][j] = 0;
		}
	}
	mapa->background = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\cima.png");

	mapa->quantidade_npc = 0;

	mapa->matriz[WINDOW_SIZE_PIXEL_Y -1][11] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][12] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][13] = 3;

	mapa->quantidade_npc = 3;

	mapa->npc[0].matriz_position_y = 19;
	mapa->npc[0].matriz_position_x = 3;

	mapa->npc[1].matriz_position_y = 1;
	mapa->npc[1].matriz_position_x = 12;

	mapa->npc[2].matriz_position_y = 5;
	mapa->npc[2].matriz_position_x = 11;


	for (int i = 0; i < mapa->quantidade_npc; i++)
		mapa->matriz[mapa->npc[i].matriz_position_y][mapa->npc[i].matriz_position_x] = 2;

	mapa->next_mapa.pra_baixo = 0;
}