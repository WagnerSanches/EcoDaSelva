#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <AJUDANTE.h>

void carregar_mapa_direita_vila(struct al_mapa* mapa)
{
	mapa->background = al_load_bitmap("assets/mapa/DireitaVila.png");

#pragma region Colisoes

	//arvores

	for (int i = 1; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 6; i < 7; i++) {
		for (int j = 0; j < 2; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 5; i < 6; i++) {
		for (int j = 7; j < 9; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 6; i < 7; i++) {
		for (int j = 13; j < 15; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 8; i < 9; i++) {
		for (int j = 20; j < 22; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 13; i < 14; i++) {
		for (int j = 22; j < 24; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 14; i < 15; i++) {
		for (int j = 30; j < 32; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 19; i < 20; i++) {
		for (int j = 29; j < 31; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 20; i < 21; i++) {
		for (int j = 17; j < 19; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 19; i < 20; i++) {
		for (int j = 10; j < 12; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 16; i < 17; i++) {
		for (int j = 8; j < 10; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 16; i < 17; i++) {
		for (int j = 2; j < 4; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 21; i < 22; i++) {
		for (int j = 5; j < 7; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 22; i < 24; i++) {
		for (int j = 12; j < 14; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i < 3; i++) {
		for (int j = 11; j < 13; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 1; i < 2; i++) {
		for (int j = 0; j < 2; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i < 3; i++) {
		for (int j = 2; j < 3; j++)
			mapa->matriz[i][j] = 1;
	}

	//montanhas

	for (int i = 0; i < 24; i++) {
		for (int j = 38; j < 42; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 12; i++) {
		for (int j = 35; j < 38; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 31; j < 35; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 9; i < 12; i++) {
		for (int j = 33; j < 37; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 15; i < 24; i++) {
		for (int j = 35; j < 38; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 21; i < 24; i++) {
		for (int j = 31; j < 37; j++)
			mapa->matriz[i][j] = 1;
	}

	//moitas

	mapa->matriz[21][14] = 1;
	mapa->matriz[3][14] = 1;
	mapa->matriz[3][15] = 1;
	mapa->matriz[9][18] = 1;
	mapa->matriz[11][22] = 1;
	mapa->matriz[4][30] = 1;
	mapa->matriz[2][5] = 1;
	mapa->matriz[17][6] = 1;
	mapa->matriz[16][33] = 1;
	mapa->matriz[20][3] = 1;
	mapa->matriz[6][5] = 1;

	//pedra

	mapa->matriz[18][32] = 1;
	mapa->matriz[22][29] = 1;
	mapa->matriz[5][32] = 1;
	mapa->matriz[5][10] = 1;
	mapa->matriz[8][10] = 1;
	mapa->matriz[18][12] = 1;
	mapa->matriz[19][15] = 1;
	mapa->matriz[19][5] = 1;

	//placa

	mapa->matriz[22][28] = 1;
	mapa->matriz[1][25] = 1;

#pragma endregion

	mapa->next_mapa->pra_esquerda = 4;
	for (int i = 7; i < WINDOW_SIZE_PIXEL_Y - 6; i++) {
		mapa->matriz[i][0] = 3;
	}

	mapa->next_mapa->pra_baixo = 8;
	for (int i = 6; i < WINDOW_SIZE_PIXEL_X - 5; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}

	mapa->next_mapa->pra_cima = 2;
	for (int i = 0; i < WINDOW_SIZE_PIXEL_X - 5; i++) {
		mapa->matriz[0][i] = 3;
	}
}