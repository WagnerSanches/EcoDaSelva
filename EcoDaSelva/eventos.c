#include <allegro5/allegro5.h>
#include <eventos.h>
#include <stdlib.h>
#include <player.h>
#include <SENTIDO.h>
#include <EVENTO_ANDAR.h>
#include <EVENTO_FICHARIO.h>

void tecla_presionado(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, int keycode) {

	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:

		if (player == FICHARIO) {
			evento_fichario_key_precionada(player, fichario, keycode);
		}
		else {
			if (player->status != CONVERSANDO)
				evento_andar_key_precionada(player, keycode);
		}

		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:

		if (player->status == FICHARIO) {
			evento_fichario_key_precionada(player, fichario, keycode);
		}
		else {
			if (player->status != CONVERSANDO)
				evento_andar_key_precionada(player, keycode);
		}

		break;
	case ALLEGRO_KEY_LEFT:
	case ALLEGRO_KEY_A:

		if (player->status == FICHARIO) {
			evento_fichario_key_precionada(player, fichario, keycode);
		}
		else {
			if (player->status != CONVERSANDO)
				evento_andar_key_precionada(player, keycode);
		}

		break;
	case ALLEGRO_KEY_RIGHT:
	case ALLEGRO_KEY_D:

		if (player->status == FICHARIO) {
			evento_fichario_key_precionada(player, fichario, keycode);
		}
		else {
			if (player->status != CONVERSANDO)
				evento_andar_key_precionada(player, keycode);
		}

		break;
	case ALLEGRO_KEY_LSHIFT:
		if (player->status == FICHARIO) {
			evento_fichario_key_precionada(player, fichario, keycode);

		}
		else {
			if (player->status != CONVERSANDO)
				evento_andar_key_precionada(player, keycode);
		}
		break;
	case ALLEGRO_KEY_SPACE:

		if (player->status == FICHARIO) {
			evento_fichario_key_precionada(player, fichario, keycode);
		}
		else if (player->status == CONVERSANDO) {
			player->status = PARADO;
		}
		else {
			player->status = INTERAGINDO;
			player->image = player->animation[player->direcao - 1][0];
			player->animation_next_image = 1;
		}
		break;
	case ALLEGRO_KEY_ENTER:
		evento_fichario_key_precionada(player, fichario, keycode);
		break;
	}

}

void tecla_levantada(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, int keycode) {

	switch (keycode) {

	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_LEFT:
	case ALLEGRO_KEY_RIGHT:
	case ALLEGRO_KEY_W:
	case ALLEGRO_KEY_S:
	case ALLEGRO_KEY_A:
	case ALLEGRO_KEY_D:

		if (player->status != FICHARIO) {
			if (player->status != CONVERSANDO)
				evento_andar_key_levantada(player, keycode);
		}

		break;
	case ALLEGRO_KEY_LSHIFT:

		if (player->status != FICHARIO) {
			if (player->status != CONVERSANDO)
				evento_andar_key_levantada(player, keycode);
		}

		break;
	}

}