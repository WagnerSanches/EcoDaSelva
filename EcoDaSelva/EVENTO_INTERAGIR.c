
#include <allegro5/allegro5.h>
#include <PLAYER.h>
#include <AL_MAPA.h>
#include <config.h>

void evento_interagir_key_precionada(struct Player* player, struct al_mapa* mapa, int keycode) {
	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:
		if (mapa->item[player->indice_objeto_interacao]->item_missao) {

			if (mapa->item[player->indice_objeto_interacao]->ajudante->opcao_selecionada - 1 == 0) {
				mapa->item[player->indice_objeto_interacao]->ajudante->opcao_selecionada--;
			}
		}

		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:
		if (mapa->item[player->indice_objeto_interacao]->item_missao) {
			if (mapa->item[player->indice_objeto_interacao]->ajudante->opcao_selecionada + 1 == 1) {
				mapa->item[player->indice_objeto_interacao]->ajudante->opcao_selecionada++;
			}
		}
		
		break;
	case ALLEGRO_KEY_SPACE:

		if (mapa->item[player->indice_objeto_interacao]->item_missao) {

			if (mapa->item[player->indice_objeto_interacao]->ajudante->opcao_selecionada == 0) {
				strcpy(player->itens_pegados[player->quantidade_itens_pegados], mapa->item[player->indice_objeto_interacao]->nome);
				player->status = PARADO;
				player->quantidade_itens_pegados++;
				mapa->item[player->indice_objeto_interacao]->ajudante->opcao = false;
				mapa->item[player->indice_objeto_interacao]->item_pegado = true;
				mapa->matriz[mapa->item[player->indice_objeto_interacao]->matriz_position_y][mapa->item[player->indice_objeto_interacao]->matriz_position_x] = 0;
			}
			else {
				mapa->item[player->indice_objeto_interacao]->ajudante->opcao_selecionada = 0;
				player->status = PARADO;
			}

		}
		else {
			player->status = PARADO;
		}

		break;
	}
}