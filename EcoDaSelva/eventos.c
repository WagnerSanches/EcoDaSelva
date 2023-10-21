#include <allegro5/allegro5.h>
#include <eventos.h>
#include <stdlib.h>
#include <player.h>
#include <SENTIDO.h>

void botao_presionado(int keycode, struct Player* player) {
	
	switch (keycode) {
	case ALLEGRO_KEY_UP:
		player->direcao = PRA_CIMA;
		player->image = player->animation[0][0];
		player->status = ANDANDO;
		break;
	case ALLEGRO_KEY_DOWN:
		player->direcao = PRA_BAIXO;
		player->image = player->animation[1][0];
		player->status = ANDANDO;
		break;
	case ALLEGRO_KEY_LEFT:
		player->direcao = PRA_ESQUERDA;
		player->image = player->animation[2][0];
		player->status = ANDANDO;
		break;
	case ALLEGRO_KEY_RIGHT:
		player->direcao = PRA_DIREITA;
		player->image = player->animation[3][0];
		player->status = ANDANDO;
		break;
	case ALLEGRO_KEY_SPACE:
		player->status = INTERAGINDO;
		break;
	}

}