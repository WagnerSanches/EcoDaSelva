#include <allegro5/allegro5.h>
#include <PLAYER.h>
#include <PAUSA.h>
#include <AL_MAPA.h>
#include <config.h>

void evento_final_key_precionada(struct Player* player, struct Pausa* pausa, int keycode) {
	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:

		if(player->opcao_final_jogo - 1 == 0)
			player->opcao_final_jogo--;

		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:

		if (player->opcao_final_jogo + 1 == 1)
			player->opcao_final_jogo++;

		break;
	case ALLEGRO_KEY_SPACE:

		if (player->opcao_final_jogo == 0) {
			pausa->reiniciar = true;
		}
		else {
			pausa->encerrar = true;
		}

		al_destroy_bitmap(player->finalItems->background);
		al_destroy_bitmap(player->finalItems->animal);
		al_destroy_bitmap(player->finalItems->resize);
		al_destroy_font(player->finalItems->font_points);
		al_destroy_font(player->finalItems->font_categoria);
		al_destroy_font(player->finalItems->sub_tittle_animal);
		al_destroy_font(player->finalItems->tittle_animal);

		free(player->finalItems);
		
		break;
	}
}