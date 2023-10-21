#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <player.h>
#include <math.h>
#include <mapa_vila.h>
#include <config.h>
#include <AL_MAPA.h>
#include <stdbool.h>
#include <REGRA.h>
#include <MAPA.h>
#include <SENTIDO.h>

void andar_para_cima(struct Player* player, struct al_mapa* mapa) {

	if (colediu(player, mapa)) {
		if (proximo_mapa(player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_cima);
			
			player->matriz_position_y = WINDOW_SIZE_Y - 1;
			player->map_position_y = player->matriz_position_y * PIXEL_SIZE;

			return;
		}
		else {
			player->status = PARADO;
			return;
		}
	}

	if (player->sum_y_pixel == -PIXEL_SIZE) {
		
		player->matriz_position_y--;
		player->map_position_y = player->matriz_position_y * PIXEL_SIZE;
		player->image = player->animation[0][0];
		player->animation_next_image = 0;

		player->sum_y_pixel = 0;

		if (player->pressing_key == 0) player->status =
			PARADO;

		return;
	}
	else {

		player->sum_y_pixel -= SPEED;
	}

	if (player->sum_y_pixel % -8 == 0) {

		if (player->animation_next_image == 4) {
			player->animation_next_image = 0;
		}

		player->image = player->animation[0][player->animation_next_image];
		player->animation_next_image++;
	}
}

void andar_para_baixo(struct Player* player, struct al_mapa* mapa) {

	if (colediu( player, mapa)) {
		if (proximo_mapa(player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_baixo);
			player->matriz_position_y = 0;
			player->map_position_y = player->matriz_position_y * PIXEL_SIZE;
			return;
		}
		else {
			player->status = PARADO;
			return;
		}
	}

	if (player->sum_y_pixel == PIXEL_SIZE) {

		player->matriz_position_y++;
		player->map_position_y = player->matriz_position_y * PIXEL_SIZE;
		player->image = player->animation[1][0];
		player->animation_next_image = 0;

		player->sum_y_pixel = 0;

		if (player->pressing_key == 0)
			player->status = PARADO;

		return;
	}
	else {

		player->sum_y_pixel += SPEED;
	}

	if (player->sum_y_pixel % 8 == 0) {

		if (player->animation_next_image == 4) {
			player->animation_next_image = 0;
		}

		player->image = player->animation[1][player->animation_next_image];
		player->animation_next_image++;
	}
}

void andar_para_esquerda(struct Player* player, struct al_mapa* mapa) {

	if (colediu(player, mapa)) {
		if (proximo_mapa(player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_esquerda);

			player->matriz_position_x = WINDOW_SIZE_X - 1;
			player->map_position_x = player->matriz_position_x * PIXEL_SIZE;

			return;
		}
		else {
			player->status = PARADO;
			return;
		}
	}

	if (player->sum_x_pixel == -PIXEL_SIZE) {

		player->matriz_position_x--;
		player->map_position_x = player->matriz_position_x * PIXEL_SIZE;
		player->image = player->animation[2][0];
		player->animation_next_image = 0;

		player->sum_x_pixel = 0;

		if (player->pressing_key == 0) 
			player->status = PARADO;

		return;
	}
	else {
		player->sum_x_pixel -= SPEED;
	}

	if (player->sum_x_pixel % -8 == 0) {

		if (player->animation_next_image == 4) {
			player->animation_next_image = 0;
		}

		player->image = player->animation[2][player->animation_next_image];
		player->animation_next_image++;
	}
}	

void andar_para_direita(struct Player* player, struct al_mapa* mapa) {
	
	if (colediu(player, mapa)) {
		if (proximo_mapa(player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_direita);
			
			player->matriz_position_x = 0;
			player->map_position_x = player->matriz_position_x * PIXEL_SIZE;
			player->animation_next_image = 0;

			return;
		}
		else {
			player->status = PARADO;
			return;
		}
	}

	if (player->sum_x_pixel == PIXEL_SIZE) {

		player->matriz_position_x++;
		player->map_position_x = player->matriz_position_x * PIXEL_SIZE;
		player->image = player->animation[3][0];

		player->sum_x_pixel = 0;

		if (!player->pressing_key) 
			player->status = PARADO;

		return;
	}
	else {
		player->sum_x_pixel += SPEED;
	}

	if (player->sum_x_pixel % 8 == 0) {

		if (player->animation_next_image == 4) {
			player->animation_next_image = 0;
		}

		player->image = player->animation[3][player->animation_next_image];
		player->animation_next_image++;
	}

}

int encontrar_npc(struct al_mapa* mapa, int x, int y) {
	for (int i = 0; i < mapa->quantidade_npc; i++) {
		if (mapa->npc[i].x == x && mapa->npc[i].y == y) {
			return i;
		}
	}
}

void virar_npc(struct Player* player, struct al_mapa* mapa) {

	int npc_position = 0;
	switch (player->direcao) {
	case PRA_CIMA:
		npc_position = encontrar_npc(mapa, player->matriz_position_x, player->matriz_position_y - 1);
		mapa->npc[npc_position].direcao = PRA_BAIXO - 1;
		break;
	case PRA_BAIXO:
		npc_position = encontrar_npc(mapa, player->matriz_position_x, player->matriz_position_y + 1);
		mapa->npc[npc_position].direcao = PRA_CIMA - 1;
		break;
	case PRA_ESQUERDA:
		npc_position = encontrar_npc(mapa, player->matriz_position_x - 1, player->matriz_position_y);
		mapa->npc[npc_position].direcao = PRA_DIREITA - 1;
		break;
	case PRA_DIREITA:
		npc_position = encontrar_npc(mapa, player->matriz_position_x + 1, player->matriz_position_y);
		mapa->npc[npc_position].direcao = PRA_ESQUERDA - 1;
		break;
	}
}
