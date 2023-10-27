#include <FICHARIO.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

void init_fichario(struct Fichario* fichario) {
	fichario->status = FICHARIO_FECHADO;
}

void criar_fichario(struct Fichario* fichario) {

	for (int i = 0; i < NUMBER_OF_CLASSES; i++) {

		fichario->classe[i].titulo = (char*) malloc(sizeof(char) * 30);

		for (int j = 0; j < NUMBER_OF_GROUP_OF_CLASSES; j++) {
			fichario->classe[i].groupo[j].titulo = (char*)malloc(sizeof(char) * 30);
		
			if (fichario->classe[i].groupo[j].titulo == NULL) {
				printf("Falha na alocação de memória grupo titulo.\n");
				return 1;
			}
		}

		if (fichario->classe[i].titulo == NULL) {
			printf("Falha na alocação de memória classe titulo.\n");
			return 1;
		}
	}

	strcpy(fichario->classe[0].titulo, "Ordem");
	strcpy(fichario->classe[0].groupo[0].titulo, "Rodentia");
	strcpy(fichario->classe[0].groupo[1].titulo, "Carnivora");
	strcpy(fichario->classe[0].groupo[2].titulo, "Lepidoptera");

	strcpy(fichario->classe[1].titulo, "Familia");
	strcpy(fichario->classe[1].groupo[0].titulo, "Dendrobatidae");
	strcpy(fichario->classe[1].groupo[1].titulo, "Carcharhinidae");
	strcpy(fichario->classe[1].groupo[2].titulo, "Labridae");

	strcpy(fichario->classe[2].titulo, "Genero");
	strcpy(fichario->classe[2].groupo[0].titulo, "Phyllobates");
	strcpy(fichario->classe[2].groupo[1].titulo, "Rana");
	strcpy(fichario->classe[2].groupo[2].titulo, "Bufo");

	strcpy(fichario->classe[3].titulo, "Especie");
	strcpy(fichario->classe[3].groupo[0].titulo, "Phyllobates terribilis");
	strcpy(fichario->classe[3].groupo[1].titulo, "Phyllobates bicolor");
	strcpy(fichario->classe[3].groupo[2].titulo, "Ranitomeya variabilis");

	fichario->posicoes = malloc(sizeof(struct Posicoes_fichario_box));

	if (fichario->posicoes == NULL) {
		printf("Falha na alocação de memória posicoes.\n");
		return 1;
	}

	fichario->posicoes->titulo28 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 28, 0);
	fichario->posicoes->subtitulo22 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 22, 0);
	fichario->posicoes->descricao18 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 18, 0);
	fichario->posicoes->tag16 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 16, 0);
	fichario->selecao.classe = 0;
	fichario->selecao.grupo = 0;

	fichario->status = FICHARIO_ABERTO;
	fichario->selecao.grupo_selecionado = false;
}

void destruir_fichario(struct Fichario* fichario) {
	al_destroy_font(fichario->posicoes->titulo28);
	al_destroy_font(fichario->posicoes->subtitulo22);
	al_destroy_font(fichario->posicoes->descricao18);
	free(fichario->posicoes);

	for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
		free(fichario->classe[i].titulo);
	}

}