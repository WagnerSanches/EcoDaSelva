#include <PAUSA.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <config.h>

void desenhar_pausa(struct Pausa* pausa) {

	al_draw_filled_rectangle(
		0,
		0,
		WINDOW_SIZE_PIXEL_X * PIXEL_SIZE,
		WINDOW_SIZE_PIXEL_Y * PIXEL_SIZE,
		al_map_rgba_f(0, 0, 0, 0.5)
	);

	int meio_tela = (WINDOW_SIZE_PIXEL_X * PIXEL_SIZE) / 2;
	int size_pause = PIXEL_SIZE * 10;

	int valor_teste = PIXEL_SIZE * 7;

	int x_pause_initial = meio_tela - (size_pause / 2);
	int y_pause_initial = PIXEL_SIZE * 5;
	int x_pause_final = x_pause_initial + size_pause;
	int y_pause_final = y_pause_initial + valor_teste;

	al_draw_filled_rectangle(
		x_pause_initial,
		y_pause_initial,
		x_pause_final,
		y_pause_final,
		al_map_rgb(255, 255, 255)
	);

}