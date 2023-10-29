#ifndef ANIMATION_H
#define ANIMATION_H

void andar_para_cima(struct Player* player, struct al_mapa* mapa);
void andar_para_baixo(struct Player* player, struct al_mapa* mapa);
void andar_para_esquerda(struct Player* player, struct al_mapa* mapa);
void andar_para_direita(struct Player* player, struct al_mapa* mapa);
void virar_npc(struct Player* player, struct al_mapa* mapa);

#endif