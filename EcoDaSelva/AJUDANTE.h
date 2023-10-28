#ifndef AJUDANTE_H
#define AJUDANTE_H
#include <allegro5/allegro5.h>

struct Ajudante {
	char* texto;
	ALLEGRO_BITMAP* image[2];
	bool ajudou;
};

#endif