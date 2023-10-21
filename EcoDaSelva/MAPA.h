#pragma once
#include <AL_MAPA.h>

void desenha_npc(struct al_mapa* mapa);
void carregar_mapa(struct al_mapa* mapa, int next_mapa);
void desenha_personagem(struct Player* player, int sum_x_pixel, int sum_y_pixel);
void desenha_background(struct al_mapa* mapa);