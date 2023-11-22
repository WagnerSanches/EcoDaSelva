#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_esquerda_vila(struct al_mapa* mapa)
{
	mapa->background = al_load_bitmap("assets/mapa/esquerda.png");

	mapa->matriz[11][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[12][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[13][WINDOW_SIZE_PIXEL_X - 1] = 3;

	mapa->next_mapa->pra_baixo = 0;

#pragma endregion 

}