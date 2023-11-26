#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_centro_cima(struct al_mapa* mapa) {
	mapa->background = al_load_bitmap("assets/mapa/topo.png");


#pragma endregion

	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][19] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][20] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][21] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][22] = 3;

	mapa->matriz[8][0] = 3;
	mapa->matriz[9][0] = 3;
	mapa->matriz[10][0] = 3;
	mapa->matriz[11][0] = 3;
	mapa->matriz[12][0] = 3;
	mapa->matriz[13][0] = 3;



	mapa->matriz[9][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[10][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[11][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[12][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[13][WINDOW_SIZE_PIXEL_X - 1] = 3;

	mapa->next_mapa->pra_baixo = 0;
	mapa->next_mapa->pra_esquerda = 7;
	mapa->next_mapa->pra_direita = 8;

}