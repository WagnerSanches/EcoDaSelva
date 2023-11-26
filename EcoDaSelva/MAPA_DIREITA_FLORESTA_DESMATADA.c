#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_direita_floresta_desmatada(struct al_mapa* mapa)
{
	mapa->background = al_load_bitmap("assets/mapa/DiretaFlorestaDesmatada.png");

	mapa->next_mapa->pra_esquerda = 1;
	for (int i = 0; i < 18; i++) {
		mapa->matriz[i][0] = 3;
	}

	mapa->next_mapa->pra_baixo = 5;
	for (int i = 0; i < WINDOW_SIZE_PIXEL_X - 5; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}

}