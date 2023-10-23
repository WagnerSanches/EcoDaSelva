#include <FICHARIO.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <FICHARIO_STATUS.h>

void init_fichario(struct Fichario* fichario) {
	fichario->status = FICHARIO_FECHADO;
}

void criar_fichario(struct Fichario* fichario) {

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++) {
		fichario->animal[i].nome = (char*)malloc(sizeof(char) * 50);

		if (fichario->animal[i].nome == NULL) {
			printf("Falha na alocação de memória para Pessoa.\n");
			return 1;
		}
	}

	strcpy(fichario->animal[0].nome, "Macaco aranha");
	strcpy(fichario->animal[1].nome, "Harpia real");
	strcpy(fichario->animal[2].nome, "Sapo boi");

	fichario->titulo28 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 28, 0);
	fichario->subtitulo22 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 22, 0);
	fichario->descricao18 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 18, 0);
	fichario->animal_selecionado = 0;

	fichario->status = FICHARIO_ABERTO;
}

void destruir_fichario(struct Fichario* fichario) {
	al_destroy_font(fichario->titulo28);
	al_destroy_font(fichario->subtitulo22);
	al_destroy_font(fichario->descricao18);

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++) {
		free(fichario->animal[i].nome);
	}
}