#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <direcao.h>
#include <enum_estados.h>
#include <player.h>
#include <math.h>
#include <viewport.h>

#define PIXEL_SIZE 64
#define SPEED 0.1


void printa_mapa(ALLEGRO_BITMAP* background, struct Viewport* viewport) {
	al_draw_bitmap(background, viewport->x, viewport->y, 0);
}

void printa_personagem(float x, float y) {
	al_draw_filled_rectangle(x * PIXEL_SIZE, y * PIXEL_SIZE, x * PIXEL_SIZE + PIXEL_SIZE, y * PIXEL_SIZE + PIXEL_SIZE, al_map_rgb(186, 181, 93), 0);
}

void andar_para_cima(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, ALLEGRO_BITMAP* background, struct Viewport* viewport) {
	if (fabs(direcao->y - (-1.0)) < 0.00001) {
		printa_mapa(background, viewport);
		printa_personagem(player->position_x, player->position_y + direcao->y);
		player->position_y--;
		direcao->y = 0;

		if (pressed == 0) *estados = IDLE;
	}
	else {
		printa_mapa(background, viewport);
		printa_personagem(player->position_x, player->position_y + direcao->y);
		direcao->y -= SPEED;
		viewport->y = viewport->y + (SPEED * PIXEL_SIZE);
	}
}

void andar_para_baixo(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, ALLEGRO_BITMAP* background, struct Viewport* viewport) {
	if (fabs(direcao->y - (1.0)) < 0.00001) {
		printa_mapa(background, viewport);
		printa_personagem(player->position_x, player->position_y + direcao->y);
		player->position_y++;
		direcao->y = 0;

		if (pressed == 0) *estados = IDLE;
	}
	else {
		printa_mapa(background, viewport);
		printa_personagem(player->position_x, player->position_y + direcao->y);
		direcao->y += SPEED;
		viewport->y = viewport->y - (SPEED * PIXEL_SIZE);
	}
}

void andar_para_esquerda(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, ALLEGRO_BITMAP* background, struct Viewport* viewport) {

	printf("Direcao X = %f, Player X = %f\n", direcao->x, player->position_x);

	if (fabs((direcao->x + 0.5) - (player->position_x)) < 0.00001) {
		printa_mapa(background, viewport);
		printa_personagem(player->position_x, player->position_y);
		direcao->x = 0;

		*estados = IDLE;
	}
	else {
		player->position_x = player->position_x - SPEED;
		viewport->x = viewport->x + (0.2 * PIXEL_SIZE);

		printa_mapa(background, viewport);
		printa_personagem(player->position_x, player->position_y);
	}
}

void andar_para_direita(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, ALLEGRO_BITMAP* background, struct Viewport* viewport) {

	if (fabs((direcao->x - 0.5) - player->position_x) < 0.00001) {
		printa_mapa(background, viewport);
		printa_personagem(player->position_x, player->position_y);
		direcao->x = 0;

		*estados = IDLE;
	}
	else {
		player->position_x = player->position_x + SPEED;
		viewport->x = viewport->x - (PIXEL_SIZE * 0.2);

		printa_mapa(background, viewport);
		printa_personagem(player->position_x , player->position_y);
	}
}


void andar(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, ALLEGRO_BITMAP* background, struct Viewport* viewport) {

	switch (direcao->sentido) {
	case 1:
		andar_para_cima(direcao, estados, player, pressed, background, viewport);
		break;
	case 2:
		andar_para_baixo(direcao, estados, player, pressed, background, viewport);
		break;
	case 3:
		andar_para_esquerda(direcao, estados, player, pressed, background, viewport);
		break;
	case 4:
		andar_para_direita(direcao, estados, player, pressed, background, viewport);
		break;
	}

}