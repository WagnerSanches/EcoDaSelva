#include <config.h>
#include <AL_MAPA.h>

void carregar_mapa_praia_esquerda(struct al_mapa* mapa) {

	mapa->background = al_load_bitmap("assets/mapa/praia_esquerda.png");

	mapa->matriz[0][20] = 3;
	mapa->matriz[0][21] = 3;
	mapa->matriz[0][22] = 3;
	mapa->matriz[0][23] = 3;
	mapa->matriz[0][24] = 3;
	mapa->matriz[0][25] = 3;
	mapa->matriz[0][26] = 3;

	mapa->next_mapa->pra_cima = 6;
}