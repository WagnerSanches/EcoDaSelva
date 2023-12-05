#include <config.h>
#include <AL_MAPA.h>
#include <AJUDANTE.h>

void carregar_mapa_direita_praia(struct al_mapa* mapa) {

	mapa->background = al_load_bitmap("assets/mapa/DireitaPraia.png");


	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_001.png");	
	mapa->NPC_IMAGES[1] = al_load_bitmap("assets/personagem/npc/Character_003.png");

	mapa->quantidade_npc = 2;

	//NPCS (sem quests)

	mapa->npc[0]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	strcpy(mapa->npc[0]->nome, "Ibotira");
	strcpy(mapa->npc[0]->nome_item_quest, "None");
	mapa->npc[0]->npc_quest = false;
	strcpy(mapa->npc[0]->tag, "Nativo");
	strcpy(mapa->npc[0]->dialogo[0]->texto, "O Rio Amazonas, gigante das aguas, esconde misterios fascinantes. Nos indigenas dizemos que suas aguas carregam nao apenas nutrientes, mas tambem historias ancestrais");
	mapa->npc[0]->dialogo_lido = 0;

	mapa->npc[0]->matriz_position_y = 22;
	mapa->npc[0]->matriz_position_x = 35;


	mapa->npc[1]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	strcpy(mapa->npc[1]->nome, "Nina");
	strcpy(mapa->npc[1]->nome_item_quest, "None");
	mapa->npc[1]->npc_quest = false;
	strcpy(mapa->npc[1]->tag, "Nativo");
	strcpy(mapa->npc[1]->dialogo[0]->texto, "Na minha tribo, o Tacaca e um espetaculo de sabores. Originado da amazonia, essa sopa quente, feita com tucupi, goma de tapioca e camaroes, e um verdadeiro banquete.");
	mapa->npc[1]->dialogo_lido = 0;

	mapa->npc[1]->matriz_position_y = 16;
	mapa->npc[1]->matriz_position_x = 10;



	for (int i = 0; i < mapa->quantidade_npc; i++) {
		mapa->matriz[mapa->npc[i]->matriz_position_y][mapa->npc[i]->matriz_position_x] = 2;

		mapa->npc[i]->direcao = 1;

		mapa->npc[i]->image[0] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 3, 16, 16);
		mapa->npc[i]->image[1] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7, 16, 16);
		mapa->npc[i]->image[2] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24, 16, 16);
		mapa->npc[i]->image[3] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 2, 16, 16);
	}



	mapa->next_mapa->pra_cima = 5;
	for (int i = 20; i < 27; i++) {
		mapa->matriz[0][i] = 3;
	}

	mapa->quantidade_item = 1;

	strcpy(mapa->item[0]->nome, "Fruta");
	mapa->item[0]->matriz_position_x =	WINDOW_SIZE_PIXEL_X - 5;
	mapa->item[0]->matriz_position_y = WINDOW_SIZE_PIXEL_Y - 5;
	mapa->item[0]->image = al_load_bitmap("assets/objeto/fruta/amora.png");
	mapa->item[0]->item_missao = true;
	mapa->item[0]->ajudante->quantiade_imagem = 0;
	mapa->item[0]->ajudante->opcao = true;
	mapa->item[0]->ajudante->opcao_selecionada = 0;
	mapa->item[0]->ajudante->tipo_pergunta = PERGUNTA_ITEM;
	strcpy(mapa->item[0]->ajudante->texto, "Voce encontrou Acai. O acai e uma fruta nativa da regiao amazonica e uma das frutas mais usadas no reflorestamento de algumas areas do Amazonas. Geralmente crescem em cachos nas palmeiras de acai. Ela contem vitaminas essenciais, como vitamina C e vitamina E.");

	for (int i = 0; i < mapa->quantidade_item; i++)
		mapa->matriz[mapa->item[i]->matriz_position_y][mapa->item[i]->matriz_position_x] = 5;

	mapa->matriz[11][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[12][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[13][WINDOW_SIZE_PIXEL_X - 1] = 3;

	

#pragma region colisões 

	//arvores

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j <= 0; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 7; i < 15; i++) {
		for (int j = 0; j <= 0; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 5; i < 7; i++) {
		for (int j = 2; j <= 6; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 14; i < 16; i++) {
		for (int j = 2; j < 7; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 14; i < 15; i++) {
		for (int j = 18; j < 20; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 10; i <= WINDOW_SIZE_PIXEL_Y - 9; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 9; j <= WINDOW_SIZE_PIXEL_X - 8; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 7; i <= WINDOW_SIZE_PIXEL_Y - 6; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 15; j <= WINDOW_SIZE_PIXEL_X - 14; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 12; i <= WINDOW_SIZE_PIXEL_Y - 11; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 20; j <= WINDOW_SIZE_PIXEL_X - 19; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 7; i <= WINDOW_SIZE_PIXEL_Y - 6; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 20; j <= WINDOW_SIZE_PIXEL_X - 19; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 7; i <= WINDOW_SIZE_PIXEL_Y - 6; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 22; j <= WINDOW_SIZE_PIXEL_X - 21; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = WINDOW_SIZE_PIXEL_Y - 8; i <= WINDOW_SIZE_PIXEL_Y - 7; i++) {
		for (int j = WINDOW_SIZE_PIXEL_X - 17; j <= WINDOW_SIZE_PIXEL_X - 16; j++)
			mapa->matriz[i][j] = 1;
	}

	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 4][WINDOW_SIZE_PIXEL_X - 10] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 4][WINDOW_SIZE_PIXEL_X - 9] = 1;

	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 3][WINDOW_SIZE_PIXEL_X - 6] = 1;

	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 7][WINDOW_SIZE_PIXEL_X - 5] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 8][WINDOW_SIZE_PIXEL_X - 5] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 7][WINDOW_SIZE_PIXEL_X - 6] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 8][WINDOW_SIZE_PIXEL_X - 6] = 1;


	//relevo

	int max_colisao = WINDOW_SIZE_PIXEL_X - 10;
	for (int i = 0; i < 9; i++) {
		for (int j = max_colisao; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[i][j] = 1;
		}
	}

	max_colisao = WINDOW_SIZE_PIXEL_X - 8;
	for (int i = 9; i < 14; i++) {
		for (int j = max_colisao; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[i][j] = 1;
		}
	}

	max_colisao = WINDOW_SIZE_PIXEL_X - 4;
	for (int i = 14; i < WINDOW_SIZE_PIXEL_Y; i++) {
		for (int j = max_colisao; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[i][j] = 1;
		}
	}

	max_colisao = WINDOW_SIZE_PIXEL_X - 6;
	for (int i = 14; i < 16; i++) {
		for (int j = max_colisao; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[i][j] = 1;
		}
	}



	//pedras

	mapa->matriz[11][2] = 1;
	mapa->matriz[9][4] = 1;
	mapa->matriz[3][12] = 1;
	mapa->matriz[4][21] = 1;
	mapa->matriz[16][16] = 1;
	mapa->matriz[0][27] = 1;

	//moitas

	mapa->matriz[10][5] = 1;
	mapa->matriz[2][13] = 1;
	mapa->matriz[3][15] = 1;
	mapa->matriz[3][18] = 1;
	mapa->matriz[5][9] = 1;
	mapa->matriz[8][9] = 1;
	mapa->matriz[7][7] = 1;
	mapa->matriz[6][11] = 1;
	mapa->matriz[17][15] = 1;
	mapa->matriz[11][20] = 1;
	mapa->matriz[11][32] = 1;
	mapa->matriz[7][31] = 1;
	mapa->matriz[14][16] = 1;
	mapa->matriz[17][18] = 1;
	mapa->matriz[16][22] = 1;
	mapa->matriz[15][24] = 1;

	//mar 

	for (int i = 21; i < 24; i++) {
		for (int j = 0; j < WINDOW_SIZE_PIXEL_X - 10; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 18 ; i < 20; i++) {
		for (int j = 0; j < 4; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 20; i < 21; i++) {
		for (int j = 0; j < 7; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 19; i <= 21; i++) {
		for (int j = 24 ; j < WINDOW_SIZE_PIXEL_X - 10; j++)
			mapa->matriz[i][j] = 1;
	}

	for (int i = 23; i < 24; i++) {
		for (int j = 0; j < WINDOW_SIZE_PIXEL_X - 5; j++)
			mapa->matriz[i][j] = 1;
	}

#pragma endregion 

	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 1) / 2][0] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 2) / 2][0] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 3) / 2][0] = 3;


	mapa->next_mapa->pra_esquerda = 2;

}