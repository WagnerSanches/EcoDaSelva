#ifndef EVENTOS_H
#define EVENTOS_H
#include <player.h>

void tecla_presionado(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, struct Pausa* pausa, int keycode);
void tecla_levantada(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, struct Pausa* pausa, int keycode);

#endif