#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_centro_direita(struct al_mapa* mapa) {
	for (int k = 0; k < WINDOW_SIZE_PIXEL_Y; k++) {
		for (int j = 0; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[k][j] = 0;
		}
	}
	mapa->background = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\direita.png");

	mapa->quantidade_npc = 0;

	mapa->matriz[11][0] = 3;
	mapa->matriz[12][0] = 3;
	mapa->matriz[13][0] = 3;

	mapa->quantidade_npc = 5;

	mapa->npc[0].matriz_position_y = 19;
	mapa->npc[0].matriz_position_x = 3;

	mapa->npc[1].matriz_position_y = 1;
	mapa->npc[1].matriz_position_x = 12;

	mapa->npc[2].matriz_position_y = 5;
	mapa->npc[2].matriz_position_x = 11;

	mapa->npc[3].matriz_position_y = 3;
	mapa->npc[3].matriz_position_x = 22;

	mapa->npc[4].matriz_position_y = 14;
	mapa->npc[4].matriz_position_x = 13;

	for (int i = 0; i < mapa->quantidade_npc; i++)
		mapa->matriz[mapa->npc[i].matriz_position_y][mapa->npc[i].matriz_position_x] = 2;


	mapa->next_mapa.pra_esquerda = 0;
}