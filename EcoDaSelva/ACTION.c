#include <stdio.h>
#include <player.h>
#include <AL_MAPA.h>
#include <REGRA.h>
#include <animation.h>

void interagir(struct Player* player, struct al_mapa* mapa) {

	if (npc(player, mapa)) {
		virar_npc(player, mapa);
	}

	player->status = PARADO;
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