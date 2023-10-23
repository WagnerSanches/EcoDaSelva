#pragma once
#include <AL_MAPA.h>

void desenha_npc(struct al_mapa* mapa);
void carregar_mapa(struct al_mapa* mapa, int next_mapa);
void desenha_personagem(struct Player* player);
void desenha_background(struct al_mapa* mapa);
void desenha_jogo(struct Player* player, struct al_mapa* mapa);