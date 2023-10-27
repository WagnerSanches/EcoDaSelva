#include <stdio.h>
#include <player.h>
#include <AL_MAPA.h>
#include <REGRA.h>
#include <animation.h>
#include <FICHARIO.h>

void interagir(struct Player* player, struct al_mapa* mapa) {
	
	if (npc(player, mapa)) {

		virar_npc(player, mapa);
		mapa->npc_interacao.matriz_position_x = -1;
		mapa->npc_interacao.matriz_position_y = -1;
	
		player->status = CONVERSANDO;
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
		player->status = PARADO;

		fichario->status = FICHARIO_FECHADO;
		break;
	case FICHARIO_ABERTO:

		break;
	}

}

void conversar(struct Player* player, struct al_mapa* mapa) {

}