#ifndef FICHARIO_H
#define FICHARIO_H
#include <config.h>
#include <stdbool.h>
#include <allegro5/allegro5.h>
#include <POSICOES_BOX.h>

enum Selecao_groupo {
	NAO_SELECIONADO = 0,
};

enum Fichario_status {
	ABRIR_FICHARIO = 1,
	FECHAR_FICHARIO = 2,
	FICHARIO_ABERTO = 3,
	FICHARIO_FECHADO = 4
};

struct Group {
	char* titulo;
	char* descricao;
	//ALLEGRO_BITMAP* image[2];
};

struct Classe {
	char* titulo;
	char* descricao;

	struct Group* groupo[3];
};

struct Selecao {
	int classe;
	int grupo;

	bool grupo_selecionado;
};

struct Fichario {
	struct Classe* classe[4];
	struct Selecao* selecao;
	enum Fichario_status status;
	struct Posicoes_fichario_box* posicoes;
};


void criar_fichario(struct Fichario* fichario);
void destruir_fichario(struct Fichario* fichario);

#endif