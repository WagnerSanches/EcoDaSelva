#include <allegro5/allegro5.h>
#include <eventos.h>
#include <direcao.h>
#include <enum_estados.h>
#include <stdlib.h>
#include <player.h>
#include <SENTIDO.h>

void botao_presionado(int keycode, struct Direcao* direcao, enum Estados* estados, struct Player* player) {
	
	switch (keycode) {
	case ALLEGRO_KEY_UP:
		direcao->sentido = PRA_CIMA;
		*estados = ANDANDO;
		break;
	case ALLEGRO_KEY_DOWN:
		direcao->sentido = PRA_BAIXO;
		*estados = ANDANDO;
		break;
	case ALLEGRO_KEY_LEFT:
		direcao->sentido = PRA_ESQUERDA;
		*estados = ANDANDO;
		break;
	case ALLEGRO_KEY_RIGHT:
		direcao->sentido = PRA_DIREITA;
		*estados = ANDANDO;
		break;
	}

}