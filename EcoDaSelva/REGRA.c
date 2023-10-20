#include <stdbool.h>
#include <AL_MAPA.h>
#include <direcao.h>
#include <player.h>
#include <SENTIDO.h>
#include <config.h>


bool colediu(struct Direcao* direcao, struct Player* player, struct al_mapa* mapa) {

	switch (direcao->sentido) {
	case PRA_CIMA:

		if (player->position_y - 1 < 0) {
			return true;
		}

		if (mapa->matriz[(int)player->position_y - 1][(int)player->position_x] == 0 || mapa->matriz[(int)player->position_y - 1][(int)player->position_x] == 3) {
			return false;
		}

		break;
	case PRA_BAIXO:

		if (player->position_y + 1 == WINDOW_SIZE_Y) {
			return true;
		}

		if (mapa->matriz[(int)player->position_y + 1][(int)player->position_x] == 0 || mapa->matriz[(int)player->position_y + 1][(int)player->position_x] == 3) {
			return false;
		}

		break;
	case PRA_ESQUERDA:

		if (player->position_x - 1 < 0) {
			return true;
		}

		if (mapa->matriz[(int)player->position_y][(int)player->position_x - 1] == 0 || mapa->matriz[(int)player->position_y][(int)player->position_x - 1] == 3) {
			return false;
		}

		break;
	case PRA_DIREITA:

		if (player->position_x + 1 == WINDOW_SIZE_X) {
			return true;
		}

		if (mapa->matriz[(int)player->position_y][(int)player->position_x + 1] == 0 || mapa->matriz[(int)player->position_y][(int)player->position_x + 1] == 3) {
			return false;
		}
		break;
	}

	return true;
}

bool proximo_mapa(struct Direcao* direcao, struct Player* player, struct al_mapa* mapa) {
	switch (direcao->sentido) {
	case PRA_CIMA:

		if (mapa->matriz[(int)player->position_y][(int)player->position_x] == 3) {
			return true;
		}

		break;
	case PRA_BAIXO:

		if (mapa->matriz[(int)player->position_y][(int)player->position_x] == 3) {
			return true;
		}

		break;
	case PRA_ESQUERDA:

		if (mapa->matriz[(int)player->position_y][(int)player->position_x] == 3) {
			return true;
		}

		break;
	case PRA_DIREITA:

		if (mapa->matriz[(int)player->position_y][(int)player->position_x] == 3) {
			return true;
		}
		break;
	}

	return false;
}
