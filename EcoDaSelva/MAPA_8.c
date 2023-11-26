#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_cima_direita(struct al_mapa* mapa)
{
	mapa->background = al_load_bitmap("assets/mapa/topo_d.png");

#pragma endregion

	mapa->matriz[9][0] = 3;
	mapa->matriz[10][0] = 3;
	mapa->matriz[11][0] = 3;
	mapa->matriz[12][0] = 3;
	mapa->matriz[13][0] = 3;
	
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][18] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][19] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][20] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][21] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][22] = 3;

	mapa->next_mapa->pra_esquerda = 1;
	mapa->next_mapa->pra_baixo = 5;

}