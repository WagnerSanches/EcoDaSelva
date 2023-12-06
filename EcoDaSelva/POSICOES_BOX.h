#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>

#ifndef POSICOES_BOX_H
#define POSICOES_BOX_H

struct Posicoes_fichario_box {

	struct ALLEGRO_FONT* titulo;
	struct ALLEGRO_FONT* subtitulo;
	struct ALLEGRO_FONT* descricao;
	struct ALLEGRO_FONT* tag;

	int espacamento_fichario_fora;
	int espacamento_fichario_dentro;
	int size_font_titulo;
	int size_font_subtitulo;
	int size_font_description;
	int size_font_tag;

	int x_subbox_initial;
	int y_subbox_initial;
	int x_subbox_final;
	int y_subbox_final;

	int x_subbox_info_final;

	ALLEGRO_FONT* font;
	ALLEGRO_BITMAP* arrow;

	ALLEGRO_BITMAP* animal;
	ALLEGRO_BITMAP* resize;

};

#endif