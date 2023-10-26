#include <AL_MAPA.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/drawing.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <FICHARIO.h>
#include <DESENHA_FICHARIO.h>
#include <PLAYER.h>

void desenhar_informacoes(struct Fichario* fichario, struct Player* player) {
	/*tamanho da tela: 1088*/

	/* SUBBOX INFO */
	int x_subbox_info_size = 352;
	int x_subbox_info_initial = fichario->posicoes->x_subbox_initial;
	fichario->posicoes->x_subbox_info_final = x_subbox_info_initial + x_subbox_info_size;
	int meio_subbox_info = x_subbox_info_initial + (fichario->posicoes->x_subbox_info_final - x_subbox_info_initial) / 2;
	//al_draw_filled_rectangle(x_subbox_info_initial, y_subbox_initial, fichario->posicoes->x_subbox_info_final, y_subbox_final, al_map_rgb(161, 53, 80));

	int box_size_image = 128;
	int x_box_image_initial = meio_subbox_info - (box_size_image / 2);
	//int x_box_image_initial = x_box_line_initial + espacamento_fichario_dentro;
	int x_box_image_final = x_box_image_initial + box_size_image;
	int y_box_image_initial = fichario->posicoes->y_subbox_initial + fichario->posicoes->espacamento_fichario_dentro * 2;
	int y_box_image_final = y_box_image_initial + box_size_image;
	al_draw_filled_rectangle(x_box_image_initial, y_box_image_initial, x_box_image_final, y_box_image_final, al_map_rgb(170, 170, 170));

	/* INICIO CLASSIFICACAO */
	int x_box_size_tag = 224;
	int y_box_size_tag = fichario->posicoes->size_font_tag + 4;
	int espacamento_text_tag = 25;
	int espacamento_class_class = 20;

	int x_box_class_title_initial = x_box_image_initial + box_size_image / 2;
	int y_box_class_title_final = y_box_image_final + fichario->posicoes->espacamento_fichario_dentro;

	for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
		int x_box_class_title = x_box_class_title_initial;
		int y_box_class_title = y_box_class_title_final + ((espacamento_class_class + y_box_size_tag + y_box_size_tag) * i);
		al_draw_text(
			fichario->posicoes->descricao18,
			al_map_rgb(145, 135, 86),
			x_box_class_title, y_box_class_title,
			ALLEGRO_ALIGN_CENTER,
			fichario->classe[i].titulo
		);

		int x_box_class_tag_initial = x_box_class_title - x_box_size_tag / 2;
		int y_box_class_tag_initial = y_box_class_title + espacamento_text_tag;
		int x_box_class_tag_final = x_box_class_tag_initial + x_box_size_tag;
		int y_box_class_tag_final = y_box_class_tag_initial + y_box_size_tag;

		// verificacao se o usuario ja nao colocou alguma classificacao
		int x_box_class_text = x_box_class_title;
		int y_box_class_text = y_box_class_title + espacamento_text_tag + (y_box_size_tag - fichario->posicoes->size_font_tag) / 4;
		
		if (player->respostas[i].selecionado) {
			al_draw_filled_rectangle(
				x_box_class_tag_initial,
				y_box_class_tag_initial,
				x_box_class_tag_final,
				y_box_class_tag_final,
				al_map_rgb(66, 135, 245)
			);

		} else {
			al_draw_filled_rectangle(
				x_box_class_tag_initial,
				y_box_class_tag_initial,
				x_box_class_tag_final,
				y_box_class_tag_final,
				al_map_rgb(170, 170, 170)
			);
		}
			
		al_draw_text(
			fichario->posicoes->tag16,
			al_map_rgb(255, 255, 255),
			x_box_class_text,
			y_box_class_text,
			ALLEGRO_ALIGN_CENTER,
			player->respostas[i].grupo);
	}
	
}