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
	
		player->status = CONVERSANDO;
	}
	else if (interagiu(player, mapa, ITEM)) {

		for (int i = 0; i < mapa->quantidade_npc; i++) {
			if (mapa->item[i]->matriz_position_x == mapa->objeto_interacao->matriz_position_x && mapa->item[i]->matriz_position_y == mapa->objeto_interacao->matriz_position_y) {
				player->indice_objeto_interacao = i;
				return;
			}
		}

		mapa->objeto_interacao->matriz_position_x = -1;
		mapa->objeto_interacao->matriz_position_y = -1;

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