#ifndef ACTION_H
#define ACTION_H

void interagir(struct Player* player, struct al_mapa* mapa);
void andar(struct Player* player, struct al_mapa* mapa);
void acessar(struct Player* player, struct Fichario* fichario);
void reiniciar(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, struct Pausa* pausa);
void encerrar(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, struct Pausa* pausa);

#endif