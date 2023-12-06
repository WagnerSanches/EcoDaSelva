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

	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_004.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("assets/personagem/npc/Character_005.png");

	mapa->quantidade_npc = 2;

	//NPCS (sem quests)

	mapa->npc[0]->foto = al_load_bitmap("assets/personagem/npc/foto/indio3.jpg");
	strcpy(mapa->npc[0]->nome, "Japira");
	strcpy(mapa->npc[0]->nome_item_quest, "None");
	mapa->npc[0]->npc_quest = false;
	strcpy(mapa->npc[0]->tag, "Nativo");
	strcpy(mapa->npc[0]->dialogo[0]->texto, "Ayahuasca e uma ponte entre o terreno e o espiritual. Nas cerimonias, o xamam nos guia em uma jornada dos buscadores, explorando as profundezas da nossa vasta consciencia.");
	mapa->npc[0]->dialogo_lido = 0;

	mapa->npc[0]->matriz_position_y = 4;
	mapa->npc[0]->matriz_position_x = 15;


	mapa->npc[1]->foto = al_load_bitmap("assets/personagem/npc/foto/indio18.jpg");
	strcpy(mapa->npc[1]->nome, "Itagiba");
	strcpy(mapa->npc[1]->nome_item_quest, "None");
	mapa->npc[1]->npc_quest = false;
	strcpy(mapa->npc[1]->tag, "Nativo");
	strcpy(mapa->npc[1]->dialogo[0]->texto, "me perdi na selva, sou da tribo, sabe? As arvores ficaram tudo igual, o som ta diferente. To rastreando o caminho mas ta dificil.");
	mapa->npc[1]->dialogo_lido = 0;

	mapa->npc[1]->matriz_position_y = 17;
	mapa->npc[1]->matriz_position_x = 21;



	for (int i = 0; i < mapa->quantidade_npc; i++) {
		mapa->matriz[mapa->npc[i]->matriz_position_y][mapa->npc[i]->matriz_position_x] = 2;

		mapa->npc[i]->direcao = 1;

		mapa->npc[i]->image[0] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 3, 16, 16);
		mapa->npc[i]->image[1] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7, 16, 16);
		mapa->npc[i]->image[2] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24, 16, 16);
		mapa->npc[i]->image[3] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 2, 16, 16);
	}


	mapa->next_mapa->pra_esquerda = 1;
	for (int i = 9; i < 15; i++) {
		mapa->matriz[i][0] = 3;
	}

	mapa->next_mapa->pra_baixo = 5;
	for (int i = 16; i < 24; i++) {
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

	for (int i = 5; i < 6; i++) {
		for (int j = 31; j < 33; j++)
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
	mapa->matriz[9][2] = 1;




	mapa->quantidade_item = 1;

	strcpy(mapa->item[0]->nome, "Latex");
	mapa->item[0]->matriz_position_x = 32;
	mapa->item[0]->matriz_position_y = 7;
	mapa->item[0]->image = al_load_bitmap("assets/objeto/barril/Barril.png");
	mapa->item[0]->item_missao = true;
	mapa->item[0]->ajudante->quantiade_imagem = 0;
	mapa->item[0]->ajudante->opcao = true;
	mapa->item[0]->ajudante->opcao_selecionada = 0;
	mapa->item[0]->ajudante->tipo_pergunta = PERGUNTA_ITEM;
	strcpy(mapa->item[0]->ajudante->texto, "Voce encontrou  Latex. O latex e uma seiva leitosa que e usada para porducao de borracha, e utilizada na frabricacao de luva e artigs medicos, bolas e brinquedos, produtos elasticos e muito mais. Ela normalmente e encontrada nas seringueiras que sao muito comuns na regiao do Amazonas.");

	for (int i = 0; i < mapa->quantidade_item; i++)
		mapa->matriz[mapa->item[i]->matriz_position_y - 1][mapa->item[i]->matriz_position_x - 1] = 5;

}