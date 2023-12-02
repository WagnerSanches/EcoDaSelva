#include <config.h>
#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <AJUDANTE.h>

void carregar_mapa_direita_floresta_desmatada(struct al_mapa* mapa)
{
	mapa->background = al_load_bitmap("assets/mapa/DiretaFlorestaDesmatada.png");

	mapa->next_mapa->pra_esquerda = 1;
	for (int i = 0; i < 18; i++) {
		mapa->matriz[i][0] = 3;
	}

	mapa->next_mapa->pra_baixo = 5;
	for (int i = 0; i < WINDOW_SIZE_PIXEL_X - 5; i++) {
		mapa->matriz[WINDOW_SIZE_PIXEL_Y - 1][i] = 3;
	}

	mapa->quantidade_item = 1;

	strcpy(mapa->item[0]->nome, "Latex");
	mapa->item[0]->matriz_position_x = 25;
	mapa->item[0]->matriz_position_y = 6;
	mapa->item[0]->image = al_load_bitmap("assets/objeto/arvore/seringueira.png");
	mapa->item[0]->item_missao = true;
	mapa->item[0]->ajudante->quantiade_imagem = 0;
	mapa->item[0]->ajudante->opcao = true;
	mapa->item[0]->ajudante->opcao_selecionada = 0;
	mapa->item[0]->ajudante->tipo_pergunta = PERGUNTA_ITEM;
	strcpy(mapa->item[0]->ajudante->texto, "Voce encontrou uma carnauba! A carnauba, ou Copernicia prunifera, e uma palmeira do Cerrado cujas folhas sao essenciais para a sobrevivencia de animais como o soldadinho-do-araripe, que constroi ninhos com elas. Alem disso, a cera de carnauba e usada em diversos produtos.");

	for (int i = 0; i < mapa->quantidade_item; i++)
		mapa->matriz[mapa->item[i]->matriz_position_y][mapa->item[i]->matriz_position_x] = 5;

}