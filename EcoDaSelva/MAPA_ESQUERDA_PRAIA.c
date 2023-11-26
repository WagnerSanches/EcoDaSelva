#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

void carregar_mapa_esquerda_praia(struct al_mapa* mapa) {
	mapa->background = al_load_bitmap("assets/mapa/EsquerdaPraia.png");

	mapa->next_mapa->pra_cima = 3;
	for (int i = 7; i < WINDOW_SIZE_PIXEL_X - 5; i++) {
		mapa->matriz[0][i] = 3;
	}
}