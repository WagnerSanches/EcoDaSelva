#include <PLAYER.h>
#include <AL_MAPA.h>

void evento_conversar_key_precionada(struct Player* player, struct al_mapa* mapa, int keycode) {

	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:

		if (mapa->npc[player->indice_objeto_interacao]->npc_quest) {
			int selecionada = mapa->npc[player->indice_objeto_interacao]->dialogo[mapa->npc[player->indice_objeto_interacao]->dialogo_lido]->opcao_selecionada;

			if (selecionada - 1 >= 0) {
				mapa->npc[player->indice_objeto_interacao]->dialogo[mapa->npc[player->indice_objeto_interacao]->dialogo_lido]->opcao_selecionada--;
			}
		}

		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:

		if (mapa->npc[player->indice_objeto_interacao]->npc_quest) {
			int selecionada = mapa->npc[player->indice_objeto_interacao]->dialogo[mapa->npc[player->indice_objeto_interacao]->dialogo_lido]->opcao_selecionada;

			if (selecionada + 1 <= 1) {
				mapa->npc[player->indice_objeto_interacao]->dialogo[mapa->npc[player->indice_objeto_interacao]->dialogo_lido]->opcao_selecionada++;
			}

		}

		break;
	case ALLEGRO_KEY_SPACE:

		if (mapa->npc[player->indice_objeto_interacao]->npc_quest && mapa->npc[player->indice_objeto_interacao]->quest_terminada == false) {
			printf("EU SOU VERDADEIRO\n");

			if (mapa->npc[player->indice_objeto_interacao]->dialogo_lido == 0
				&& player->missao->quest_aceita == false) {
				mapa->npc[player->indice_objeto_interacao]->dialogo_lido++;
				printf("Dialogo incial\n");
			}
			else if (mapa->npc[player->indice_objeto_interacao]->dialogo_lido == 1
						&& player->missao->quest_aceita == false) {
				if (mapa->npc[player->indice_objeto_interacao]->dialogo[mapa->npc[player->indice_objeto_interacao]->dialogo_lido]->opcao_selecionada == 0) {
					player->missao->quest_aceita = true;
					player->missao->indice_npc_guest_aceita = player->indice_objeto_interacao;
					printf("Aceitou a missao\n");
				}
				else {
					mapa->npc[player->indice_objeto_interacao]->dialogo[mapa->npc[player->indice_objeto_interacao]->dialogo_lido]->opcao_selecionada = 0;
					player->status = PARADO;
					printf("Recusou a missao\n");
				}
			}
			else if (player->indice_objeto_interacao == player->missao->indice_npc_guest_aceita) {

				bool item_pegado = false;
				for (int i = 0; i < player->quantidade_itens_pegados; i++) {
					printf("R = %d\n", strcmp(player->itens_pegados[i], mapa->npc[player->indice_objeto_interacao]->nome_item_quest));
					int r = strcmp(player->itens_pegados[i], mapa->npc[player->indice_objeto_interacao]->nome_item_quest);
					if (r == 0)
						item_pegado = true;
				}

				if (item_pegado) {
					mapa->npc[player->indice_objeto_interacao]->dialogo_lido++;
					printf("Concluiu a missao\n");

					mapa->npc[player->indice_objeto_interacao]->quest_terminada = true;
					player->missao->indice_npc_guest_aceita = 0;
					player->missao->quest_aceita = false;
					player->status = PARADO;
				}
				else if (mapa->npc[player->indice_objeto_interacao]->quest_terminada) {
					printf("Missao ja terminada\n");
					player->status = PARADO;
				}
				else {
					printf("Fazendo a missao\n");
					player->status = PARADO;
				}
			}
			else {
				printf("Fazendo outra missao\n");
				player->status = PARADO;
			}
		}
		else {
			printf("Fez nada\n");
			player->status = PARADO;
		}
		
		break;
	}
}