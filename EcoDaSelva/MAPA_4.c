#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_centro_direita(struct al_mapa* mapa) {
	for (int k = 0; k < WINDOW_SIZE_Y; k++) {
		for (int j = 0; j < WINDOW_SIZE_X; j++) {
			mapa->matriz[k][j] = 0;
		}
	}
	mapa->background = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\direita.png");

	mapa->quantidade_npc = 0;

	mapa->matriz[11][0] = 3;
	mapa->matriz[12][0] = 3;
	mapa->matriz[13][0] = 3;

	mapa->quantidade_npc = 5;

	mapa->npc[0].y = 19;
	mapa->npc[0].x = 3;

	mapa->npc[1].y = 1;
	mapa->npc[1].x = 12;

	mapa->npc[2].y = 5;
	mapa->npc[2].x = 11;

	mapa->npc[3].y = 3;
	mapa->npc[3].x = 22;

	mapa->npc[4].y = 14;
	mapa->npc[4].x = 13;

	for (int i = 0; i < mapa->quantidade_npc; i++)
		mapa->matriz[mapa->npc[i].y][mapa->npc[i].x] = 2;


	mapa->next_mapa.pra_esquerda = 0;
}