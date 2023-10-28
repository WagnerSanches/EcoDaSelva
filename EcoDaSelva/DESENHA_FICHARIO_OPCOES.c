#include <FICHARIO.h>
#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <FICHARIO.h>
#include <AJUDANTE.h>
#include <DESENHA_AJUDANTE.H>

void desenhar_opcoes(struct Fichario* fichario) {
	/* INICIO OPCOES */

	int x_subbox_options_initial = fichario->posicoes->x_subbox_info_final;
	int y_subbox_options_initial = fichario->posicoes->y_subbox_initial;
	int x_subbox_options_final = fichario->posicoes->x_subbox_final;
	int y_subbox_options_final = fichario->posicoes->y_subbox_final;
	int meio_subbox_options = (x_subbox_options_initial + (x_subbox_options_final - x_subbox_options_initial) / 2);
	//al_draw_filled_rectangle(x_subbox_options_initial, y_subbox_options_initial, x_subbox_options_final, y_subbox_options_final, /*al_map_rgb(190, 170, 80)*/ al_map_rgb(186, 181, 93));

	int y_subbox_option_title = y_subbox_options_initial + fichario->posicoes->espacamento_fichario_dentro * 2;

	if (fichario->selecao->grupo_selecionado)
		al_draw_text(
			fichario->posicoes->titulo28,
			al_map_rgb(100, 100, 100),
			meio_subbox_options,
			y_subbox_option_title,
			ALLEGRO_ALIGN_CENTER,
			"Selecione um grupo"
		);
	else
		al_draw_text(
			fichario->posicoes->titulo28,
			al_map_rgb(100, 100, 100),
			meio_subbox_options,
			y_subbox_option_title,
			ALLEGRO_ALIGN_CENTER,
			"Selecione uma classe"
		);

	/*	CAIXA DE OPCOES	 */

	int espacemento_y_inner_subbox_option = fichario->posicoes->espacamento_fichario_dentro * 4;
	int espacemento_y_subbox_option_option = fichario->posicoes->espacamento_fichario_dentro;

	int x_subbox_size_button_option = 384;
	int y_subbox_size_button_option = fichario->posicoes->size_font_subtitulo + 24;

	int x_subbox_button_option_initial = meio_subbox_options - (x_subbox_size_button_option / 2);
	int x_subbox_button_option_final = x_subbox_button_option_initial + x_subbox_size_button_option;
	int y_subbox_button_option_initial = y_subbox_options_initial + espacemento_y_inner_subbox_option;

	/* LINHAS BRANCA DE SELECIONAR OPCAO */
	int line_thickness_button_selected = 4;
	int x_selected_option_initial = x_subbox_button_option_initial - line_thickness_button_selected;

	int y_selected_option_initial = ((y_subbox_button_option_initial + (fichario->selecao->classe * (y_subbox_size_button_option + espacemento_y_subbox_option_option))) - (line_thickness_button_selected)) + 2;
	if (fichario->selecao->grupo_selecionado) {
		y_selected_option_initial = ((y_subbox_button_option_initial +
			(fichario->selecao->grupo * (y_subbox_size_button_option + espacemento_y_subbox_option_option))) -
			(line_thickness_button_selected)) + 2 + fichario->posicoes->espacamento_fichario_dentro;

	}

	int x_selected_option_final = x_subbox_button_option_final + line_thickness_button_selected;
	int y_selected_option_final = y_selected_option_initial + y_subbox_size_button_option + line_thickness_button_selected;
	al_draw_rectangle(x_selected_option_initial, y_selected_option_initial, x_selected_option_final, y_selected_option_final, al_map_rgb(255, 255, 255), line_thickness_button_selected);
	/* FINAL - LINHAS BRANCA DE SELECIONAR OPCAO */

	if (fichario->selecao->grupo_selecionado == false) {
		for (int i = 0; i < 4; i++) {
			int y_subbox_button_option = y_subbox_button_option_initial +
				((y_subbox_size_button_option + espacemento_y_subbox_option_option) * i);

			int y_subbox_button_option_final = y_subbox_button_option + y_subbox_size_button_option;
			al_draw_filled_rectangle(x_subbox_button_option_initial, y_subbox_button_option, x_subbox_button_option_final, y_subbox_button_option_final, al_map_rgb(161, 127, 53));

			int y_subbox_option_text = y_subbox_button_option + (y_subbox_size_button_option / 4);
			al_draw_text(fichario->posicoes->subtitulo22, al_map_rgb(255, 255, 255), meio_subbox_options, y_subbox_option_text, ALLEGRO_ALIGN_CENTER, fichario->classe[i]->titulo);
		}
	}
	else {

			y_subbox_button_option_initial = y_subbox_button_option_initial + fichario->posicoes->espacamento_fichario_dentro;
			for (int i = 0; i < 3; i++) {
				int y_subbox_button_option = y_subbox_button_option_initial +
					((y_subbox_size_button_option + espacemento_y_subbox_option_option) * i);

				int y_subbox_button_option_final = y_subbox_button_option + y_subbox_size_button_option;
				al_draw_filled_rectangle(x_subbox_button_option_initial, y_subbox_button_option, x_subbox_button_option_final, y_subbox_button_option_final, al_map_rgb(161, 127, 53));

				int y_subbox_option_text = y_subbox_button_option + (y_subbox_size_button_option / 4);
				al_draw_text(fichario->posicoes->subtitulo22,
					al_map_rgb(255, 255, 255),
					meio_subbox_options,
					y_subbox_option_text,
					ALLEGRO_ALIGN_CENTER,
					fichario->classe[fichario->selecao->classe]->groupo[i]->titulo);

			}
			
			if (fichario->classe[fichario->selecao->classe]->groupo[fichario->selecao->grupo]->mostrar_opcoes) {
				desenhar_ajudante(fichario->classe[fichario->selecao->classe]->groupo[fichario->selecao->grupo]->ajudante);
			}

	}

}