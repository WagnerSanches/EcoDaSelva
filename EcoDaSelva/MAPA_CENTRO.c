#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <AJUDANTE.h>

void carregar_mapa_centro(struct al_mapa *mapa) {

	mapa->quantidade_npc = 5;

	mapa->background = al_load_bitmap("assets/mapa/centro2.png");
	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_001.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("assets/personagem/npc/Character_002.png");
	mapa->NPC_IMAGES[2] = al_load_bitmap("assets/personagem/npc/Character_003.png");
	mapa->NPC_IMAGES[3] = al_load_bitmap("assets/personagem/npc/Character_004.png");
	mapa->NPC_IMAGES[4] = al_load_bitmap("assets/personagem/npc/Character_005.png");


	for (int i = 0; i < mapa->quantidade_npc; i++) {
		mapa->npc[i]->npc_quest = false;
		mapa->npc[i]->direcao = 1;
		mapa->npc[i]->dialogo_lido = 0;
		mapa->npc[i]->image[0] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 3, 16, 16);
		mapa->npc[i]->image[1] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7, 16, 16);
		mapa->npc[i]->image[2] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24, 16, 16);
		mapa->npc[i]->image[3] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 2, 16, 16);
	}

	mapa->npc[0]->matriz_position_y = 14;
	mapa->npc[0]->matriz_position_x = 22;

	mapa->npc[1]->matriz_position_y = 8;
	mapa->npc[1]->matriz_position_x = 17;

	mapa->npc[2]->matriz_position_y = 20;
	mapa->npc[2]->matriz_position_x = 6;

	mapa->npc[3]->matriz_position_y = 10;
	mapa->npc[3]->matriz_position_x = 10;
	mapa->npc[3]->npc_quest = true;

	mapa->npc[4]->matriz_position_y = 5;
	mapa->npc[4]->matriz_position_x = 11;
	mapa->npc[4]->npc_quest = true;

	for (int i = 0; i < mapa->quantidade_npc; i++) 
		mapa->matriz[mapa->npc[i]->matriz_position_y][mapa->npc[i]->matriz_position_x] = 2;
	
	strcpy(mapa->npc[0]->nome, "Caramuru");
	strcpy(mapa->npc[0]->dialogo[0]->texto, "Ola aventureiro! Seja bem-vindo a Oiapoque, \nvoce deve estar estranhando o clima quente, mas logo se acostuma. E claro, sou a (nome da assistente) e irei te ajudar durante sua pesquisa aqui na vila. Soube que esta em busca de informacoes sobre a fauna, entao, por que nao se enturmar e aprender um pouco com os moradores do vilarejo? Talvez eles tenham informacoes que possam te ajudar.");
	mapa->npc[0]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");

	strcpy(mapa->npc[1]->nome, "Tupa");
	strcpy(mapa->npc[1]->dialogo[0]->texto, "Gostaria de experimentar nossa comida tradicional? Oferecemos peixe grelhado e mandioca, e uma delicia!");
	mapa->npc[1]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");

	strcpy(mapa->npc[2]->nome, "Jatoba");
	strcpy(mapa->npc[2]->dialogo[0]->texto, "Aprendemos muitas tradicoes dos nossos ancestrais, como a arte de tecer cestas e o uso de plantas medicinais.");
	mapa->npc[2]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");

	strcpy(mapa->npc[3]->nome, "Arariboia");
	mapa->npc[3]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	strcpy(mapa->npc[3]->dialogo[0]->texto, "A musica e a danca desempenham um papel importante em nossas celebracoes. Gostaria de aprender alguns passos de danca conosco?");
	strcpy(mapa->npc[3]->dialogo[1]->texto, "Venha, permita-me mostrar os movimentos tradicionais de nossa danca, uma experiencia unica que voce jamais esquecera");
	strcpy(mapa->npc[3]->dialogo[2]->texto, "Nossas dancas contam historias ancestrais e celebram nossa conexao com a natureza. Voce encontrara beleza e significado em cada movimento.");

	strcpy(mapa->npc[4]->nome, "Pataxo");
	strcpy(mapa->npc[4]->nome_item_quest, "CARNAUBA");
	mapa->npc[4]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	strcpy(mapa->npc[4]->dialogo[0]->texto, "A musica e a danca desempenham um papel importante em nossas celebracoes. Gostaria de aprender alguns passos de danca conosco?");
	strcpy(mapa->npc[4]->dialogo[1]->texto, "Venha, permita-me mostrar os movimentos tradicionais de nossa danca, uma experiencia unica que voce jamais esquecera");
	strcpy(mapa->npc[4]->dialogo[2]->texto, "Nossas dancas contam historias ancestrais e celebram nossa conexao com a natureza. Voce encontrara beleza e significado em cada movimento.");


	mapa->quantidade_item = 1;

	strcpy(mapa->item[0]->nome, "CARNAUBA");
	mapa->item[0]->matriz_position_x = 12;
	mapa->item[0]->matriz_position_y = 12;
	mapa->item[0]->image = al_load_bitmap("assets/objeto/arvore/Palm_tree1_3.png");
	mapa->item[0]->item_missao = true;
	mapa->item[0]->ajudante->quantiade_imagem = 0;
	mapa->item[0]->ajudante->opcao = true;
	mapa->item[0]->ajudante->opcao_selecionada = 0;
	mapa->item[0]->ajudante->tipo_pergunta = PERGUNTA_ITEM;
	strcpy(mapa->item[0]->ajudante->texto, "Voce encontrou uma carnauba! A carnauba, ou Copernicia prunifera, e uma palmeira do Cerrado cujas folhas sao essenciais para a sobrevivencia de animais como o soldadinho-do-araripe, que constroi ninhos com elas. Alem disso, a cera de carnauba e usada em diversos produtos.");
	
	for(int i = 0; i < mapa->quantidade_item; i++) 
		mapa->matriz[mapa->item[i]->matriz_position_y][mapa->item[i]->matriz_position_x] = 5;

	mapa->matriz[11][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[12][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[13][WINDOW_SIZE_PIXEL_X - 1] = 3;

	for (int i = 12; i < WINDOW_SIZE_PIXEL_X - 6; i++) {
		mapa->matriz[0][i] = 3;
	}

#pragma region Colisoes

	int max_colisao = 12;
	for (int i = 0; i < 7; i++) {
		if (i == 4) max_colisao = 9;
		if (i == 5) max_colisao = 6;
		for (int j = 0; j < max_colisao; j++)
			mapa->matriz[i][j] = 1;
	}

	max_colisao = WINDOW_SIZE_PIXEL_X - 6;
	for (int i = 0; i < 3; i++) {
		if (i == 2) max_colisao = WINDOW_SIZE_PIXEL_X - 3;
		for (int j = max_colisao; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[i][j] = 1;
		}
	}

	// 4 arvrinha
	mapa->matriz[5][WINDOW_SIZE_PIXEL_X - 7] = 1;
	mapa->matriz[5][WINDOW_SIZE_PIXEL_X - 8] = 1;
	mapa->matriz[6][WINDOW_SIZE_PIXEL_X - 7] = 1;
	mapa->matriz[6][WINDOW_SIZE_PIXEL_X - 8] = 1;

	// pedra
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 4][WINDOW_SIZE_PIXEL_X - 3] = 1;

	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 3][3] = 1;


#pragma endregion

	mapa->matriz[11][0] = 3;
	mapa->matriz[12][0] = 3;
	mapa->matriz[13][0] = 3;

	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][11] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][12] = 3;
	mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][13] = 3;

	mapa->next_mapa->pra_cima = 1;
	mapa->next_mapa->pra_baixo = 2;
	mapa->next_mapa->pra_esquerda = 3;
	mapa->next_mapa->pra_direita = 4;

	


}

