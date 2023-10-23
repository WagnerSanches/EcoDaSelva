#include <allegro5/allegro5.h>
#include <AL_MAPA.h>
#include <MAPA.h>

void init_mapa(struct al_mapa* mapa) {
	mapa->npc_interacao.matriz_position_x = 0;
	mapa->npc_interacao.matriz_position_y = 0;
	mapa->criado = false;

	for (int k = 0; k < WINDOW_SIZE_PIXEL_Y; k++) {
		for (int j = 0; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[k][j] = 0;
		}
	}

	carregar_mapa(mapa, 0);
}