#include <allegro5/allegro5.h>
#include <eventos.h>
#include <direcao.h>
#include <enum_estados.h>
#include <stdlib.h>
#include <player.h>

void botao_presionado(int keycode, struct Direcao* direcao, enum Estados* estados, struct Player* player) {
	
	switch (keycode) {
	case ALLEGRO_KEY_UP:
		direcao->sentido = 1;
		*estados = ANDANDO;
		break;
	case ALLEGRO_KEY_DOWN:
		direcao->sentido = 2;
		*estados = ANDANDO;
		break;
	case ALLEGRO_KEY_LEFT:
		direcao->sentido = 3;
		*estados = ANDANDO;
		break;
	case ALLEGRO_KEY_RIGHT:
		direcao->sentido = 4;
		*estados = ANDANDO;
		break;
	}

}