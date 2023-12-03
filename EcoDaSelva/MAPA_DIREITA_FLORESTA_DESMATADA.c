#include <config.h>
#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <AJUDANTE.h>

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

	// montanha 
	for (int i = 0; i < 7; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 9] = 1;
	}
	for (int j = WINDOW_SIZE_PIXEL_X - 9; j > WINDOW_SIZE_PIXEL_X - 11; j--) {
		mapa->matriz[7][j] = 1;
	}
	for (int i = 7; i < 16; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 11] = 1;
	}
	for (int j = WINDOW_SIZE_PIXEL_X - 11 ; j < WINDOW_SIZE_PIXEL_X - 8; j++) {
		mapa->matriz[15][j] = 1;
	}
	for (int i = 15; i < 19; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 9] = 1;
	}
	for (int j = WINDOW_SIZE_PIXEL_X - 9; j > WINDOW_SIZE_PIXEL_X - 11; j--) {
		mapa->matriz[19][j] = 1;
	}
	for (int i = 19; i < WINDOW_SIZE_PIXEL_Y; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 11] = 1;
	}
	
	// cercas das casas
	for (int i = 0; i < 1; i++) {
		mapa->matriz[i][7] = 1;
	}
	for (int j = 5; j < 31; j++) {
		mapa->matriz[1][j] = 1;
	}
	mapa->matriz[1][WINDOW_SIZE_PIXEL_X - 10] = 1;
	
	//árvores
	for (int j = 0; j < 5; j++) {
		mapa->matriz[0][j] = 1;
	}
	for (int i = 5; i < 6; i++) {
		for (int j = 1; j < 3; j++)
			mapa->matriz[i][j ] = 1;
	}
	for (int i = 5; i < 6; i++) {
		for (int j = 10; j < 12; j++)
			mapa->matriz[i][j] = 1;
	}
	for (int i = 6; i < 7; i++) {
		for (int j = 16; j < 18; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 9; i < 10; i++) {
		for (int j = 24; j < 26; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 11; i < 12; i++) {
		for (int j = 28; j < 30; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 13; i < 14; i++) {
		for (int j = 25; j < 27; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 15; i < 16; i++) {
		for (int j = 27; j < 29; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 17; i < 18; i++) {
		for (int j = 25; j < 27; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 18; i < 19; i++) {
		for (int j = 29; j < 31; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 19; i < 20; i++) {
		for (int j = 27; j < 29; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 3; i < WINDOW_SIZE_PIXEL_Y - 2; i++) {
		for (int j = 5; j < 7; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 3; i < WINDOW_SIZE_PIXEL_Y - 2; i++) {
		for (int j = 9; j < 11; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 2; i < WINDOW_SIZE_PIXEL_Y - 1; i++) {
		for (int j = 28; j < 30; j++)
			mapa->matriz[i][j] = 1;
	}


	//moita
	mapa->matriz[4][WINDOW_SIZE_PIXEL_X - 10] = 1;
	mapa->matriz[4][WINDOW_SIZE_PIXEL_X - 11] = 1;
	mapa->matriz[5][WINDOW_SIZE_PIXEL_X - 12] = 1;
	mapa->matriz[6][22] = 1;
	mapa->matriz[6][13] = 1;
	mapa->matriz[6][4] = 1;
	mapa->matriz[9][19] = 1;
	mapa->matriz[9][12] = 1;
	mapa->matriz[13][22] = 1;
	mapa->matriz[15][29] = 1;
	mapa->matriz[16][23] = 1;
	mapa->matriz[17][2] = 1; 
	mapa->matriz[20][7] = 1;
	mapa->matriz[22][26] = 1;
	//arvores desmatada
	mapa->matriz[20][1] = 1;
	mapa->matriz[21][3] = 1;
	for (int i = 22; i < WINDOW_SIZE_PIXEL_Y; i++) {
			mapa->matriz[i][0] = 1;
	}
	
	//placa
	mapa->matriz[21][24] = 1;
	mapa->matriz[8][2] = 1;




	mapa->quantidade_item = 1;

	strcpy(mapa->item[0]->nome, "Latex");
	mapa->item[0]->matriz_position_x = 25;
	mapa->item[0]->matriz_position_y = 6;
	mapa->item[0]->image = al_load_bitmap("assets/objeto/arvore/seringueira.png");
	mapa->item[0]->item_missao = true;
	mapa->item[0]->ajudante->quantiade_imagem = 0;
	mapa->item[0]->ajudante->opcao = true;
	mapa->item[0]->ajudante->opcao_selecionada = 0;
	mapa->item[0]->ajudante->tipo_pergunta = PERGUNTA_ITEM;
	strcpy(mapa->item[0]->ajudante->texto, "Voce encontrou uma carnauba! A carnauba, ou Copernicia prunifera, e uma palmeira do Cerrado cujas folhas sao essenciais para a sobrevivencia de animais como o soldadinho-do-araripe, que constroi ninhos com elas. Alem disso, a cera de carnauba e usada em diversos produtos.");

	for (int i = 0; i < mapa->quantidade_item; i++)
		mapa->matriz[mapa->item[i]->matriz_position_y][mapa->item[i]->matriz_position_x] = 5;

}