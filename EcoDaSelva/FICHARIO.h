#ifndef FICHARIO_H
#define FICHARIO_H
#include <config.h>
#include <allegro5/allegro5.h>

struct Animal {
	char* nome;
};

struct Fichario {
	struct Animal animal[NUMBER_OF_ANIMALS];

	struct ALLEGRO_FONT* titulo28;
	struct ALLEGRO_FONT* subtitulo22;
	struct ALLEGRO_FONT* descricao18;

	int animal_selecionado;
};

void init_fichario(struct Fichario* fichario);
void criar_fichario(struct Fichario* fichario);
void destruir_fichario(struct Fichario* fichario);

#endif