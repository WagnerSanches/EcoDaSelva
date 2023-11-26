#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <AJUDANTE.h>

void carregar_mapa_direita_vila(struct al_mapa* mapa)
{
	mapa->background = al_load_bitmap("assets/mapa/DireitaVila.png");

	mapa->next_mapa->pra_esquerda = 4;
	for (int i = 7; i < WINDOW_SIZE_PIXEL_Y - 6; i++) {
		mapa->matriz[i][0] = 3;
	}

	mapa->next_mapa->pra_baixo = 8;
	for (int i = 6; i < WINDOW_SIZE_PIXEL_X - 5; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}

	mapa->next_mapa->pra_cima = 2;
	for (int i = 0; i < WINDOW_SIZE_PIXEL_X - 5; i++) {
		mapa->matriz[0][i] = 3;
	}
}