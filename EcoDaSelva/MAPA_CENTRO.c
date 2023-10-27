#include <AL_MAPA.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

void carregar_mapa_centro(struct al_mapa *mapa) {
	srand(time(NULL));
	mapa->background = al_load_bitmap("assets/mapa/centro.png");
	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_001.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("assets/personagem/npc/Character_002.png");
	mapa->NPC_IMAGES[2] = al_load_bitmap("assets/personagem/npc/Character_003.png");

	mapa->quantidade_npc = 3;

	mapa->npc[0].matriz_position_y = 14;
	mapa->npc[0].matriz_position_x = 22;

	mapa->npc->nome = (char*)malloc(sizeof(char) * 30);
	if (mapa->npc[0].dialogo == NULL)
		return -1;

	mapa->npc[0].dialogo = malloc(sizeof(struct Dialogo));
	if (mapa->npc[0].dialogo == NULL)
		return -1;

	mapa->npc[0].dialogo->texto = (char*) malloc(sizeof(char) * 30);
	if (mapa->npc[0].dialogo->texto == NULL)
		return -1;

	mapa->dialogue16 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 16, 0);

	strcpy(mapa->npc[0].nome, "Caramuru");
	strcpy(mapa->npc[0].dialogo->texto, "Ola aventureiro!");
	mapa->npc[0].dialogo->linhas_texto = 1;
	mapa->npc[0].foto = al_load_bitmap("assets/npc/foto/mapa_centro/npc_um_resize.jpg");

	mapa->npc[1].matriz_position_y = 8;
	mapa->npc[1].matriz_position_x = 17;

	mapa->npc[2].matriz_position_y = 20;
	mapa->npc[2].matriz_position_x = 6;

	int i_npc = 0;
	for (int i = 0; i < mapa->quantidade_npc; i++) {
		mapa->matriz[mapa->npc[i].matriz_position_y][mapa->npc[i].matriz_position_x] = 2;

		mapa->npc[i].direcao = 2;
		
		mapa->npc[i].image[0] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 3, 16, 16);
		mapa->npc[i].image[1] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7, 16, 16);
		mapa->npc[i].image[2] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24, 16, 16);
		mapa->npc[i].image[3] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 2, 16, 16);

	}

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

	mapa->next_mapa.pra_cima = 1;
	mapa->next_mapa.pra_baixo = 2;
	mapa->next_mapa.pra_esquerda = 3;
	mapa->next_mapa.pra_direita = 4;


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

	mapa->criado = true;

}