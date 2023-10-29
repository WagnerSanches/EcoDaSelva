#include <stdio.h>
#include <player.h>
#include <AL_MAPA.h>
#include <REGRA.h>
#include <animation.h>
#include <FICHARIO.h>
#include <OBJETO.h>

void interagir(struct Player* player, struct al_mapa* mapa) {
	
	if (interagiu(player, mapa, NPC)) {

		virar_npc(player, mapa);
		mapa->objeto_interacao->matriz_position_x = -1;
		mapa->objeto_interacao->matriz_position_y = -1;
	
		if (player->indice_objeto_interacao == player->missao->indice_npc_guest_aceita) {
			bool item_pegado = false;
			for (int i = 0; i < player->quantidade_itens_pegados; i++) {
				printf("Item pegado = %s", player->itens_pegados[i]);
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

		player->status = CONVERSANDO;
	}
	else if (interagiu(player, mapa, ITEM)) {

		for (int i = 0; i < mapa->quantidade_npc; i++) {
			if (mapa->item[i]->matriz_position_x == mapa->objeto_interacao->matriz_position_x && mapa->item[i]->matriz_position_y == mapa->objeto_interacao->matriz_position_y) {
				player->indice_objeto_interacao = i;
				mapa->objeto_interacao->matriz_position_x = -1;
				mapa->objeto_interacao->matriz_position_y = -1;
			}
		}
	}
	else {
		player->status = PARADO;
	}

	player->animation_next_image = 0;
	player->pressing_key = false;
	player->pressing_multiple_key = false;
}

void andar(struct Player* player, struct al_mapa* mapa) {
	switch (player->direcao) {
	case 1:
		andar_para_cima(player, mapa);
		break;
	case 2:
		andar_para_baixo(player, mapa);
		break;
	case 3:
		andar_para_esquerda(player, mapa);
		break;
	case 4:
		andar_para_direita(player, mapa);
		break;
	}
}

void acessar(struct Player* player, struct Fichario* fichario) {

	switch (fichario->status) {
	case ABRIR_FICHARIO:
		criar_fichario(fichario);
		break;
	case FECHAR_FICHARIO:
		destruir_fichario(fichario);
		fichario->status = FICHARIO_FECHADO;
		player->status = PARADO;

		break;
	case FICHARIO_ABERTO:

		break;
	}

}

void conversar(struct Player* player, struct al_mapa* mapa) {

}