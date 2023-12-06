#include <config.h>
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

	for (int i = 18; i < 24; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}

	for (int i = 16; i < 23; i++) {
		mapa->matriz[0][i] = 3;
	}

	for (int i = 8; i < 14; i++) {
		mapa->matriz[i][WINDOW_SIZE_PIXEL_X - 1] = 3;
	}

	for (int i = 8; i < 14; i++) {
		mapa->matriz[i][0] = 3;
	}

	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_002.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("assets/personagem/npc/Character_003.png");
	mapa->NPC_IMAGES[2] = al_load_bitmap("assets/personagem/npc/Character_006.png");
	mapa->NPC_IMAGES[3] = al_load_bitmap("assets/personagem/npc/Character_005.png");
	mapa->NPC_IMAGES[4] = al_load_bitmap("assets/personagem/npc/Character_001.png");


	mapa->quantidade_npc = 5;

	// Quest latex
	mapa->npc[0]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	strcpy(mapa->npc[0]->nome, "Anajé"); 
	strcpy(mapa->npc[0]->nome_item_quest, "Latex");
	mapa->npc[0]->npc_quest = true;
	strcpy(mapa->npc[0]->tag, "Familia");
	strcpy(mapa->npc[0]->dialogo[0]->texto, "Ola aventureiro, voce veio conhecer nosso vilarejo no momento certo, nesse final de semana planejamos um jogo de Jikunahaty(Futebol de cabeca) entre nossa vila mas infelizmente nos nao temos mais latex para fazer a bola.");
	strcpy(mapa->npc[0]->dialogo[1]->texto, "sera que voce conseguiria um pouco de latex para a bola ? ha algumas seringueiras no norte a direita da vila, elas ja estao no barril.");
	strcpy(mapa->npc[0]->dialogo[2]->texto, "Quando eu era crianca minha mae me pediu para se afastar dele, pois ele era venenso.");
	mapa->npc[0]->dialogo_lido = 0;

	mapa->npc[0]->matriz_position_y = 8; 
	mapa->npc[0]->matriz_position_x = 12;

	// Quest arara

	mapa->npc[1]->foto = al_load_bitmap("assets/personagem/npc/foto/indio1.jpg");
	strcpy(mapa->npc[1]->nome, "Aimoré");
	strcpy(mapa->npc[1]->nome_item_quest, "Buriti");
	mapa->npc[1]->npc_quest = true; 
	strcpy(mapa->npc[1]->tag, "Genero");
	strcpy(mapa->npc[1]->dialogo[0]->texto, "Ola aventureiro, preciso muito da sua ajuda com a minha arara. Ela nao come sua fruta favorita (Buriti) a muito tempo, entao ela anda muito agitada.");
	strcpy(mapa->npc[1]->dialogo[1]->texto, "Sera que voce consegue encontrar alguns buritis ? Geralmente os buritis sao vermelehos e ficam no sul a esquerda da vila, perto das palmerias. Eu nao tive muita sorte, tomara que voce tenha.");
	strcpy(mapa->npc[1]->dialogo[2]->texto, "Meu pai conseguiu ve-lo de longe. Ele me disse que o animal era muito bonito e tinha uma coloracao viva, porem ele tinha medo de se aproximar.");
	mapa->npc[1]->dialogo_lido = 0;

	mapa->npc[1]->matriz_position_y = 12;
	mapa->npc[1]->matriz_position_x = 24;

	//Npcs (sem quest)

	mapa->npc[2]->foto = al_load_bitmap("assets/personagem/npc/foto/indio3.jpg");
	strcpy(mapa->npc[2]->nome, "Araxá");
	strcpy(mapa->npc[2]->nome_item_quest, "None");
	mapa->npc[2]->npc_quest = false;
	strcpy(mapa->npc[2]->tag, "");
	strcpy(mapa->npc[2]->dialogo[0]->texto, "Na aldeia dos Guajajara, os bichos - preguica sao tipo os reis da soneca.Eles penduram nas arvores numa boa, trocando segredos preguicosos e ensinando que as vezes, e bacana tirar um cochilo e curtir a brisa da floresta.");
	mapa->npc[2]->dialogo_lido = 0;

	mapa->npc[2]->matriz_position_y = 8;
	mapa->npc[2]->matriz_position_x = 30;


	mapa->npc[3]->foto = al_load_bitmap("assets/personagem/npc/foto/indio5.jpg");
	strcpy(mapa->npc[3]->nome, "Anhanguera");
	strcpy(mapa->npc[3]->nome_item_quest, "None");
	mapa->npc[3]->npc_quest = false;
	strcpy(mapa->npc[3]->tag, "");
	strcpy(mapa->npc[3]->dialogo[0]->texto, "Na vastidao da Amazonia, os botos-cor-de-rosa sao os encantadores do rio. Conta-se que, ao entardecer, esses cetaceos magicos se transformam em belos jovens para dancar nas margens, revelando o elo sagrado entre a agua e o misterioso reino das lendas fluviais.");
	mapa->npc[3]->dialogo_lido = 0;

	mapa->npc[3]->matriz_position_y = 8;
	mapa->npc[3]->matriz_position_x = 4;


	mapa->npc[4]->foto = al_load_bitmap("assets/personagem/npc/foto/Indio9.jpg");
	strcpy(mapa->npc[4]->nome, "Amary");
	strcpy(mapa->npc[4]->nome_item_quest, "None");
	mapa->npc[4]->npc_quest = false;
	strcpy(mapa->npc[4]->tag, "");
	strcpy(mapa->npc[4]->dialogo[0]->texto, "Nas terras dos Yawanawa, o murmur do vento revela segredos. Dizem que as borboletas, dancando entre as flores, sao espiritos ancestrais que nos visitam, trazendo bencaos aqueles que as observam com o coracao aberto.");
	mapa->npc[4]->dialogo_lido = 0;

	mapa->npc[4]->matriz_position_y = 20;
	mapa->npc[4]->matriz_position_x = 29;


	for (int i = 0; i < mapa->quantidade_npc; i++) {
		mapa->matriz[mapa->npc[i]->matriz_position_y][mapa->npc[i]->matriz_position_x] = 2;

		mapa->npc[i]->direcao = 1;

		mapa->npc[i]->image[0] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 3, 16, 16);
		mapa->npc[i]->image[1] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7, 16, 16);
		mapa->npc[i]->image[2] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24, 16, 16);
		mapa->npc[i]->image[3] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 2, 16, 16);
	}

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

	mapa->matriz[1][23] = 1;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 2][17] = 1;
	mapa->matriz[8][2] = 1;
	mapa->matriz[8][WINDOW_SIZE_PIXEL_X - 3] = 1;

	//Estatua

	mapa->matriz[WINDOW_SIZE_PIXEL_Y / 2][23] = 1;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y / 2) - 1][23] = 1;

	//teste
}