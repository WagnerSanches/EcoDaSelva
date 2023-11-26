#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <AJUDANTE.h>

void carregar_mapa_vila(struct al_mapa* mapa) {
	mapa->background = al_load_bitmap("assets/mapa/Vila.png");

	mapa->next_mapa->pra_baixo = 7;
	mapa->next_mapa->pra_cima = 1;
	mapa->next_mapa->pra_direita = 5;
	mapa->next_mapa->pra_esquerda = 3;

	for (int i = 11; i < 32; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}

	for (int i = 8; i < 37; i++) {
		mapa->matriz[0][i] = 3;
	}

	for (int i = 7; i < WINDOW_SIZE_PIXEL_Y - 6; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 1] = 3;
	}

	for (int i = 7; i < WINDOW_SIZE_PIXEL_Y - 3; i++) {
		mapa->matriz[i][0] = 3;
	}

	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_001.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("assets/personagem/npc/Character_002.png");
	mapa->NPC_IMAGES[2] = al_load_bitmap("assets/personagem/npc/Character_003.png");

	mapa->quantidade_npc = 3;

	mapa->npc[0]->matriz_position_y = 17;
	mapa->npc[0]->matriz_position_x = 3;

	// Exemplo NPC de quest
	mapa->npc[1]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	strcpy(mapa->npc[1]->nome, "Douglas"); 
	strcpy(mapa->npc[1]->nome_item_quest, "Banana");
	mapa->npc[1]->npc_quest = true;
	strcpy(mapa->npc[1]->tag, "Familia");
	strcpy(mapa->npc[1]->dialogo[0]->texto, "Bem vindo");
	strcpy(mapa->npc[1]->dialogo[1]->texto, "Gosta de banana");
	strcpy(mapa->npc[1]->dialogo[2]->texto, "Hmmmmm");
	mapa->npc[1]->dialogo_lido = 0;

	mapa->npc[1]->matriz_position_y = 1; 
	mapa->npc[1]->matriz_position_x = 12;

	mapa->npc[2]->matriz_position_y = 5;
	mapa->npc[2]->matriz_position_x = 11;

	for (int i = 0; i < mapa->quantidade_npc; i++) {
		mapa->matriz[mapa->npc[i]->matriz_position_y][mapa->npc[i]->matriz_position_x] = 2;

		mapa->npc[i]->direcao = 1;

		mapa->npc[i]->image[0] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 3, 16, 16);
		mapa->npc[i]->image[1] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7, 16, 16);
		mapa->npc[i]->image[2] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24, 16, 16);
		mapa->npc[i]->image[3] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 2, 16, 16);
	}


	mapa->npc[0]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	mapa->npc[1]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	mapa->npc[2]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");

#pragma region Colisoes

	//pedras

	mapa->matriz[0][4] = 1;
	mapa->matriz[0][7] = 1;
	mapa->matriz[1][0] = 1;
	mapa->matriz[1][1] = 1;
	mapa->matriz[1][2] = 1;
	mapa->matriz[1][3] = 1;
	mapa->matriz[1][5] = 1;
	mapa->matriz[1][6] = 1;
	mapa->matriz[7][16] = 1;
	mapa->matriz[21][1] = 1;


	//cercas

	for (int i = 2; i <= 2; i++) {
		for (int j = 1; j < 7; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i < 7; i++) {
		for (int j = 6; j <= 6; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i < 7; i++) {
		for (int j = 8; j <= 8; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i <= 2; i++) {
		for (int j = 8; j < 15; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i < 7; i++) {
		for (int j = 14; j <= 14; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i < 7; i++) {
		for (int j = 1; j <= 1; j++)
			mapa->matriz[i][j] = 1;
	}

	mapa->matriz[6][2] = 1;
	mapa->matriz[6][5] = 1;

	mapa->matriz[5][3] = 1;
	mapa->matriz[5][4] = 1;


	mapa->matriz[6][13] = 1;
	mapa->matriz[6][12] = 1;
	mapa->matriz[6][10] = 1;
	mapa->matriz[6][9] = 1;

	for (int i = 15; i <= 21; i++) {
		for (int j = 1; j <= 1; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 15; i <= 15; i++) {
		for (int j = 1; j <= 5; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 15; i <= 19; i++) {
		for (int j = 5; j <= 5; j++)
			mapa->matriz[i][j] = 1;
	}

	mapa->matriz[19][4] = 1;
	mapa->matriz[19][2] = 1;
	mapa->matriz[18][4] = 1;
	mapa->matriz[18][2] = 1;

	for (int i = 15; i <= 19; i++) {
		for (int j = 8; j <= 8; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 15; i <= 15; i++) {
		for (int j = 8; j <= 14; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 15; i <= 19; i++) {
		for (int j = 14; j <= 14; j++)
			mapa->matriz[i][j] = 1;
	}

	mapa->matriz[19][13] = 1;
	mapa->matriz[19][12] = 1;
	mapa->matriz[18][11] = 1;
	mapa->matriz[19][10] = 1;
	mapa->matriz[19][9] = 1;

	for (int i = 3; i <= 3; i++) {
		for (int j = 26; j <= 35; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 3; i <= 7; i++) {
		for (int j = 35; j <= 35; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 3; i <= 7; i++) {
		for (int j = 27; j <= 27; j++)
			mapa->matriz[i][j] = 1;
	}

	mapa->matriz[6][30] = 1;
	mapa->matriz[6][31] = 1;
	mapa->matriz[6][32] = 1;
	mapa->matriz[7][33] = 1;
	mapa->matriz[7][34] = 1;
	mapa->matriz[7][29] = 1;
	mapa->matriz[7][28] = 1;

	for (int i = WINDOW_SIZE_PIXEL_Y - 4; i <= WINDOW_SIZE_PIXEL_Y - 4; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 19; j <= WINDOW_SIZE_PIXEL_X - 14; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 4; i <= WINDOW_SIZE_PIXEL_Y - 4; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 7; j <= WINDOW_SIZE_PIXEL_X - 3; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 9; i <= WINDOW_SIZE_PIXEL_Y - 4; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 19; j <= WINDOW_SIZE_PIXEL_X - 19; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 9; i <= WINDOW_SIZE_PIXEL_Y - 9; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 19; j <= WINDOW_SIZE_PIXEL_X - 3; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 9; i <= WINDOW_SIZE_PIXEL_Y - 4; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 3; j <= WINDOW_SIZE_PIXEL_X - 3; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 8; i <= WINDOW_SIZE_PIXEL_Y - 6; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 12; j <= WINDOW_SIZE_PIXEL_X - 8; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 8; i <= WINDOW_SIZE_PIXEL_Y - 6; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 18; j <= WINDOW_SIZE_PIXEL_X - 14; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 8; i <= WINDOW_SIZE_PIXEL_Y - 6; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 6; j <= WINDOW_SIZE_PIXEL_X - 3; j++)
			mapa->matriz[i][j] = 1;
	}

	//Arvores

	for (int i = 23; i <= 23; i++) {
		for (int j = 0; j <= 11; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 8; i <= WINDOW_SIZE_PIXEL_Y - 7; i++) {
		for (int j = 15; j <= 16; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 7; i <= 8; i++) {
		for (int j = 18; j <= 19; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 3; i <= 4; i++) {
		for (int j = 16; j <= 17; j++)
			mapa->matriz[i][j] = 1;
	}


	for (int i = 2; i <= 3; i++) {
		for (int j = 25; j <= 26; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 1; i <= 2; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 5; j <= WINDOW_SIZE_PIXEL_X - 2; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 4; i <= 5; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 2; j <= WINDOW_SIZE_PIXEL_X; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 6; i <= 6; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 6; j <= WINDOW_SIZE_PIXEL_X - 5; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 13; i <= 14; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 5; j <= WINDOW_SIZE_PIXEL_X - 4; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 6; i <= WINDOW_SIZE_PIXEL_Y - 5; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 2; j <= WINDOW_SIZE_PIXEL_X - 1; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 1; i <= WINDOW_SIZE_PIXEL_Y - 1; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 12; j <= WINDOW_SIZE_PIXEL_X; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 13; i <= 14; i++) {
		for (int j = 4; j <= 5; j++)
			mapa->matriz[i][j] = 1;
	}

	//Moitas

	mapa->matriz[22][0] = 1;
	mapa->matriz[0][WINDOW_SIZE_PIXEL_X - 8] = 1;
	mapa->matriz[1][WINDOW_SIZE_PIXEL_X - 10] = 1;
	mapa->matriz[1][WINDOW_SIZE_PIXEL_X - 7] = 1;
	mapa->matriz[0][WINDOW_SIZE_PIXEL_X - 1] = 1;
	mapa->matriz[3][WINDOW_SIZE_PIXEL_X - 4] = 1;
	mapa->matriz[1][WINDOW_SIZE_PIXEL_X - 1] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 3][WINDOW_SIZE_PIXEL_X - 1] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 2][WINDOW_SIZE_PIXEL_X - 1] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 2][WINDOW_SIZE_PIXEL_X - 2] = 1;

	//placa

	mapa->matriz[0][23] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][23] = 1;
	mapa->matriz[8][0] = 1;
	mapa->matriz[8][WINDOW_SIZE_PIXEL_X - 1] = 1;

	//Estatua

	mapa->matriz[WINDOW_SIZE_PIXEL_Y / 2][23] = 1;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y / 2) - 1][23] = 1;
}