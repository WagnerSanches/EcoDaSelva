#include <allegro5/allegro5.h>
#include <eventos.h>
#include <direcao.h>
#include <enum_estados.h>
#include <stdlib.h>
#include <player.h>

void botao_presionado(int keycode, struct Direcao* direcao, enum Estados* estados, struct Player* player) {
	*estados = ANDANDO;
	switch (keycode) {
	case ALLEGRO_KEY_UP:
		direcao->sentido = 1;
		break;
	case ALLEGRO_KEY_DOWN:
		direcao->sentido = 2;
		break;
	case ALLEGRO_KEY_LEFT:
		direcao->sentido = 3;
		direcao->x = player->position_x - 1;
		break;
	case ALLEGRO_KEY_RIGHT:
		direcao->sentido = 4;
		direcao->x = player->position_x + 1;
		break;
	}

}