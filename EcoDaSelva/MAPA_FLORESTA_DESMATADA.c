#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_floresta_desmatada(struct al_mapa* mapa) {
	mapa->background = al_load_bitmap("assets/mapa/FlorestaDesmatada.png");

	mapa->next_mapa->pra_baixo = 4;
	mapa->next_mapa->pra_esquerda = 0;
	mapa->next_mapa->pra_direita = 2;

	//npc

	mapa->quantidade_npc = 1;

	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_001.png");

	mapa->npc[0]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	strcpy(mapa->npc[0]->nome, "Apoena");
	strcpy(mapa->npc[0]->nome_item_quest, "Fruta");
	mapa->npc[0]->npc_quest = true;
	strcpy(mapa->npc[0]->tag, "Ordem");
	strcpy(mapa->npc[0]->dialogo[0]->texto, "Oi explorador, Eu acho que vc ja percebeu que essa area esta desmatada, mas estou fazendo um projeto de reflorenstamento desse local e preciso da sua ajuda. ");
	strcpy(mapa->npc[0]->dialogo[1]->texto, "Preciso de sementes de acai para plantar aqui. Elas sao roxas e ficam no sul a direita da vila, ao lado da palmeira.");
	strcpy(mapa->npc[0]->dialogo[2]->texto, "Me falaram que ja viram algo paracido aqui por perto. Ele era pequeno, tinha um corpo solido e estava na margem do lago.");
	mapa->npc[0]->dialogo_lido = 0;

	mapa->npc[0]->matriz_position_y = 9;
	mapa->npc[0]->matriz_position_x = 35;


	for (int i = 0; i < mapa->quantidade_npc; i++) {
		mapa->matriz[mapa->npc[i]->matriz_position_y][mapa->npc[i]->matriz_position_x] = 2;

		mapa->npc[i]->direcao = 1;

		mapa->npc[i]->image[0] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 3, 16, 16);
		mapa->npc[i]->image[1] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7, 16, 16);
		mapa->npc[i]->image[2] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24, 16, 16);
		mapa->npc[i]->image[3] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 2, 16, 16);
	}

#pragma region Colisoes

	// baixo
	for (int i = 16; i < 23; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}

	// esquerda
	for (int i = 8; i < 13; i++) {
		mapa->matriz[i][0] = 3;
	}

	// direita
	for (int i = 10; i < 15; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 1] = 3;
	}


	// árvores topo
	for (int j = 0; j < WINDOW_SIZE_PIXEL_X - 1; j++) {
		mapa->matriz[0][j] = 1;
	}

	// cercas  
	for (int i = 3; i < 8; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 4] = 1;
	}
	for (int j = WINDOW_SIZE_PIXEL_X - 9; j < WINDOW_SIZE_PIXEL_X - 4; j++) {
		mapa->matriz[7][j] = 1;
	}
	for (int j = WINDOW_SIZE_PIXEL_X - 14; j < WINDOW_SIZE_PIXEL_X - 9; j++) {
		mapa->matriz[7][j] = 1;
	}
	for (int i = 3; i < 8; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 14] = 1;
	}
	for (int j = WINDOW_SIZE_PIXEL_X - 14; j < WINDOW_SIZE_PIXEL_X - 4; j++) {
		mapa->matriz[3][j] = 1;
	}

	//placas
	mapa->matriz[8][WINDOW_SIZE_PIXEL_X - 3] = 1;
	mapa->matriz[6][2] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 2][23] = 1;

	//troncos baixo

	mapa->matriz[15][4] = 1;
	mapa->matriz[15][5] = 1;
	mapa->matriz[15][9] = 1;
	mapa->matriz[18][3] = 1;
	mapa->matriz[18][11] = 1;
	mapa->matriz[20][5] = 1;
	for (int i = 20; i < WINDOW_SIZE_PIXEL_Y; i++) {
		for (int j = 0; j < 2; j++) {
			mapa->matriz[i][j] = 1;
		}
	}
	mapa->matriz[23][2] = 1;
	mapa->matriz[18][26] = 1;
	for (int i = 18; i < 21; i++) {
		mapa->matriz[i][31] = 1;
	}
	mapa->matriz[17][36] = 1;
	mapa->matriz[18][40] = 1;
	mapa->matriz[19][38] = 1;

	for (int i = WINDOW_SIZE_PIXEL_Y - 2; i < WINDOW_SIZE_PIXEL_Y; i++) {
		for (int j = 39; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[i][j] = 1;
		}
	}
	//troncos cima

	for (int i = 3; i < 6; i++) {
		mapa->matriz[i][0] = 1;
	}
	for (int i = 1; i < 5; i++) {
		mapa->matriz[i][1] = 1;
	}
	for (int i = 4; i < 6; i++) {
		mapa->matriz[i][2] = 1;
	}
	mapa->matriz[4][7] = 1;
	mapa->matriz[6][13] = 1;
	mapa->matriz[3][15] = 1;
	mapa->matriz[7][16] = 1;
	mapa->matriz[4][17] = 1;
	for (int j = 19; j < 21; j++){
		mapa->matriz[8][j] = 1;
	}
	for (int j = 21; j < 23; j++) {
		mapa->matriz[5][j] = 1;
	}
	mapa->matriz[8][24] = 1;
	for (int i = 1; i < 5 ; i++){
		for (int j = WINDOW_SIZE_PIXEL_X - 3; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[i][j] = 1;
		}
	}
}

#pragma endregion