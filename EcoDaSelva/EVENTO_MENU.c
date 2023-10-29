#include <PLAYER.h>

void evento_menu_key_precionada(struct Player* player, int keycode) {
	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:
		if (player->menu->opcao - 1 >= 0) {
			player->menu->opcao--;
		}

		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:
		if (player->menu->opcao + 1 <= 2) {
			player->menu->opcao++;
		}

		break;
	case ALLEGRO_KEY_SPACE:

		if (player->menu->opcao == 0) {
			player->menu->ativo = false;
			player->status = PARADO;
		}
		else if (player->menu->opcao == 2) {
			player->menu->encerrar = true;
		}

		break;
	}
}