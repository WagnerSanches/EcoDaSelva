#include <stdbool.h>
#include <AL_MAPA.h>
#include <player.h>
#include <SENTIDO.h>
#include <config.h>


bool colediu(struct Player* player, struct al_mapa* mapa) {

	switch (player->direcao) {
	case PRA_CIMA:

		if (player->matriz_position_y - 1 < 0) {
			return true;
		}

		if (mapa->matriz[(int)player->matriz_position_y - 1][(int)player->matriz_position_x] == 0 || mapa->matriz[(int)player->matriz_position_y - 1][(int)player->matriz_position_x] == 3) {
			return false;
		}

		break;
	case PRA_BAIXO:

		if (player->matriz_position_y + 1 == WINDOW_SIZE_Y) {
			return true;
		}

		if (mapa->matriz[(int)player->matriz_position_y + 1][(int)player->matriz_position_x] == 0 || mapa->matriz[(int)player->matriz_position_y + 1][(int)player->matriz_position_x] == 3) {
			return false;
		}

		break;
	case PRA_ESQUERDA:

		if (player->matriz_position_x - 1 < 0) {
			return true;
		}

		if (mapa->matriz[(int)player->matriz_position_y][(int)player->matriz_position_x - 1] == 0 || mapa->matriz[(int)player->matriz_position_y][(int)player->matriz_position_x - 1] == 3) {
			return false;
		}

		break;
	case PRA_DIREITA:

		if (player->matriz_position_x + 1 == WINDOW_SIZE_X) {
			return true;
		}

		if (mapa->matriz[(int)player->matriz_position_y][(int)player->matriz_position_x + 1] == 0 || mapa->matriz[(int)player->matriz_position_y][(int)player->matriz_position_x + 1] == 3) {
			return false;
		}
		break;
	}

	return true;
}

bool proximo_mapa(struct Player* player, struct al_mapa* mapa) {
	switch (player->direcao) {
	case PRA_CIMA:

		if (mapa->matriz[(int)player->matriz_position_y][(int)player->matriz_position_x] == 3) {
			return true;
		}

		break;
	case PRA_BAIXO:

		if (mapa->matriz[(int)player->matriz_position_y][(int)player->matriz_position_x] == 3) {
			return true;
		}

		break;
	case PRA_ESQUERDA:

		if (mapa->matriz[(int)player->matriz_position_y][(int)player->matriz_position_x] == 3) {
			return true;
		}

		break;
	case PRA_DIREITA:

		if (mapa->matriz[(int)player->matriz_position_y][(int)player->matriz_position_x] == 3) {
			return true;
		}
		break;
	}

	return false;
}

bool npc(struct Player* player, struct al_mapa* mapa) {
	switch (player->direcao) {
	case PRA_CIMA:

		if (mapa->matriz[(int)player->matriz_position_y - 1][(int)player->matriz_position_x] == 2) {
			return true;
		}

		break;
	case PRA_BAIXO:

		if (mapa->matriz[(int)player->matriz_position_y + 1][(int)player->matriz_position_x] == 2) {
			return true;
		}

		break;
	case PRA_ESQUERDA:

		if (mapa->matriz[(int)player->matriz_position_y][(int)player->matriz_position_x - 1] == 2) {
			return true;
		}

		break;
	case PRA_DIREITA:

		if (mapa->matriz[(int)player->matriz_position_y][(int)player->matriz_position_x + 1] == 2) {
			return true;
		}
		break;
	}

	return false;
}