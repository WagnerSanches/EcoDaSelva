#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_centro_baixo(struct al_mapa* mapa) {
	for (int k = 0; k < WINDOW_SIZE_Y; k++) {
		for (int j = 0; j < WINDOW_SIZE_X; j++) {
			mapa->matriz[k][j] = 0;
		}
	}
	mapa->background = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\baixo.png");

	mapa->matriz[0][11] = 3;
	mapa->matriz[0][12] = 3;
	mapa->matriz[0][13] = 3;

	for (int i = 0; i < mapa->quantidade_npc; i++)
		mapa->matriz[mapa->npc[i].y][mapa->npc[i].x] = 2;

	mapa->next_mapa.pra_cima = 0;
}