#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

void carregar_mapa_esquerda_vila(struct al_mapa* mapa) {
	mapa->background = al_load_bitmap("assets/mapa/EsquerdaVila.png");


#pragma region Colis�es

	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 5; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 21; i++) {
		for (int j = 5; j <= 5; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 4; i < 20; i++) {
		for (int j = 6; j <= 6; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 4; i < 17; i++) {
		for (int j = 7; j <= 10; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 4; i < 9; i++) {
		for (int j = 11; j <= 11; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 14; i < 17; i++) {
		for (int j = 11; j <= 11; j++)
			mapa->matriz[i][j] = 1;
	}

	//arvore

	for (int i = 0; i <= 0; i++) {
		for (int j = 9; j <= 13; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i <= 0; i++) {
		for (int j = 6; j <= 7; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i <= 3; i++) {
		for (int j = 12; j <= 13; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 6; i <= 6; i++) {
		for (int j = 17; j <= 18; j++)
			mapa->matriz[i][j] = 1;
	}


	for (int i = 9; i <= 9; i++) {
		for (int j = 15; j <= 16; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 4; i <= 4; i++) {
		for (int j = 32; j <= 33; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 16; i <= 16; i++) {
		for (int j = 34; j <= 35; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 21; i <= 21; i++) {
		for (int j = 36; j <= 37; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 18; i <= 20; i++) {
		for (int j = 15; j <= 19; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 14; i <= 16; i++) {
		for (int j = 13; j <= 17; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 19; i <= 21; i++) {
		for (int j = 10; j <= 14; j++)
			mapa->matriz[i][j] = 1;
	}

	//moita

	mapa->matriz[19][23] = 1;
	mapa->matriz[19][36] = 1;
	mapa->matriz[22][34] = 1;
	mapa->matriz[22][40] = 1;
	mapa->matriz[14][20] = 1;
	mapa->matriz[16][21] = 1;
	mapa->matriz[11][12] = 1;
	mapa->matriz[23][19] = 1;

	//pedra

	mapa->matriz[19][32] = 1;
	mapa->matriz[5][36] = 1;
	mapa->matriz[2][35] = 1;
	mapa->matriz[2][37] = 1;
	mapa->matriz[2][39] = 1;
	mapa->matriz[1][41] = 1;
	mapa->matriz[4][41] = 1;
	mapa->matriz[5][15] = 1;
	mapa->matriz[10][18] = 1;

	//placas
	mapa->matriz[1][26] = 1;
	mapa->matriz[8][39] = 1;
	mapa->matriz[22][28] = 1;

#pragma endregion

	mapa->next_mapa->pra_direita = 4;
	for (int i = 8; i < 14; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 1] = 3;
	}

	mapa->next_mapa->pra_baixo = 6;
	for (int i = 20; i < 28; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}

	mapa->next_mapa->pra_cima = 0;
	for (int i = 19; i < 27; i++) {
		mapa->matriz[0][i] = 3;
	}
}