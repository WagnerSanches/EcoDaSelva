#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <direcao.h>
#include <enum_estados.h>
#include <player.h>
#include <math.h>
#include <mapa_vila.h>
#include <enum_maps.h>
#include <config.h>
#include <AL_MAPA.h>
#include <stdbool.h>
#include <REGRA.h>
#include <MAPA.h>

void printa_mapa(ALLEGRO_BITMAP* background) {
	al_draw_bitmap(background, 0, 0, 0);
}

void printa_personagem(float x, float y) {
	al_draw_filled_rectangle(x * PIXEL_SIZE, y * PIXEL_SIZE, x * PIXEL_SIZE + PIXEL_SIZE, y * PIXEL_SIZE + PIXEL_SIZE, al_map_rgb(186, 181, 93), 0);
}

void andar_para_cima(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, struct al_mapa* mapa) {

	if (colediu(direcao, player, mapa)) {
		if (proximo_mapa(direcao, player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_cima);
			player->position_y = WINDOW_SIZE_Y - 1;
			return;
		}
		else {
			*estados = IDLE;
			return;
		}
	}

	if (fabs(direcao->y - (-1.0)) < 0.00001) {
		printa_personagem(player->position_x, player->position_y + direcao->y);
		player->position_y--;
		direcao->y = 0;

		if (pressed == 0) *estados = IDLE;
	}
	else {
		printa_personagem(player->position_x, player->position_y + direcao->y);
		direcao->y -= SPEED;
	}
}

void andar_para_baixo(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, struct al_mapa* mapa) {

	if (colediu(direcao, player, mapa)) {
		if (proximo_mapa(direcao, player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_baixo);
			player->position_y = 0;
			return;
		}
		else {
			*estados = IDLE;
			return;
		}
	}

	if (fabs(direcao->y - (1)) < 0.00001) {
		printa_personagem(player->position_x, player->position_y + direcao->y);
		player->position_y++;
		direcao->y = 0;

		if (pressed == 0) *estados = IDLE;
	}
	else {
		printa_personagem(player->position_x, player->position_y + direcao->y);
		direcao->y += SPEED;
	}
}

void andar_para_esquerda(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, struct al_mapa* mapa) {
	
	if (colediu(direcao, player, mapa)) {
		if (proximo_mapa(direcao, player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_esquerda);
			player->position_x = WINDOW_SIZE_X - 1;
			return;
		}
		else {
			*estados = IDLE;
			return;
		}
	}

	if (fabs((direcao->x ) - (-1)) < 0.00001) {
		printa_personagem(player->position_x + direcao->x, player->position_y);
		player->position_x--;
		direcao->x = 0;

		if (pressed == 0) *estados = IDLE;
	}
	else {
		printa_personagem(player->position_x + direcao->x, player->position_y);
		direcao->x -= SPEED;
	}
}	

void andar_para_direita(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, struct al_mapa* mapa) {
	
	if (colediu(direcao, player, mapa)) {
		if (proximo_mapa(direcao, player, mapa)) {
			carregar_mapa(mapa, mapa->next_mapa.pra_direita);
			player->position_x = 0;
			return;
		}
		else {
			*estados = IDLE;
			return;
		}
	}

	//if (player->position_x == 31) {
	//	/*
	//	if (map[(int)player->position_y][(int)player->position_x] == 3) {
	//		*indice_mapa = DIREITA;
	//		printf("Voce pode passar pro proximo mapa\n");
	//		player->position_x = 0;
	//	}
	//	else {
	//		*estados = IDLE;
	//		return;
	//	}*/
	//	printf("Chegou no final do mapa\n");
	//	printa_personagem(player->position_x + direcao->x, player->position_y);
	//	//*estados = IDLE;
	//}

	////if (map[(int)player->position_y][(int)player->position_x + 1] == 1) {
	////	printf("Voce nao pode andar ai!\n");
	////	printa_personagem(player->position_x + direcao->x, player->position_y);
	////	
	////}

	if (fabs((direcao->x ) - (1)) < 0.00001) {
		printa_personagem(player->position_x + direcao->x, player->position_y);
		player->position_x++;
		direcao->x = 0;

		if (pressed == 0) *estados = IDLE;
	}
	else {
		direcao->x += SPEED;
		printa_personagem(player->position_x + direcao->x, player->position_y);
	}
}


void andar(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, struct al_mapa* mapa) {

	switch (direcao->sentido) {
	case 1:
		andar_para_cima(direcao, estados, player, pressed, mapa);
		break;
	case 2:
		andar_para_baixo(direcao, estados, player, pressed, mapa);
		break;
	case 3:
		andar_para_esquerda(direcao, estados, player, pressed, mapa);
		break;
	case 4:
		andar_para_direita(direcao, estados, player, pressed, mapa);
		break;
	}

}

void meu_mapa(struct al_mapa* mapa) {
	printf("meu_mapa = %p\n", mapa);
}