#include <config.h>
#include <AL_MAPA.h>
#include <AJUDANTE.h>

void carregar_mapa_esquerda_floresta_desmatada(struct al_mapa* mapa) {

	mapa->background = al_load_bitmap("assets/mapa/EsquerdaFlorestaDesmatada.png");

	//item (Andiroba)

	mapa->quantidade_item = 1;

	strcpy(mapa->item[0]->nome, "Andiroba");
	mapa->item[0]->matriz_position_x = 25;
	mapa->item[0]->matriz_position_y = 5;
	mapa->item[0]->image = al_load_bitmap("assets/objeto/fruta/andiroba.png");
	mapa->item[0]->item_missao = true;
	mapa->item[0]->ajudante->quantiade_imagem = 0;
	mapa->item[0]->ajudante->opcao = true;
	mapa->item[0]->ajudante->opcao_selecionada = 0;
	mapa->item[0]->ajudante->tipo_pergunta = PERGUNTA_ITEM;
	strcpy(mapa->item[0]->ajudante->texto, "Voce encontrou uma carnauba! A carnauba, ou Copernicia prunifera, e uma palmeira do Cerrado cujas folhas sao essenciais para a sobrevivencia de animais como o soldadinho-do-araripe, que constroi ninhos com elas. Alem disso, a cera de carnauba e usada em diversos produtos.");

	for (int i = 0; i < mapa->quantidade_item; i++)
		mapa->matriz[mapa->item[i]->matriz_position_y][mapa->item[i]->matriz_position_x] = 5;



#pragma region Colisões

	//arvores

	for (int i = 1; i < 2; i++) {
		for (int j = 13; j < 15; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 2; i < 3; i++) {
		for (int j = 11; j < 13; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 3; i < 4; i++) {
		for (int j = 12; j < 14; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 3; i < 4; i++) {
		for (int j = 18; j < 20; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 5; i < 6; i++) {
		for (int j = 22; j < 24; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 6; i < 7; i++) {
		for (int j = 11; j < 13; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 15; i < 16; i++) {
		for (int j = 17; j < 19; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 16; i < 17; i++) {
		for (int j = 14; j < 16; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 11; i < 12; i++) {
		for (int j = 13; j < 15; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 11; i < 12; i++) {
		for (int j = 9; j < 11; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 14; i < 15; i++) {
		for (int j = 11; j < 13; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 7; i < 8; i++) {
		for (int j = 15; j < 17; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 23; i <= 23; i++) {
		for (int j = 7; j < 11; j++)
			mapa->matriz[i][j] = 1;
	}

	//mar

	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 3; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 22; i++) {
		for (int j = 2; j <= 3; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 4; j <= 4; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 17; i++) {
		for (int j = 5; j <= 5; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 16; i++) {
		for (int j = 6; j <= 6; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 7; j <= 7; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 11; i++) {
		for (int j = 8; j <= 8; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 9; j <= 9; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 10; j <= 10; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 11; j <= 11; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 15; j < 42; j++)
			mapa->matriz[i][j] = 1;
	}

	//moita

	mapa->matriz[3][14] = 1;
	mapa->matriz[7][26] = 1;
	mapa->matriz[9][11] = 1;
	mapa->matriz[16][9] = 1;
	mapa->matriz[19][7] = 1;
	mapa->matriz[18][12] = 1;
	mapa->matriz[21][12] = 1;
	mapa->matriz[12][16] = 1;
	mapa->matriz[10][21] = 1;
	mapa->matriz[7][26] = 1;
	mapa->matriz[3][25] = 1;
	mapa->matriz[4][29] = 1;
	mapa->matriz[4][36] = 1;

	//placas

	mapa->matriz[22][26] = 1;
	mapa->matriz[7][39] = 1;

	//troncos

	mapa->matriz[7][41] = 1;
	mapa->matriz[6][41] = 1;
	mapa->matriz[2][40] = 1;
	mapa->matriz[3][40] = 1;
	mapa->matriz[17][40] = 1;
	mapa->matriz[18][40] = 1;
	mapa->matriz[22][38] = 1;
	mapa->matriz[23][38] = 1;


#pragma endregion

	mapa->next_mapa->pra_direita = 1;
	for (int i = 8; i < 12; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 1] = 3;
	}

	mapa->next_mapa->pra_baixo = 3;
	for (int i = 19; i < 27; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}
}