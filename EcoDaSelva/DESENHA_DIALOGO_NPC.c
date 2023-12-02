#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <PLAYER.h>
#include <AL_MAPA.h>

void desenhar_caixa_dialogo(struct Player* player, struct al_mapa* mapa) {

	int font_size = 18;
	ALLEGRO_FONT* dialogue_font = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size, 0);

	al_draw_filled_rectangle(
		0,
		0,
		WINDOW_SIZE_PIXEL_X * PIXEL_SIZE,
		WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE,
		al_map_rgba_f(0, 0, 0, 0.5)
	);

	int indice_bot = player->indice_objeto_interacao;
	
	bool caixa_opcoes = mapa->npc[player->indice_objeto_interacao]->npc_quest 
		&& mapa->npc[player->indice_objeto_interacao]->dialogo_lido == 1
		&& player->missao->quest_aceita == false;

	int meio_tela = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2;

	int dialogue_box_size = meio_tela;
	int inner_dialogue_spacing = PIXEL_SIZE;

	int x_dialogue_box_initial = meio_tela - (dialogue_box_size / 2);
	int y_dialogue_box_initial = PIXEL_SIZE * 3;
	int x_dialogue_box_final = x_dialogue_box_initial + dialogue_box_size;

	
	int spacing_between_text = font_size + 6;

	int spacing = 4;
	if (caixa_opcoes)
		spacing = 6;

	char* texto = mapa->npc[indice_bot]->
				dialogo[mapa->npc[indice_bot]->dialogo_lido]->texto;
	
	if (player->missao->indice_npc_guest_aceita == player->indice_objeto_interacao
		&& mapa->npc[player->indice_objeto_interacao]->npc_quest
		&& mapa->npc[player->indice_objeto_interacao]->quest_terminada == false) {
		strcpy(texto, "Obrigado por estar me ajudando, termine minha tarefa que te darei uma informacao.");
	}
	else if (mapa->npc[player->indice_objeto_interacao]->npc_quest
		&& player->missao->quest_aceita
		&& mapa->npc[player->indice_objeto_interacao]->quest_terminada == false) {
		strcpy(texto, "Quando terminar sua tarefa venha falar comigo.");
	}

	int size_by_text = (strlen(texto) / 40);

	if (size_by_text < 1)
		size_by_text = 2;

	int y_dialogue_box_final = y_dialogue_box_initial
		+ spacing_between_text * size_by_text
		+ inner_dialogue_spacing * spacing;

	al_draw_filled_rectangle(
		x_dialogue_box_initial,
		y_dialogue_box_initial,
		x_dialogue_box_final,
		y_dialogue_box_final,
		al_map_rgb(255, 255, 255)
	);

	int size_dialogue_box_name = PIXEL_SIZE * 6;

	int x_dialogue_box_name_initial = x_dialogue_box_initial + inner_dialogue_spacing - PIXEL_SIZE / 2;
	int y_dialogue_box_name_initial = y_dialogue_box_initial - PIXEL_SIZE / 4;
	int x_dialogue_box_name_final = x_dialogue_box_name_initial + size_dialogue_box_name;
	int y_dialogue_box_name_final = y_dialogue_box_name_initial + 8 + font_size;

	al_draw_filled_rectangle(
		x_dialogue_box_name_initial,
		y_dialogue_box_name_initial,
		x_dialogue_box_name_final,
		y_dialogue_box_name_final,
		al_map_rgb(181, 102, 27)
	);

	int x_dialogue_name = x_dialogue_box_name_initial + size_dialogue_box_name / 2;
	int y_dialogue_name = y_dialogue_box_name_initial + 4;

	al_draw_text(
		dialogue_font,
		al_map_rgb(255, 255, 255),
		x_dialogue_name,
		y_dialogue_name,
		ALLEGRO_ALIGN_CENTER,
		mapa->npc[indice_bot]->nome
	);

	int x_dialogue_box_tag_initial = x_dialogue_box_name_final + PIXEL_SIZE;
	int x_dialogue_box_tag_final = x_dialogue_box_tag_initial + (size_dialogue_box_name / 2);

	al_draw_filled_rectangle( 
		x_dialogue_box_tag_initial, 
		y_dialogue_box_name_initial, 
		x_dialogue_box_tag_final, 
		y_dialogue_box_name_final, 
		al_map_rgb(109, 50, 168)
	);

	int x_dialogue_tag = x_dialogue_box_tag_initial + (size_dialogue_box_name / 2) / 2;

	al_draw_text(
		dialogue_font,
		al_map_rgb(255, 255, 255), 
		x_dialogue_tag,
		y_dialogue_name, 
		ALLEGRO_ALIGN_CENTER, 
		mapa->npc[indice_bot]->tag
	); 

	int x_dialogue_text = x_dialogue_box_initial + inner_dialogue_spacing * 2;
	int y_dialogue_text = y_dialogue_box_initial + inner_dialogue_spacing + 16;
	int x_dialogue_text_final = dialogue_box_size - inner_dialogue_spacing * 4;

	al_draw_multiline_text(
		dialogue_font,
		al_map_rgb(0, 0, 0),
		x_dialogue_text,
		y_dialogue_text,
		x_dialogue_text_final,
		spacing_between_text,
		0,
		texto
	);

	int image_dialogue_size = PIXEL_SIZE * 4;

	int x_image_dialogue_initial = x_dialogue_box_final - (image_dialogue_size / 2);
	int y_image_dialogue_initial = y_dialogue_box_initial + PIXEL_SIZE / 2;

	al_draw_bitmap(
		mapa->npc[indice_bot]->foto,
		x_image_dialogue_initial,
		y_image_dialogue_initial,
		0
	);

	if (caixa_opcoes) {

		int selecionado = mapa->npc[player->indice_objeto_interacao]->dialogo[mapa->npc[player->indice_objeto_interacao]->dialogo_lido]->opcao_selecionada;

		int raio = font_size / 2;
		int x_press_key_circle = x_dialogue_box_initial + inner_dialogue_spacing * 2;
		int y_press_key_circle = y_dialogue_box_final + raio - (inner_dialogue_spacing * 3);
		al_draw_filled_circle(
			x_press_key_circle,
			y_press_key_circle + 1,
			raio,
			selecionado == 0 ? al_map_rgb(255, 161, 0) : al_map_rgb(220, 220, 220)
		);

		int x_press_key_text = x_press_key_circle + font_size;
		int y_press_key_text = y_press_key_circle - raio;
		al_draw_text(
			dialogue_font,
			selecionado == 0 ? al_map_rgb(255, 161, 0) : al_map_rgb(220, 220, 220),
			x_press_key_text,
			y_press_key_text,
			0,
			"Eu adoraria!"
		);

		int y_press_key_circle_2 = y_press_key_circle + font_size * 2;
		al_draw_filled_circle(
			x_press_key_circle,
			y_press_key_circle_2,
			raio,
			selecionado == 1 ? al_map_rgb(255, 161, 0) : al_map_rgb(220, 220, 220)
		);

		int y_press_key_text_2 = y_press_key_circle_2 - raio;
		al_draw_text(
			dialogue_font,
			selecionado == 1 ? al_map_rgb(255, 161, 0) : al_map_rgb(220, 220, 220),
			x_press_key_text,
			y_press_key_text_2,
			0,
			"No momento eu nao consigo."
		);
	} else {
		int y_press_key = y_dialogue_box_final - spacing_between_text - PIXEL_SIZE / 2;
		al_draw_text(
			dialogue_font,
			al_map_rgb(200, 200, 200),
			meio_tela,
			y_press_key,
			ALLEGRO_ALIGN_CENTER,
			"Aperte 'espaco' para continuar"
		);

	}

	al_destroy_font(dialogue_font);
}