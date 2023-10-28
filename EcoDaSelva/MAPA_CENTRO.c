#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

void carregar_mapa_centro(struct al_mapa *mapa) {

	mapa->quantidade_npc = 5;

	mapa->background = al_load_bitmap("assets/mapa/centro.png");
	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_001.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("assets/personagem/npc/Character_002.png");
	mapa->NPC_IMAGES[2] = al_load_bitmap("assets/personagem/npc/Character_003.png");
	mapa->NPC_IMAGES[3] = al_load_bitmap("assets/personagem/npc/Character_004.png");
	mapa->NPC_IMAGES[4] = al_load_bitmap("assets/personagem/npc/Character_005.png");

	for (int i = 0; i < mapa->quantidade_npc; i++) {
		mapa->npc[i]->npc_quest = false;
		mapa->npc[i]->direcao = 2;
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
	mapa->npc[4]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	strcpy(mapa->npc[4]->dialogo[0]->texto, "A musica e a danca desempenham um papel importante em nossas celebracoes. Gostaria de aprender alguns passos de danca conosco?");
	strcpy(mapa->npc[4]->dialogo[1]->texto, "Venha, permita-me mostrar os movimentos tradicionais de nossa danca, uma experiencia unica que voce jamais esquecera");
	strcpy(mapa->npc[4]->dialogo[2]->texto, "Nossas dancas contam historias ancestrais e celebram nossa conexao com a natureza. Voce encontrara beleza e significado em cada movimento.");


	mapa->matriz[11][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[12][WINDOW_SIZE_PIXEL_X - 1] = 3;
	mapa->matriz[13][WINDOW_SIZE_PIXEL_X - 1] = 3;

	mapa->matriz[0][11] = 3;
	mapa->matriz[0][12] = 3;
	mapa->matriz[0][13] = 3;

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

	/*mapa->quantidade_item = 1;

	mapa->items[0]->pixel_size_image = 64;
	mapa->items[0]->image = al_create_sub_bitmap(mapa->ITEM_IMAGES[0], 0, 0, 16, 16);

	mapa->items[0]->matriz_position_x = 10;
	mapa->items[0]->matriz_position_y = 10;
	mapa->items[0]->map_position_x = mapa->items[0]->matriz_position_x * PIXEL_SIZE;
	mapa->items[0]->map_position_y = (mapa->items[0]->matriz_position_y - 1) * PIXEL_SIZE;


	for (int i = 0; i < mapa->quantidade_item; i++) {
		mapa->matriz[mapa->items[i]->matriz_position_y][mapa->items[i]->matriz_position_x] = 1;
	}*/

}

