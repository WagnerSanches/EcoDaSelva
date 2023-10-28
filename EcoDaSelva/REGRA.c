#include <stdbool.h>
#include <AL_MAPA.h>
#include <player.h>
#include <SENTIDO.h>
#include <config.h>
#include <OBJETO.h>


bool proximo_mapa(struct Player* player, struct al_mapa* mapa) {
	switch (player->direcao) {
	case PRA_CIMA:

		if (mapa->next_mapa->pra_cima >= 0) {
			if (mapa->matriz[player->matriz_position_y][player->matriz_position_x] == CAMINHO) {
				return true;
			}
		}

		break;
	case PRA_BAIXO:
		if (mapa->next_mapa->pra_baixo >= 0) {

			if (mapa->matriz[player->matriz_position_y][player->matriz_position_x] == CAMINHO) {
				return true;
			}
		}
		break;
	case PRA_ESQUERDA:

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x] == CAMINHO) {
			return true;
		}

		break;
	case PRA_DIREITA:

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x] == CAMINHO) {
			return true;
		}
		break;
	}

	return false;
}
bool interagiu(struct Player* player, struct al_mapa* mapa, enum Objeto objeto) {
	switch (player->direcao) {
	case PRA_CIMA:

		if (player->sum_x_pixel < -16) {

			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x - 1] == objeto) {
				mapa->objeto_interacao->matriz_position_y = player->matriz_position_y - 1;
				mapa->objeto_interacao->matriz_position_x = player->matriz_position_x - 1;

				return true;
			}
		}

		if (player->sum_x_pixel > 16) {

			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x + 1] == objeto) {
				mapa->objeto_interacao->matriz_position_y = player->matriz_position_y - 1;
				mapa->objeto_interacao->matriz_position_x = player->matriz_position_x + 1;

				return true;
			}
		}

		if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x] == objeto) {
			mapa->objeto_interacao->matriz_position_y = player->matriz_position_y - 1;
			mapa->objeto_interacao->matriz_position_x = player->matriz_position_x;

			return true;
		}

		break;
	case PRA_BAIXO:

		if (player->sum_x_pixel < -16) {

			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x - 1] == objeto) {
				mapa->objeto_interacao->matriz_position_y = player->matriz_position_y + 1;
				mapa->objeto_interacao->matriz_position_x = player->matriz_position_x - 1;

				return true;
			}
		}

		if (player->sum_x_pixel > 16) {

			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x + 1] == objeto) {
				mapa->objeto_interacao->matriz_position_y = player->matriz_position_y + 1;
				mapa->objeto_interacao->matriz_position_x = player->matriz_position_x + 1;

				return true;
			}
		}

		if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x] == objeto) {
			mapa->objeto_interacao->matriz_position_y = player->matriz_position_y + 1;
			mapa->objeto_interacao->matriz_position_x = player->matriz_position_x;
			return true;
		}

		break;
	case PRA_ESQUERDA:

		if (player->sum_y_pixel < -16) {

			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x - 1] == objeto) {
				mapa->objeto_interacao->matriz_position_y = player->matriz_position_y - 1;
				mapa->objeto_interacao->matriz_position_x = player->matriz_position_x - 1;

				return true;
			}
		}

		if (player->sum_y_pixel > 16) {

			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x - 1] == objeto) {
				mapa->objeto_interacao->matriz_position_y = player->matriz_position_y + 1;
				mapa->objeto_interacao->matriz_position_x = player->matriz_position_x - 1;

				return true;
			}
		}

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x - 1] == objeto) {
			mapa->objeto_interacao->matriz_position_y = player->matriz_position_y;
			mapa->objeto_interacao->matriz_position_x = player->matriz_position_x - 1;

			return true;
		}

		break;
	case PRA_DIREITA:

		if (player->sum_y_pixel < -16) {

			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x + 1] == objeto) {
				mapa->objeto_interacao->matriz_position_y = player->matriz_position_y - 1;
				mapa->objeto_interacao->matriz_position_x = player->matriz_position_x + 1;

				return true;
			}
		}

		if (player->sum_y_pixel > 16) {

			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x + 1] == objeto) {
				mapa->objeto_interacao->matriz_position_y = player->matriz_position_y + 1;
				mapa->objeto_interacao->matriz_position_x = player->matriz_position_x + 1;

				return true;
			}
		}

		if (mapa->matriz[player->matriz_position_y][player->matriz_position_x + 1] == objeto) {

			mapa->objeto_interacao->matriz_position_y = player->matriz_position_y;
			mapa->objeto_interacao->matriz_position_x = player->matriz_position_x + 1;

			return true;
		}

		break;
	}

	return false;
}


bool colediu(struct Player* player, struct al_mapa* mapa) {

	switch (player->direcao) {
	case PRA_CIMA:


		// colisao com o objetos na frente
		if (player->sum_x_pixel == 0 && player->sum_y_pixel <= 0) {
			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x] != CHAO &&
				mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x] != CAMINHO) {
				return true;
			}
		}

		// colisao com o objetos na frente ou em cima dele
		// X < 0 o player esta mais para a esquerda de um bloco
		// sum_y_pixel <= 0 se o player passou de um bloco
		if (player->sum_x_pixel < 0 && player->sum_y_pixel <= 0) {
			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x] != CHAO && 
				mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x] != CAMINHO) {

				return true;
			}

			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x - 1] != CHAO &&
				mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x - 1] != CAMINHO) {
				return true;
			}
		}

		// colisao com o objetos na frente ou em baixo dele
		if (player->sum_x_pixel > 0 && player->sum_y_pixel <= 0) {
			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x] != CHAO && 
				mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x] != CAMINHO) {
				return true;
			}

			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x + 1] != CHAO &&
				mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x + 1] != CAMINHO) {
				return true;
			}
		}

		// colisão com o inicio do mapa
		if (player->matriz_position_y == 0 && player->sum_y_pixel <= 0) {
			return true;
		}

		break;
	case PRA_BAIXO:

		// colisão com o final do mapa
		if (player->matriz_position_y == WINDOW_SIZE_PIXEL_Y - 1 && player->sum_y_pixel >= 0) {
			return true;
		}

		// colisao com o objetos na frente
		if (player->sum_x_pixel == 0 && player->sum_y_pixel >= 0) {
			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x] != CHAO && 
				mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x] != CAMINHO) {
				return true;
			}
		}

		// colisao com o objetos na frente ou em cima dele
		if (player->sum_x_pixel < 0 && player->sum_y_pixel >= 0) {
			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x] != CHAO &&
				mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x] != CAMINHO) {
				return true;
			}

			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x - 1] != CHAO &&
				mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x - 1] != CAMINHO) {
				return true;
			}
		}

		// colisao com o objetos na frente ou em baixo dele
		if (player->sum_x_pixel > 0 && player->sum_y_pixel >= 0) {
			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x] != CHAO &&
				mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x] != CAMINHO) {
				return true;
			}

			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x + 1] != CHAO &&
				mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x + 1] != CAMINHO) {
				return true;
			}
		}

		break;
	case PRA_ESQUERDA:

		// colisão com o inicio do mapa
		if (player->matriz_position_x == 0 && player->sum_x_pixel <= 0) {
			return true;
		}

		// colisao com o objetos na frente
		if (player->sum_y_pixel == 0 && player->sum_x_pixel <= 0) {
			if (mapa->matriz[player->matriz_position_y][player->matriz_position_x - 1] != CHAO &&
				mapa->matriz[player->matriz_position_y][player->matriz_position_x - 1] != CAMINHO) {
				return true;
			}
		}

		// colisao com o objetos na frente ou em cima dele
		if (player->sum_y_pixel < 0 && player->sum_x_pixel <= 0) {
			if (mapa->matriz[player->matriz_position_y][player->matriz_position_x - 1] != CHAO &&
				mapa->matriz[player->matriz_position_y][player->matriz_position_x - 1] != CAMINHO) {
				return true;
			}

			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x - 1] != CHAO &&
				mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x - 1] != CAMINHO) {
				return true;
			}
		}

		// colisao com o objetos na frente ou em baixo dele
		if (player->sum_y_pixel > 0 && player->sum_x_pixel <= 0) {
			if (mapa->matriz[player->matriz_position_y][player->matriz_position_x - 1] != CHAO &&
				mapa->matriz[player->matriz_position_y][player->matriz_position_x - 1] != CAMINHO) {
				return true;
			}

			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x - 1] != CHAO &&
				mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x - 1] != CAMINHO) {
				return true;
			}
		}

		break;
	case PRA_DIREITA:

		// colisão com o final do mapa
		if (player->matriz_position_x == WINDOW_SIZE_PIXEL_X - 1 && player->sum_x_pixel >= 0) {
			return true;
		}

		// colisao com o objetos na frente
		if (player->sum_y_pixel == 0 && player->sum_x_pixel >= 0) {
			if (mapa->matriz[player->matriz_position_y][player->matriz_position_x + 1] != CHAO && 
				mapa->matriz[player->matriz_position_y][player->matriz_position_x + 1] != CAMINHO) {
				return true;
			}
		}

		// colisao com o objetos na frente ou em cima dele
		if (player->sum_y_pixel < 0 && player->sum_x_pixel >= 0) {
			if (mapa->matriz[player->matriz_position_y][player->matriz_position_x + 1] != CHAO &&
				mapa->matriz[player->matriz_position_y][player->matriz_position_x + 1] != CAMINHO) {
				return true;
			}

			if (mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x + 1] != CHAO &&
				mapa->matriz[player->matriz_position_y - 1][player->matriz_position_x + 1] != CAMINHO) {
				return true;
			}
		}

		// colisao com o objetos na frente ou em baixo dele
		if (player->sum_y_pixel > 0 && player->sum_x_pixel >= 0) {
			if (mapa->matriz[player->matriz_position_y][player->matriz_position_x + 1] != CHAO &&
				mapa->matriz[player->matriz_position_y][player->matriz_position_x + 1] != CAMINHO) {
				return true;
			}

			if (mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x + 1] != CHAO && 
				mapa->matriz[player->matriz_position_y + 1][player->matriz_position_x + 1] != CAMINHO) {
				return true;
			}
		}

		break;
	}

	return false;
}