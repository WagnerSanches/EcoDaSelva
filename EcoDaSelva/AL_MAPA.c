#include <allegro5/allegro5.h>
#include <AL_MAPA.h>
#include <MAPA.h>

void init_mapa(struct al_mapa* mapa) {
	mapa->criado = false;
	mapa->dialogue16 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 16, 0);

	carregar_mapa(mapa, 0);
}