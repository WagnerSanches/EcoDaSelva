
#pragma once
void andar_para_cima(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, enum Mapa* indice_mapa, struct Viewport* viewport);
void andar_para_baixo(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, enum Mapa* indice_mapa, struct Viewport* viewport);
void andar_para_esquerda(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, enum Mapa* indice_mapa, struct Viewport* viewport);
void andar_para_direita(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, enum Mapa* indice_mapa, struct Viewport* viewport);
void printa_personagem(float x, float y);
void andar(struct Direcao* direcao, enum Estados* estados, struct Player* player, int pressed, enum Mapa* indice_mapa, struct Viewport* viewport);
void printa_mapa(ALLEGRO_BITMAP* background, struct Viewport* viewport);