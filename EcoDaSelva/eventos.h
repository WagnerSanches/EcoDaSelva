#ifndef EVENTOS_H
#define EVENTOS_H
#include <player.h>

void tecla_presionado(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, int keycode);
void tecla_levantada(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, int keycode);
void conversar(struct Player* player, struct al_mapa* mapa);

#endif