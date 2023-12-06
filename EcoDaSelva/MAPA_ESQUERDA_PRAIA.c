#include <AL_MAPA.h>
#include <stdlib.h>
#include <AJUDANTE.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

void carregar_mapa_esquerda_praia(struct al_mapa* mapa) {
	mapa->background = al_load_bitmap("assets/mapa/EsquerdaPraia.png");

	mapa->next_mapa->pra_cima = 3;
	for (int i = 20; i < 27; i++) {
		mapa->matriz[0][i] = 3;
	}

	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_004.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("assets/personagem/npc/Character_001.png");


	mapa->quantidade_npc = 2;

	// Quest Andiroba

	mapa->npc[0]->foto = al_load_bitmap("assets/personagem/npc/foto/indio2.jpg");
	strcpy(mapa->npc[0]->nome, "Aimbere");
	strcpy(mapa->npc[0]->nome_item_quest, "Andiroba");
	mapa->npc[0]->npc_quest = true;
	strcpy(mapa->npc[0]->tag, "Especie");
	strcpy(mapa->npc[0]->dialogo[0]->texto, "Oi explorador, nossa ainda bem que voce esta aqui. Minha filha se cortou com um galho e infelizmente acabou o nosso remedio.");
	strcpy(mapa->npc[0]->dialogo[1]->texto, "Sera que voce poderia pegar sementes da arvore Andiroba ? Elas sao laranjas e normalmente ficam norte a esquerda da vila. Rapido! Ela esta com dor.");
	strcpy(mapa->npc[0]->dialogo[2]->texto, "Enquanto estava na Colombia conversei com um povo indegena e eles falaram que cacava esse animal por la.");
	mapa->npc[0]->dialogo_lido = 0;

	mapa->npc[0]->matriz_position_y = 7;
	mapa->npc[0]->matriz_position_x = 10;


	//NPCS (sem quest)

	mapa->npc[1]->foto = al_load_bitmap("assets/personagem/npc/foto/Indio17.jpg");
	strcpy(mapa->npc[1]->nome, "Araxa");
	strcpy(mapa->npc[1]->nome_item_quest, "None");
	mapa->npc[1]->npc_quest = false;
	strcpy(mapa->npc[1]->tag, "Nativo");
	strcpy(mapa->npc[1]->dialogo[0]->texto, "os peixes tem cada historia! Sabia que os pirarucus, gigantes das aguas, guardam um segredo? Eles tem uma mania de subir a superficie pra respirar, como se fossem uns gigantes gentis dando um oi. Dizem que quem ve um pirarucu respirando leva um pedacinho da magia dos rios consigo");
	mapa->npc[1]->dialogo_lido = 0;

	mapa->npc[1]->matriz_position_y = 19;
	mapa->npc[1]->matriz_position_x = 30;



	for (int i = 0; i < mapa->quantidade_npc; i++) {
		mapa->matriz[mapa->npc[i]->matriz_position_y][mapa->npc[i]->matriz_position_x] = 2;

		mapa->npc[i]->direcao = 1;

		mapa->npc[i]->image[0] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 3, 16, 16);
		mapa->npc[i]->image[1] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7, 16, 16);
		mapa->npc[i]->image[2] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24, 16, 16);
		mapa->npc[i]->image[3] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 2, 16, 16);
	}

	// item (Buruti)

	mapa->quantidade_item = 1;

	strcpy(mapa->item[0]->nome, "Buriti");
	mapa->item[0]->matriz_position_x = 9;
	mapa->item[0]->matriz_position_y = 17;
	mapa->item[0]->image = al_load_bitmap("assets/objeto/fruta/Buriti.png");
	mapa->item[0]->item_missao = true;
	mapa->item[0]->ajudante->quantiade_imagem = 0;
	mapa->item[0]->ajudante->opcao = true;
	mapa->item[0]->ajudante->opcao_selecionada = 0;
	mapa->item[0]->ajudante->tipo_pergunta = PERGUNTA_ITEM;
	strcpy(mapa->item[0]->ajudante->texto, "Voce encontrou Buriti. Nativa da regiao amazonica, o buriti, tambem conhecido como o fruto da palmeira de buriti, alem de ser rica em vitamina A e vitamina C, ele e utilizado nos tratamento de problemas respiratorios e gastrointestinais.");

	for (int i = 0; i < mapa->quantidade_item; i++)
		mapa->matriz[mapa->item[i]->matriz_position_y][mapa->item[i]->matriz_position_x] = 5;

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