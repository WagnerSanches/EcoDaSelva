#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <AJUDANTE.h>

void carregar_mapa_direita_vila(struct al_mapa* mapa)
{
	mapa->background = al_load_bitmap("assets/mapa/meio_d.png");

	mapa->matriz[11][0] = 3;
	mapa->matriz[12][0] = 3;
	mapa->matriz[13][0] = 3;

#pragma endregion 

	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 1) / 2][0] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 2) / 2][0] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 3) / 2][0] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 4) / 2][0] = 3;

	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 1)][20] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 1)][21] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 1)][22] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 1)][23] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 1)][24] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 1)][25] = 3;
	mapa->matriz[(WINDOW_SIZE_PIXEL_Y - 1)][26] = 3;

	mapa->next_mapa->pra_esquerda = 0;
	mapa->next_mapa->pra_baixo = 4;
}