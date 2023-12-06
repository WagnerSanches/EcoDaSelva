#include <allegro5/allegro5.h>

#ifndef PAUSA_H
#define PAUSA_H

#include <stdbool.h>

struct Pausa {
	int opcao;
	bool pausado;
	bool encerrar;
	bool reiniciar;
	ALLEGRO_BITMAP* font18;
};

#endif