#include <allegro5/allegro5.h>
#include <PAUSA.h>

void evento_pausa_key_precionada(struct Pausa* pausa, int keycode) {
	switch (keycode) {
	case ALLEGRO_KEY_UP:
	case ALLEGRO_KEY_W:
		if (pausa->opcao - 1 >= 0) {
			pausa->opcao--;
		}

		break;
	case ALLEGRO_KEY_DOWN:
	case ALLEGRO_KEY_S:
		if (pausa->opcao + 1 <= 2) {
			pausa->opcao++;
		}

		break;
	case ALLEGRO_KEY_SPACE:

		/*if (pausa->opcao == 0) {
			pausa->ativo = false;
			player->status = PARADO;
		}
		else if (pausa->selecionado == 2) {
			menu->encerrar = true;
		}*/

		break;
	case ALLEGRO_KEY_ESCAPE:
		pausa->pausado = !pausa->pausado;

		break;
	}
}