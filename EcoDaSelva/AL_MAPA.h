#ifndef AL_MAPA_H
#define AL_MAPA_H

#include <config.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>

struct NPC {
	int matriz_position_x;
	int matriz_position_y;
	int direcao;
	ALLEGRO_BITMAP* image[4];
};

struct NPC_INTERACAO {
	int matriz_position_x;
	int matriz_position_y;
};

struct al_next_mapa {
	int pra_cima;
	int pra_baixo;
	int pra_esquerda;
	int pra_direita;
};

struct Item {
	int map_position_x;
	int map_position_y;

	int matriz_position_x;
	int matriz_position_y;

	int pixel_size_image;

	ALLEGRO_BITMAP* image;
};

struct al_mapa {
	int matriz[WINDOW_SIZE_PIXEL_Y][WINDOW_SIZE_PIXEL_X];
	ALLEGRO_BITMAP* background;
	struct al_next_mapa next_mapa;

	struct NPC npc[5];
	ALLEGRO_BITMAP* NPC_IMAGES[7];

	struct Item* items[20];
	ALLEGRO_BITMAP* ITEM_IMAGES[10];

	int quantidade_item;
	int quantidade_npc;

	struct NPC_INTERACAO npc_interacao;

}; 

void init_mapa(struct al_mapa* mapa);

#endif // DIRECAO_H