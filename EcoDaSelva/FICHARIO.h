#ifndef FICHARIO_H
#define FICHARIO_H
#include <config.h>
#include <allegro5/allegro5.h>
#include <FICHARIO_STATUS.h>

struct Animal {
	char* nome;
};

struct Fichario {
	struct Animal animal[NUMBER_OF_CLASSES];

	struct ALLEGRO_FONT* titulo28;
	struct ALLEGRO_FONT* subtitulo22;
	struct ALLEGRO_FONT* descricao18;
	struct ALLEGRO_FONT* tag16;

	int classe_selecionada;

	enum Fichario_status status;
};

void init_fichario(struct Fichario* fichario);
void criar_fichario(struct Fichario* fichario);
void destruir_fichario(struct Fichario* fichario);

#endif