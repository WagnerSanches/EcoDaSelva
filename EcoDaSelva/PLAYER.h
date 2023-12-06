#ifndef PLAYER_H
#define PLAYER_H
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <FICHARIO.h>

enum Status {
	PARADO = 0,
	ANDANDO = 1,
	INTERAGINDO = 2,
	CORRENDO = 3,
	FICHARIO = 4,
	CONVERSANDO = 5,
	AJUDANTE = 6,
	MENU = 7,
	FINAL = 8 
};

struct Menu {
	bool ativo;
	bool encerrar;
	int opcao;
	ALLEGRO_BITMAP* background;

	int font_size;
	ALLEGRO_FONT* menu22;

	ALLEGRO_BITMAP* logo;
	ALLEGRO_BITMAP* information;

};

struct Final {
	ALLEGRO_BITMAP* background;// = al_load_bitmap("assets/jogo/FinalBackground.jpg");
	ALLEGRO_FONT* sub_tittle_animal; // = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 16, 0);
	ALLEGRO_BITMAP* animal;// = al_load_bitmap("assets/jogo/animal.jpg");
	ALLEGRO_BITMAP* resize;// = al_create_sub_bitmap(animal, PIXEL_SIZE * 6.5, PIXEL_SIZE * 5, img_animal_size, img_animal_size);
	ALLEGRO_FONT* tittle_animal;// = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size_tittle_animal, 0);
	ALLEGRO_FONT* font_categoria;// = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size_categoria, 0);
	ALLEGRO_FONT* font_points;// = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size_points, 0);
};

struct Resposta {
	char* grupo;
	bool selecionado;
};

struct Mission {
	int indice_npc_guest_aceita;
	bool quest_aceita;
	bool concluida;
	int quantidade_missoes_concluidas;
	char* missoes_concluidas[MAX_NPC_QUEST];
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

	struct Menu* menu;

	bool finalizou_jogo;
	int opcao_final_jogo;

	struct Final* finalItems;

};

void init_player(struct Player* player);


#endif