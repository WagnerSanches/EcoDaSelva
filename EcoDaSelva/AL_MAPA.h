#ifndef AL_MAPA_H
#define AL_MAPA_H

#include <config.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>

struct NPC {
	int x;
	int y;
};

struct al_next_mapa {
	int pra_cima;
	int pra_baixo;
	int pra_esquerda;
	int pra_direita;
};

struct al_mapa {
	int matriz[WINDOW_SIZE_Y][WINDOW_SIZE_X];
	ALLEGRO_BITMAP* background;
	int quantidade_npc;
	struct NPC npc[5];
	struct al_next_mapa next_mapa;
}; 

#endif // DIRECAO_H