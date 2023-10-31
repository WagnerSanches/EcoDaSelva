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

	/* INICIO CLASSIFICACAO */
	int x_box_size_tag = 224;
	int y_box_size_tag = fichario->posicoes->size_font_tag + 4;
	int espacamento_text_tag = 25;
	int espacamento_class_class = 20;

	int x_size_classification = PIXEL_SIZE * 10;
	int y_size_classification = PIXEL_SIZE  + (PIXEL_SIZE / 2) + (PIXEL_SIZE / 4);

	int x_box_class_title_initial = meio_subbox_info - (x_size_classification / 2);
	int y_box_class_title_final = fichario->posicoes->y_subbox_initial + fichario->posicoes->espacamento_fichario_dentro;

	int spacing = PIXEL_SIZE / 2;

	int x_size_box_response = PIXEL_SIZE * 8; 
	int y_size_box_response = fichario->posicoes->size_font_tag + (fichario->posicoes->size_font_tag / 2);


	ALLEGRO_COLOR cors[7] = {
		al_map_rgb(255, 174, 69),
		al_map_rgb(255, 240, 69),
		al_map_rgb(156, 255, 69),
		al_map_rgb(69, 255, 236),
		al_map_rgb(81, 69, 255),
		al_map_rgb(143, 69, 255),
		al_map_rgb(233, 69, 255)
	};
	
	char* textos[7] = {
		"Reino",
		"Filo",
		"Classe",
		"Ordem",
		"Familia",
		"Genero",
		"Especie"
	};

	for (int i = 0; i < 7; i++) {

		int y_classification_initial = y_box_class_title_final + (i * (spacing + y_size_classification));
		int x_classification_final = x_box_class_title_initial + x_size_classification;
		int y_classification_final = y_classification_initial + y_size_classification;

		al_draw_filled_rectangle(
			x_box_class_title_initial,
			y_classification_initial,
			x_classification_final,
			y_classification_final,
			cors[i]
		);

		int y_title_classification = y_classification_initial + y_size_box_response / 2;
		al_draw_text(
			fichario->posicoes->tag,
			al_map_rgb(255, 255, 255),
			meio_subbox_info,
			y_title_classification,
			ALLEGRO_ALIGN_CENTER,
			/*player->respostas[i]->grupo*/ textos[i]
		);


		int x_classification_response_initial = meio_subbox_info - (x_size_box_response / 2);
		int y_classification_response_initial = y_classification_final - y_size_box_response - (spacing / 2);
		int x_classification_response_final = x_classification_response_initial + x_size_box_response;
		int y_classification_response_final = y_classification_response_initial + y_size_box_response;

		al_draw_filled_rectangle(
			x_classification_response_initial,
			y_classification_response_initial,
			x_classification_response_final,
			y_classification_response_final,
			al_map_rgb(255, 255, 255)
		);

		int y_response = y_classification_response_initial + y_size_box_response / 4;

		al_draw_text(
			fichario->posicoes->tag,
			al_map_rgb(0, 0, 0),
			meio_subbox_info,
			y_response,
			ALLEGRO_ALIGN_CENTER,
			/*player->respostas[i]->grupo*/ "Nao classificado"
		);


	}
	
}