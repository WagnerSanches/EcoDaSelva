#ifndef PLAYER_H
#define PLAYER_H
#include <allegro5/allegro5.h>

enum Status {
	PARADO = 0,
	ANDANDO = 1,
	INTERAGINDO = 2
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

	enum Status status;
};

#endif