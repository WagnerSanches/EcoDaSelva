#include <PLAYER.h>
#include <AL_MAPA.h>

void evento_conversar_key_precionada(struct Player* player, struct al_mapa* mapa, int keycode) {

	switch (keycode) {
	case ALLEGRO_KEY_SPACE:

		if (mapa->npc[player->indice_bot_conversando]->npc_quest) {
			mapa->npc[player->indice_bot_conversando]->dialogo_lido++;
			if (mapa->npc[player->indice_bot_conversando]->dialogo_lido == 3) {
				mapa->npc[player->indice_bot_conversando]->dialogo_lido = 2;
				player->status = PARADO;
			}
		}
		else {
			player->status = PARADO;
		}
		
		break;
	}
}