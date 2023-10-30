#ifndef AL_MAPA_H
#define AL_MAPA_H

#include <config.h>
#include <allegro5/allegro.h>
#include <NPC.h>
#include <allegro5/allegro_font.h>

struct OBJETO_INTERACAO {
	int matriz_position_x;
	int matriz_position_y;
};

struct al_next_mapa {
	int pra_cima;
	int pra_baixo;
	int pra_esquerda;
	int pra_direita;
};

struct Item {
	char* nome;
	int matriz_position_x;
	int matriz_position_y;
	struct Ajudante* ajudante;
	bool item_missao;
	bool item_pegado;
	ALLEGRO_BITMAP* image;
};

struct al_mapa {
	bool criado;

	int matriz[WINDOW_SIZE_PIXEL_Y][WINDOW_SIZE_PIXEL_X];
	ALLEGRO_BITMAP* background;
	struct al_next_mapa* next_mapa;

	struct NPC* npc[MAX_NPC_PER_MAP];
	ALLEGRO_BITMAP* NPC_IMAGES[MAX_NPC_PER_MAP];
	ALLEGRO_FONT* dialogue16;

	struct Item* item[MAX_ITEM_PER_MAP];

	int quantidade_item;
	int quantidade_npc;

	struct OBJETO_INTERACAO* objeto_interacao;
}; 

void init_mapa(struct al_mapa* mapa);
void carregar_mapa(struct al_mapa* mapa, int next_mapa);
void validar_mapa(struct Player* player, struct al_mapa* mapa);
#endif // DIRECAO_H