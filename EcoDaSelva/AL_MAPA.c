#include <allegro5/allegro5.h>
#include <AL_MAPA.h>
#include <MAPA.h>

void init_mapa(struct al_mapa* mapa) {
	mapa->npc_interacao.matriz_position_x = 0;
	mapa->npc_interacao.matriz_position_y = 0;
	mapa->criado = false;

	carregar_mapa(mapa, 0);
}