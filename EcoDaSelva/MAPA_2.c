#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_centro_baixo(struct al_mapa* mapa) {
	mapa->background = al_load_bitmap("assets/mapa/baixo.jpg");

	mapa->matriz[0][11] = 3;
	mapa->matriz[0][12] = 3;
	mapa->matriz[0][13] = 3;

	mapa->next_mapa.pra_cima = 0;
	mapa->criado = true;
}