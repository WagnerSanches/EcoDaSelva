#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

void carregar_mapa_esquerda_praia(struct al_mapa* mapa) {
	mapa->background = al_load_bitmap("assets/mapa/EsquerdaPraia.png");

	mapa->next_mapa->pra_cima = 3;
	for (int i = 7; i < WINDOW_SIZE_PIXEL_X - 5; i++) {
		mapa->matriz[0][i] = 3;
	}

#pragma region colision

	// mar

	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 5; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 3; i < 24; i++) {
		for (int j = 5; j <= 5; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 3; i < 10; i++) {
		for (int j = 6; j <= 6; j++)
			mapa->matriz[i][j] = 1;
	}
	
	for (int i = 14; i < 24; i++) {
		for (int j = 6; j <= 6; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 21; i < 24; i++) {
		for (int j = 6; j <= 42; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 20; i <= 20; i++) {
		for (int j = 14; j <= 26; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 20; i <= 20; i++) {
		for (int j = 30; j < 42; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 19; i <= 19; i++) {
		for (int j = 38; j < 42; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 19; i < 24; i++) {
		for (int j = 6; j <= 9; j++)
			mapa->matriz[i][j] = 1;
	}

	//arvores

	for (int i = 0; i < 6; i++) {
		for (int j = 41; j <= 41; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 8; i < 15; i++) {
		for (int j = 41; j <= 41; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 7; j <= 11; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 10; i < 12; i++) {
		for (int j = 8; j <= 12; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 12; i < 14; i++) {
		for (int j = 6; j <= 7; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 14; i < 16; i++) {
		for (int j = 9; j <= 10; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 16; i < 18; i++) {
		for (int j = 7; j <= 8; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 19; i < 21; i++) {
		for (int j = 10; j <= 11; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 16; i < 18; i++) {
		for (int j = 18; j <= 22; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 15; i < 17; i++) {
		for (int j = 34; j <= 38; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 17; i < 19; i++) {
		for (int j = 40; j <= 42; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i < 3; i++) {
		for (int j = 36; j <= 37; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i < 3; i++) {
		for (int j = 32; j <= 33; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 5; i < 6; i++) {
		for (int j = 36; j <= 37; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 5; i < 6; i++) {
		for (int j = 33; j <= 34; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 13; i < 15; i++) {
		for (int j = 23; j <= 27; j++)
			mapa->matriz[i][j] = 1;
	}

	//moitas

	mapa->matriz[2][16] = 1;
	mapa->matriz[2][30] = 1;
	mapa->matriz[13][33] = 1;
	mapa->matriz[13][38] = 1;
	mapa->matriz[10][15] = 1;
	mapa->matriz[19][15] = 1;
	mapa->matriz[18][27] = 1;

	//pedras

	mapa->matriz[0][30] = 1;
	mapa->matriz[10][37] = 1;
	mapa->matriz[9][19] = 1;
	mapa->matriz[17][24] = 1;
	mapa->matriz[18][34] = 1;
	mapa->matriz[0][15] = 1;

	//placa
	mapa->matriz[1][27] = 1;
}