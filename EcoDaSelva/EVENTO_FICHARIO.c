#include <allegro5/allegro5.h>
#include <PLAYER.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

void evento_fichario_key_precionada(struct Player* player, int keycode) {
	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:

		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:


		break;
	case ALLEGRO_KEY_LEFT:
	case ALLEGRO_KEY_A:

		if (player->animal_selecionado > 0) {
			player->animal_selecionado--;
		}

		break;
	case ALLEGRO_KEY_RIGHT:
	case ALLEGRO_KEY_D:

		if (player->animal_selecionado < NUMBER_OF_ANIMALS - 1) {
			player->animal_selecionado++;
		}

		break;

	case ALLEGRO_KEY_SPACE:
		player->status = INTERAGINDO;
		player->animation_next_image = 0;
		break;
	case ALLEGRO_KEY_ENTER:

		if (player->status == ACESSANDO) {
			player->status = FECHOU_FICHARIO;
		}
		else {
			player->status = ABRIU_FICHARIO;
			player->animation_next_image = 0;
			player->pressing_key = false;
			player->pressing_multiple_key = false;
			player->image = player->animation[player->direcao - 1][0];

		}

		break;
	}
}
void evento_fichario_key_levantada(struct Player* player, int keycode) {

	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:

		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:


		break;
	case ALLEGRO_KEY_LEFT:
	case ALLEGRO_KEY_A:

		break;
	case ALLEGRO_KEY_RIGHT:
	case ALLEGRO_KEY_D:

		break;

	case ALLEGRO_KEY_SPACE:

	case ALLEGRO_KEY_ENTER:


		break;
	}

}