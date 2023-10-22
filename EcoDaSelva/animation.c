#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <player.h>
#include <math.h>
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
			
			player->matriz_position_y = WINDOW_SIZE_PIXEL_Y - 1;
			player->map_position_y = player->matriz_position_y * PIXEL_SIZE;

			return;
		}
		else {
			player->sum_y_pixel = 0;
			player->status = PARADO;
			return;
		}
	}

	if (player->velocidade == 4)
		if (player->sum_y_pixel % player->velocidade == -2)
			player->sum_y_pixel += -2;

	if (player->sum_y_pixel % (player->velocidade * 4) == 0) {

		if (player->animation_next_image == 4) {
			player->animation_next_image = 0;
		}

		player->image = player->animation[0][player->animation_next_image];
		player->animation_next_image++;
	}

	if (!player->pressing_key) {
		player->image = player->animation[0][0];
		player->status = PARADO;
		return;
	} else {
		player->sum_y_pixel -= player->velocidade;

		if (player->sum_y_pixel == -PIXEL_SIZE) {

			player->matriz_position_y--;
			player->map_position_y = player->matriz_position_y * PIXEL_SIZE;
			player->sum_y_pixel = 0;
		}
	}
}

void andar_para_baixo(struct Player* player, struct al_mapa* mapa) {

	if (colediu(player, mapa)) {
		if (proximo_mapa(player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_baixo);
			player->matriz_position_y = 0;
			player->map_position_y = player->matriz_position_y * PIXEL_SIZE;
			return;
		}
		else {
			player->status = PARADO;
			player->sum_y_pixel = 0;
			return;
		}
	}

	if (player->velocidade == 4)
		if (player->sum_y_pixel % player->velocidade == 2) 
			player->sum_y_pixel += 2;

	if (player->sum_y_pixel % (player->velocidade * 4) == 0) {

		if (player->animation_next_image == 4) {
			player->animation_next_image = 0;
		}

		player->image = player->animation[1][player->animation_next_image];
		player->animation_next_image++;
	}

	if (!player->pressing_key) {
		player->image = player->animation[1][0];
		player->status = PARADO;
		return;
	}
	else {
		player->sum_y_pixel += player->velocidade;

		if (player->sum_y_pixel == PIXEL_SIZE) {

			player->matriz_position_y++;
			player->map_position_y = player->matriz_position_y * PIXEL_SIZE;
			player->sum_y_pixel = 0;
		}
	}
}

void andar_para_esquerda(struct Player* player, struct al_mapa* mapa) {

	if (colediu(player, mapa)) {
		if (proximo_mapa(player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_esquerda);

			player->matriz_position_x = WINDOW_SIZE_PIXEL_X - 1;
			player->map_position_x = player->matriz_position_x * PIXEL_SIZE;

			return;
		}
		else {
			player->status = PARADO;
			player->sum_x_pixel = 0;
			return;
		}
	}

	if (player->velocidade == 4)
		if (player->sum_x_pixel % player->velocidade == -2) 
			player->sum_x_pixel += -2;

	if (player->sum_x_pixel % (player->velocidade * 4) == 0) {

		if (player->animation_next_image == 4) {
			player->animation_next_image = 0;
		}

		player->image = player->animation[2][player->animation_next_image];
		player->animation_next_image++;
	}

	if (!player->pressing_key) {
		player->image = player->animation[2][0];
		player->status = PARADO;
		return;
	}
	else {
		player->sum_x_pixel -= player->velocidade;

		if (player->sum_x_pixel == -PIXEL_SIZE) {
			player->matriz_position_x--;
			player->map_position_x = player->matriz_position_x * PIXEL_SIZE;
			player->sum_x_pixel = 0;
		}

	}
}	

void andar_para_direita(struct Player* player, struct al_mapa* mapa) {

	// sistema de colisao com os objetos e npcs do mapa
	if (colediu(player, mapa)) {

		player->pressing_key = false;
		/*if (proximo_mapa(player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_direita);
			
			player->matriz_position_x = 0;
			player->map_position_x = player->matriz_position_x * PIXEL_SIZE;
			player->animation_next_image = 0;

			return;
		}
		else {
			player->status = PARADO;
			return;
		}*/
		player->status = PARADO;

		return;
	}

	// ajusta a velocidade
	if(player->velocidade == 4)
		if (player->sum_x_pixel % player->velocidade == 2 || player->sum_x_pixel % player->velocidade == -2)
			player->sum_x_pixel += 2;

	// troca o slide de animacao do player andando
	if (player->sum_x_pixel % (player->velocidade * 4) == 0) {

		if (player->animation_next_image == 4) {
			player->animation_next_image = 0;
		}

		player->image = player->animation[3][player->animation_next_image];
		player->animation_next_image++;
	}

	// faz com que o player se mova na tela
	// caso ele nao estiver precionando a tecla o personagem fica no estado de PARADO
	if (!player->pressing_key) {
		player->image = player->animation[3][0];
		player->status = PARADO;
		return;
	} else {
		player->sum_x_pixel += player->velocidade;

		if (player->sum_x_pixel == PIXEL_SIZE) {

			player->matriz_position_x++;

			player->map_position_x += player->sum_x_pixel;
			player->sum_x_pixel = 0;
		}
	}

}

int encontrar_npc(struct al_mapa* mapa, int x, int y) {
	for (int i = 0; i < mapa->quantidade_npc; i++) {
		if (mapa->npc[i].matriz_position_x == x && mapa->npc[i].matriz_position_y == y) {
			return i;
		}
	}

	return -1;
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
