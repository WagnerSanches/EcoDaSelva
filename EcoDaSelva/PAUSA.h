#ifndef PAUSA_H
#define PAUSA_H

#include <stdbool.h>

struct Pausa {
	int opcao;
	bool pausado;
	bool encerrar;
	bool reiniciar;
};

#endif