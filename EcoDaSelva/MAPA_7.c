#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_cima_esquerda(struct al_mapa* mapa)
{
	mapa->background = al_load_bitmap("assets/mapa/topo_e.png");



#pragma endregion

	mapa->matriz[9][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[10][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[11][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[12][WINDOW_SIZE_PIXEL_X - 1] = 3;

	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][19] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][20] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][21] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][22] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][23] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][24] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][25] = 3;


	mapa->next_mapa->pra_direita = 1;
	mapa->next_mapa->pra_baixo = 6;

}