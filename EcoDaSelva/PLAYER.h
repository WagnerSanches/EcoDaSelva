#ifndef PLAYER_H
#define PLAYER_H
#include <allegro5/allegro5.h>
#include <FICHARIO.h>

enum Status {
	PARADO = 0,
	ANDANDO = 1,
	INTERAGINDO = 2,
	CORRENDO = 3,
	FICHARIO = 4,
	CONVERSANDO = 5,
	AJUDANTE = 6
};

struct Resposta {
	char* grupo;
	bool selecionado;
};

struct Mission {
	int indice_npc_guest_aceita;
	bool quest_aceita;
	bool concluida;
};

struct Player {
	int map_position_x;
	int map_position_y;

	int matriz_position_x;
	int matriz_position_y;

	ALLEGRO_BITMAP* image;
	ALLEGRO_BITMAP* animation[4][4];

	int animation_next_image;

	int direcao;

	int sum_x_pixel;
	int sum_y_pixel;

	bool pressing_key;
	bool pressing_multiple_key;

	enum Status status;

	int velocidade;

	int indice_objeto_interacao;

	struct Resposta* respostas[4];
	struct Mission* missao;

	struct Ajudante* ajudante;

	int quantidade_itens_pegados;
	char* itens_pegados[MAX_ITEM_QUEST];
};

void init_player(struct Player* player);


#endif