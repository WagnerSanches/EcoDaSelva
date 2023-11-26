#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_praia(struct al_mapa* mapa) {
	mapa->background = al_load_bitmap("assets/mapa/centro2.png");

	mapa->matriz[0][17] = 3;
	mapa->matriz[0][18] = 3;
	mapa->matriz[0][19] = 3;
	mapa->matriz[0][20] = 3;
	mapa->matriz[0][21] = 3;
	mapa->matriz[0][22] = 3;

#pragma region Colisoes

	//arvores

	int max_colisao = 12;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < max_colisao; j++)
			mapa->matriz[i][j] = 1;
	}

	max_colisao = 12;
	for (int i = 0; i < 15; i++) {
		if (i == 0) max_colisao = 4;
		if (i == 0) max_colisao = 1;
		for (int j = 0; j < max_colisao; j++)
			mapa->matriz[i][j] = 1;
	}

	max_colisao = WINDOW_SIZE_PIXEL_X - 12;
	for (int i = 0; i < 6; i++) {
		for (int j = max_colisao; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[i][j] = 1;
		}
	}

	max_colisao = WINDOW_SIZE_PIXEL_X - 1;
	for (int i = 0; i < 15; i++) {
		if (i == 8) max_colisao = WINDOW_SIZE_PIXEL_X - 1;
		for (int j = max_colisao; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[i][j] = 1;
		}
	}

	// pedra

	for (int i = 12; i < 16; i++) {
		for (int j = 15; j <= 15; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 12; i < 16; i++) {
		for (int j = 25; j <= 25; j++)
			mapa->matriz[i][j] = 1;
	}

	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 4][WINDOW_SIZE_PIXEL_X - 3] = 1;
	mapa->matriz[7][WINDOW_SIZE_PIXEL_X - 2] = 1;

	mapa->matriz[16][WINDOW_SIZE_PIXEL_X - 2] = 1;
	mapa->matriz[16][WINDOW_SIZE_PIXEL_X - 1] = 1;
	mapa->matriz[17][WINDOW_SIZE_PIXEL_X - 2] = 1;

	mapa->matriz[16][WINDOW_SIZE_PIXEL_X - 15] = 1;
	mapa->matriz[13][WINDOW_SIZE_PIXEL_X - 11] = 1;

	mapa->matriz[6][1] = 1;
	mapa->matriz[16][0] = 1;
	mapa->matriz[6][14] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 3][3] = 1;

	//mar

	for (int i = 18; i < 24; i++) {
		for (int j = 7; j < WINDOW_SIZE_PIXEL_X; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 16; i < 18; i++) {
		for (int j = 15; j < 26; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 17; i < 21; i++) {
		for (int j = 7; j < 26; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 21; i < 24; i++) {
		for (int j = 0; j < WINDOW_SIZE_PIXEL_X; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 18; i < 22; i++) {
		for (int j = 0; j < 3; j++)
			mapa->matriz[i][j] = 1;
	}

	mapa->matriz[17][WINDOW_SIZE_PIXEL_X - 14] = 1;
	mapa->matriz[17][WINDOW_SIZE_PIXEL_X - 12] = 1;
	mapa->matriz[17][WINDOW_SIZE_PIXEL_X - 13] = 1;

	//madeiras

	mapa->matriz[0][23] = 1;
	mapa->matriz[19][5] = 1;


}