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

		if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x] == 0 || mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x] == 3) {
			return false;
		}

		break;
	case PRA_BAIXO:

		if (player->matriz_position_y + 1 == WINDOW_SIZE_PIXEL_Y) {
			return true;
		}

		if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x] == 0 || mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x] == 3) {
			return false;
		}

		break;
	case PRA_ESQUERDA:

		if (player->matriz_position_x == 0 && player->sum_x_pixel == 0) {
			return true;
		}

		break;
	case PRA_DIREITA:

		// colisão com a parede
		if (player->matriz_position_x == WINDOW_SIZE_PIXEL_X - 1) {

			if (player->sum_x_pixel > 0)
				player->sum_x_pixel = 0;

			if(player->sum_x_pixel == 0)
				return true;

		}

	/*	

		if (player->map_position_x == (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) - PIXEL_SIZE) {
			return true;
		}

		if (player->map_position_x + player->velocidade > (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) - PIXEL_SIZE) {
			return true;
		}

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x + 1] == 0 || mapa->matriz[player->matriz_position_y][player->matriz_position_x + 1] == 3) {
			return false;
		}*/

		break;
	}

	return false;
}

bool proximo_mapa(struct Player* player, struct al_mapa* mapa) {
	switch (player->direcao) {
	case PRA_CIMA:

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x] == 3) {
			return true;
		}

		break;
	case PRA_BAIXO:

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x] == 3) {
			return true;
		}

		break;
	case PRA_ESQUERDA:

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x] == 3) {
			return true;
		}

		break;
	case PRA_DIREITA:

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x] == 3) {
			return true;
		}
		break;
	}

	return false;
}

bool npc(struct Player* player, struct al_mapa* mapa) {
	switch (player->direcao) {
	case PRA_CIMA:

		if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x] == 2) {
			return true;
		}

		break;
	case PRA_BAIXO:

		if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x] == 2) {
			return true;
		}

		break;
	case PRA_ESQUERDA:

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x - 1] == 2) {
			return true;
		}

		break;
	case PRA_DIREITA:

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x + 1] == 2) {
			return true;
		}
		break;
	}

	return false;
}