#ifndef REGRA_H
#define REGRA_H

bool colediu(struct Player* player, struct al_mapa* mapa);
bool proximo_mapa(struct Player* player, struct al_mapa* mapa);
bool interagiu(struct Player* player, struct al_mapa* mapa, enum Objeto objeto);

#endif