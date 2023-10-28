#ifndef AJUDANTE_H
#define AJUDANTE_H
#include <allegro5/allegro5.h>

enum Ensinar  {
	ENSINAR_INFORMACAO = 0,
	ENSINAR_ITEM = 2
};

struct Ajudante {
	char* texto;
	int quantiade_imagem;
	ALLEGRO_BITMAP* image[2];
	bool ajudou;
	bool opcao;
	int opcao_selecionada;
	enum Ensinar tipo_ensino;
};

#endif