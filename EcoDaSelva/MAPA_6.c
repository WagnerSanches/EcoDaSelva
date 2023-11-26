#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_esquerda_vila(struct al_mapa* mapa)
{
	mapa->background = al_load_bitmap("assets/mapa/Meio_e.png");


#pragma endregion 

	mapa->matriz[11][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[12][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[13][WINDOW_SIZE_PIXEL_X - 1] = 3;

	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][18] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][19] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][20] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][21] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][22] = 3;

	mapa->matriz[0][19] = 3;
	mapa->matriz[0][20] = 3;
	mapa->matriz[0][21] = 3;
	mapa->matriz[0][22] = 3;
	mapa->matriz[0][23] = 3;
	mapa->matriz[0][24] = 3;
	mapa->matriz[0][25] = 3;

	mapa->next_mapa->pra_baixo = 3;
	mapa->next_mapa->pra_cima = 7;



}