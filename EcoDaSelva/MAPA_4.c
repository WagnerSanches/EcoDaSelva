#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_centro_direita(struct al_mapa* mapa) {

	mapa->background = al_load_bitmap("assets/mapa/direita.jpg");

	mapa->quantidade_npc = 0;

	mapa->matriz[11][0] = 3;
	mapa->matriz[12][0] = 3;
	mapa->matriz[13][0] = 3;

	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_001.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("assets/personagem/npc/Character_002.png");
	mapa->NPC_IMAGES[2] = al_load_bitmap("assets/personagem/npc/Character_003.png");
	mapa->NPC_IMAGES[3] = al_load_bitmap("assets/personagem/npc/Character_004.png");
	mapa->NPC_IMAGES[4] = al_load_bitmap("assets/personagem/npc/Character_005.png");

	mapa->quantidade_npc = 5;

	mapa->npc[0]->matriz_position_y = 17;
	mapa->npc[0]->matriz_position_x = 3;

	mapa->npc[1]->matriz_position_y = 1;
	mapa->npc[1]->matriz_position_x = 12;

	mapa->npc[2]->matriz_position_y = 5;
	mapa->npc[2]->matriz_position_x = 11;

	mapa->npc[3]->matriz_position_y = 3;
	mapa->npc[3]->matriz_position_x = 22;

	mapa->npc[4]->matriz_position_y = 14;
	mapa->npc[4]->matriz_position_x = 13;

	for (int i = 0; i < mapa->quantidade_npc; i++) {
		mapa->matriz[mapa->npc[i]->matriz_position_y][mapa->npc[i]->matriz_position_x] = 2;

		mapa->npc[i]->direcao = 1;

		mapa->npc[i]->image[0] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 3, 16, 16);
		mapa->npc[i]->image[1] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7, 16, 16);
		mapa->npc[i]->image[2] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24, 16, 16);
		mapa->npc[i]->image[3] = al_create_sub_bitmap(mapa->NPC_IMAGES[i], 4, 7 + 24 * 2, 16, 16);
	}

	mapa->npc[0]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	mapa->npc[1]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	mapa->npc[2]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	mapa->npc[3]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");
	mapa->npc[4]->foto = al_load_bitmap("assets/personagem/npc/foto/npc_um_resize.jpg");


	mapa->next_mapa->pra_esquerda = 0;

}