#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro_primitives.h>
#include <MAPA_CENTRO.h>
#include <MAPA_1.h>
#include <MAPA_2.h>
#include <MAPA_3.h>
#include <MAPA_4.h>

void desenha_mapa(struct al_mapa* mapa) {
	for (int i = 0; i < mapa->quantidade_npc; i++)
		al_draw_filled_rectangle(mapa->npc[i].x * PIXEL_SIZE, mapa->npc[i].y * PIXEL_SIZE, mapa->npc[i].x * PIXEL_SIZE + PIXEL_SIZE, mapa->npc[i].y * PIXEL_SIZE + PIXEL_SIZE, al_map_rgb(170, 50, 123), 0);

}

void carregar_mapa(struct al_mapa* mapa, int next_mapa) {

	switch (next_mapa) {
	case 0:
		carregar_mapa_centro(mapa);
		break;
	case 1:
		carregar_mapa_centro_cima(mapa);
		break;
	case 2:
		carregar_mapa_centro_baixo(mapa);
		break;
	case 3:
		carregar_mapa_centro_esquerda(mapa);
		break;
	case 4:
		carregar_mapa_centro_direita(mapa);
		break;
	}

}