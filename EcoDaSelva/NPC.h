#ifndef NPC_H
#define NPC_H
#include <allegro5/allegro.h>
#include <DIALOGO.h>

struct NPC {
	char* nome;
	ALLEGRO_BITMAP* foto;
	
	struct Dialogo* dialogo[3];

	int matriz_position_x;
	int matriz_position_y;
	int direcao;
	ALLEGRO_BITMAP* image[4];

	bool npc_quest;
	int dialogo_lido;
	bool quest_terminada;
};

#endif