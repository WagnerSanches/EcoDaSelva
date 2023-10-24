#include <allegro5/allegro5.h>
#include <PLAYER.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include "EVENTO_FICHARIO.h"


void evento_fichario_key_precionada(struct Player* player, struct Fichario* fichario, int keycode) {
	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:
		
		fichario->classe_selecionada--;

		if (fichario->classe_selecionada <= -1) {
			fichario->classe_selecionada = NUMBER_OF_CLASSES - 1;
		}

		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:

		fichario->classe_selecionada++;

		if (fichario->classe_selecionada >= NUMBER_OF_CLASSES) {
			fichario->classe_selecionada = 0;
		}

		break;
	case ALLEGRO_KEY_LEFT:
	case ALLEGRO_KEY_A:

		break;
	case ALLEGRO_KEY_RIGHT:
	case ALLEGRO_KEY_D:

		break;

	case ALLEGRO_KEY_SPACE:
		printf("Selecionou o animal");

		break;
	case ALLEGRO_KEY_ENTER:

		switch (fichario->status) {
		case FICHARIO_FECHADO:
			fichario->status = ABRIR_FICHARIO;

			player->status = FICHARIO;
			player->animation_next_image = 0;
			player->pressing_key = false;
			player->pressing_multiple_key = false;
			player->image = player->animation[player->direcao - 1][0];

			break;
		case FICHARIO_ABERTO:
			fichario->status = FECHAR_FICHARIO;
		}

		break;
	}
}

void evento_fichario_key_levantada(struct Player* player, struct Fichario* fichario, int keycode) {

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