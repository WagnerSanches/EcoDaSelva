#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_floresta_desmatada(struct al_mapa* mapa) {
	mapa->background = al_load_bitmap("assets/mapa/FlorestaDesmatada.png");

	mapa->next_mapa->pra_baixo = 4;
	mapa->next_mapa->pra_esquerda = 0;
	mapa->next_mapa->pra_direita = 2;

	// baixo
	for (int i = 8; i < 37; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}

	// esquerda
	for (int i = 0; i < 18; i++) {
		mapa->matriz[i][0] = 3;
	}

	// direita
	for (int i = 0; i < 18; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 1] = 3;
	}

}