#include <PLAYER.h>
#include <SENTIDO.h>

void evento_andar_key_precionada(struct Player* player, int keycode) {
	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:

		if (player->pressing_key) player->pressing_multiple_key = true;

		player->direcao = PRA_CIMA;
		player->image = player->animation[0][0];
		player->status = ANDANDO;
		player->pressing_key = true;

		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:

		if (player->pressing_key) player->pressing_multiple_key = true;

		player->direcao = PRA_BAIXO;
		player->image = player->animation[1][0];
		player->status = ANDANDO;
		player->pressing_key = true;

		break;
	case ALLEGRO_KEY_LEFT:
	case ALLEGRO_KEY_A:

		if (player->pressing_key) player->pressing_multiple_key = true;

		player->direcao = PRA_ESQUERDA;
		player->image = player->animation[2][0];
		player->status = ANDANDO;
		player->pressing_key = true;

		break;
	case ALLEGRO_KEY_RIGHT:
	case ALLEGRO_KEY_D:

		if (player->pressing_key) player->pressing_multiple_key = true;

		player->direcao = PRA_DIREITA;
		player->image = player->animation[3][0];
		player->status = ANDANDO;
		player->pressing_key = true;

		break;
	case ALLEGRO_KEY_SPACE:
		player->status = INTERAGINDO;
		player->animation_next_image = 0;
		break;
	case ALLEGRO_KEY_LSHIFT:
		if (player->status == ANDANDO || player->status == PARADO) {
			player->velocidade = RUNNING;
			player->status = CORRENDO;
			player->pressing_multiple_key = true;
		}
		break;
	}
}

void evento_andar_key_levantada(struct Player* player, int keycode) {
	switch (keycode) {

	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_LEFT:
	case ALLEGRO_KEY_RIGHT:
	case ALLEGRO_KEY_W:
	case ALLEGRO_KEY_S:
	case ALLEGRO_KEY_A:
	case ALLEGRO_KEY_D:

		if (player->status == ANDANDO && player->pressing_multiple_key == false) {
			player->pressing_key = false;
		}
		else {
			player->pressing_multiple_key = false;
		}

		if (player->status == CORRENDO) {
			player->pressing_key = false;
			player->pressing_multiple_key = false;
		}

		break;
	case ALLEGRO_KEY_LSHIFT:
		player->status = ANDANDO;
		player->velocidade = WALKING;
		player->pressing_multiple_key = false;
		break;
	}

}