#ifndef AJUDANTE_H
#define AJUDANTE_H
#include <allegro5/allegro5.h>

enum Pergunta  {
	PERGUNTA_INFORMACAO = 0,
	PERGUNTA_ITEM = 1
};

struct Ajudante {
	char* texto;
	int quantiade_imagem;
	ALLEGRO_BITMAP* image[2];
	bool ajudou;
	bool opcao;
	int opcao_selecionada;
	enum Pergunta tipo_pergunta;
};

#endif