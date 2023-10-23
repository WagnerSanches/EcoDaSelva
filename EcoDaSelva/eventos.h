#ifndef EVENTOS_H
#define EVENTOS_H
#include <player.h>

void tecla_presionado(struct Player* player, int keycode);
void tecla_levantada(struct Player* player, int keycode);

#endif