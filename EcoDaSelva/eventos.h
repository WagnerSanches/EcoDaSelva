#ifndef EVENTOS_H
#define EVENTOS_H
#include <Direcao.h>
#include <enum_estados.h>
#include <player.h>

void botao_presionado(int keycode, struct Direcao *direcao, enum Estados *estados, struct Player *player);

#endif