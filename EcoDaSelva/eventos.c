#include <allegro5/allegro5.h>
#include <eventos.h>
#include <stdlib.h>
#include <player.h>
#include <SENTIDO.h>
#include <EVENTO_ANDAR.h>
#include <EVENTO_FICHARIO.h>
#include <EVENTO_CONVERSAR.h>
#include <EVENTO_INTERAGIR.h>
#include <EVENTO_FINAL.h>
#include <EVENTO_MENU.h>
#include <EVENTO_PAUSA.h>
#include <AJUDANTE.h>
#include <PAUSA.h>

void tecla_presionado(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, struct Pausa* pausa, int keycode) {

	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:
		
		if (player->ajudante->ajudou == false && player->menu->ativo == false) 
			return;
		
		if (pausa->pausado) {
			evento_pausa_key_precionada(pausa, keycode);
			return;
		}

		if (player->status == FICHARIO)
			evento_fichario_key_precionada(player, fichario, keycode);
		else if (player->status == CONVERSANDO)
			evento_conversar_key_precionada(player, mapa, keycode);
		else if (player->status == INTERAGINDO)
			evento_interagir_key_precionada(player, mapa, keycode);
		else if (player->status == MENU)
			evento_menu_key_precionada(player, keycode);
		else if (player->status == FINAL)
			evento_final_key_precionada(player, pausa, keycode);
		else
			evento_andar_key_precionada(player, keycode);


		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:

		if (player->ajudante->ajudou == false && player->menu->ativo == false)
			return;

		if (pausa->pausado) {
			evento_pausa_key_precionada(pausa, keycode);
			return;
		}

		if (player->status == FICHARIO)
			evento_fichario_key_precionada(player, fichario, keycode);
		else if (player->status == CONVERSANDO)
			evento_conversar_key_precionada(player, mapa, keycode);
		else if (player->status == INTERAGINDO)
			evento_interagir_key_precionada(player, mapa, keycode);
		else if (player->status == MENU)
			evento_menu_key_precionada(player, keycode);
		else if (player->status == FINAL)
			evento_final_key_precionada(player, pausa, keycode); 
		else
			evento_andar_key_precionada(player, keycode);

		break;
	case ALLEGRO_KEY_LEFT:
	case ALLEGRO_KEY_A:

		if (player->ajudante->ajudou == false && player->menu->ativo == false)
			return;

		if (player->status == FICHARIO)
			evento_fichario_key_precionada(player, fichario, keycode);
		else if (player->status != CONVERSANDO 
			&& player->status != INTERAGINDO
			&& player->status != MENU
			&& player->status != FINAL
			&& pausa->pausado == false)
			evento_andar_key_precionada(player, keycode);


		break;
	case ALLEGRO_KEY_RIGHT:
	case ALLEGRO_KEY_D:

		if (player->ajudante->ajudou == false && player->menu->ativo == false)
			return;

		if (player->status == FICHARIO)
			evento_fichario_key_precionada(player, fichario, keycode);
		else if (player->status != CONVERSANDO
			&& player->status != INTERAGINDO
			&& player->status != MENU
			&& player->status != FINAL
			&& pausa->pausado == false)
			evento_andar_key_precionada(player, keycode);


		break;
	case ALLEGRO_KEY_LSHIFT:

		if (player->ajudante->ajudou == false && player->menu->ativo == false)
			return;

		if (player->status == FICHARIO)
			evento_fichario_key_precionada(player, fichario, keycode);
		else if (player->status != CONVERSANDO
			&& player->status != INTERAGINDO
			&& player->status != MENU
			&& player->status != FINAL
			&& pausa->pausado == false)
			evento_andar_key_precionada(player, keycode);

		break;
	case ALLEGRO_KEY_SPACE:

		if (player->ajudante->ajudou == false && player->menu->ativo == false)
			player->ajudante->ajudou = true;

		if (pausa->pausado) {
			evento_pausa_key_precionada(pausa, keycode);
			return;
		}

		if (player->status == FICHARIO)
			evento_fichario_key_precionada(player, fichario, keycode);
		else if (player->status == CONVERSANDO)
			evento_conversar_key_precionada(player, mapa, keycode);
		else if (player->status == INTERAGINDO)
			evento_interagir_key_precionada(player, mapa, keycode);
		else if (player->status == MENU)
			evento_menu_key_precionada(player, keycode);
		else if (player->status == FINAL)
			evento_final_key_precionada(player, pausa, keycode); 
		else {
			player->status = INTERAGINDO;
			player->image = player->animation[player->direcao - 1][0];
			player->animation_next_image = 1;
		}

		break;
	case ALLEGRO_KEY_ENTER:

		if (player->ajudante->ajudou == false && player->menu->ativo == false)
			return;

		if (player->status != CONVERSANDO
			&& player->status != INTERAGINDO
			&& player->status != MENU
			&& player->status != FINAL
			&& pausa->pausado == false)
			evento_fichario_key_precionada(player, fichario, keycode);

		break;
	case ALLEGRO_KEY_ESCAPE:
		if (player->ajudante->ajudou == false && player->menu->ativo == false)
			return;

		if(player->status != FINAL)
			evento_pausa_key_precionada(pausa, keycode);
		
		break;
	}

}

void tecla_levantada(struct Player* player, struct al_mapa* mapa, struct Fichario* fichario, struct Pausa* pausa, int keycode) {

	if (player->finalizou_jogo) return;

	switch (keycode) {

	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_LEFT:
	case ALLEGRO_KEY_RIGHT:
	case ALLEGRO_KEY_W:
	case ALLEGRO_KEY_S:
	case ALLEGRO_KEY_A:
	case ALLEGRO_KEY_D:

		if (player->status != FICHARIO && player->status != CONVERSANDO && player->status != MENU)
			evento_andar_key_levantada(player, keycode);

		break;
	case ALLEGRO_KEY_LSHIFT:

		if (player->status != FICHARIO && player->status != CONVERSANDO && player->status != MENU)
			evento_andar_key_levantada(player, keycode);

		break;
	}

}