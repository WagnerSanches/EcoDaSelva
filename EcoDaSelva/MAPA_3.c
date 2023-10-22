#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_centro_esquerda(struct al_mapa* mapa) {
	for (int k = 0; k < WINDOW_SIZE_PIXEL_Y; k++) {
		for (int j = 0; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[k][j] = 0;
		}
	}
	mapa->background = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\esquerda.png");

	mapa->quantidade_npc = 0;

	mapa->matriz[11][WINDOW_SIZE_PIXEL_X -1] = 3;
	mapa->matriz[12][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[13][WINDOW_SIZE_PIXEL_X - 1] = 3;

	for (int i = 0; i < mapa->quantidade_npc; i++)
		mapa->matriz[mapa->npc[i].matriz_position_y][mapa->npc[i].matriz_position_x] = 2;


	mapa->next_mapa.pra_direita = 0;
}