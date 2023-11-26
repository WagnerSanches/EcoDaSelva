#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_esquerda_floresta_desmatada(struct al_mapa* mapa) {

	mapa->background = al_load_bitmap("assets/mapa/EsquerdaFlorestaDesmatada.png");

	mapa->next_mapa->pra_direita = 1;
	for (int i = 0; i < 18; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 1] = 3;
	}

	mapa->next_mapa->pra_baixo = 3;
	for (int i = 0; i < WINDOW_SIZE_PIXEL_X - 5; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}
}