#include <FICHARIO.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

void init_fichario(struct Fichario* fichario) {
	fichario->status = FICHARIO_FECHADO;

	fichario->ajudante = malloc(sizeof(struct Ajudante));
	if (fichario->ajudante == NULL) {
		printf("Falha na alocação de memória classe ajudante.\n");
		return;
	}
	fichario->ajudante->texto = (char*)malloc(sizeof(char) * 600);
	if (fichario->ajudante->texto == NULL) {
		printf("Falha na alocação de memória classe descricao.\n");
		return;
	}
	fichario->ajudante->ajudou = false;
	fichario->ajudante->quantiade_imagem = 1;
	fichario->ajudante->image[0] = al_load_bitmap("assets/personagem/ajudante/informacoes/taxonomia.jpg");



	for (int i = 0; i < NUMBER_OF_CLASSES; i++) {

		fichario->classe[i] = malloc(sizeof(struct Classe));
		if (fichario->classe[i] == NULL) {
			printf("Falha na alocação de memória classe.\n");
			return;
		}

		fichario->classe[i]->titulo = (char*)malloc(sizeof(char) * 30);
		if (fichario->classe[i]->titulo == NULL) {
			printf("Falha na alocação de memória classe titulo.\n");
			return;
		}

		for (int j = 0; j < NUMBER_OF_GROUP_OF_CLASSES; j++) {

			fichario->classe[i]->groupo[j] = malloc(sizeof(struct Group));
			if (fichario->classe[i]->groupo[j] == NULL) {
				printf("Falha na alocação de memória classe groupo.\n");
				return 1;
			}
			fichario->classe[i]->groupo[j]->mostrar_opcoes = false;

			fichario->classe[i]->groupo[j]->titulo = (char*)malloc(sizeof(char) * 30);
			if (fichario->classe[i]->groupo[j]->titulo == NULL) {
				printf("Falha na alocação de memória classe grupo titulo.\n");
				return 1;
			}

			fichario->classe[i]->groupo[j]->ajudante = malloc(sizeof(struct Ajudante));
			if (fichario->classe[i]->groupo[j]->ajudante == NULL) {
				printf("Falha na alocação de memória classe ajudante.\n");
				return;
			}
			fichario->classe[i]->groupo[j]->ajudante->texto = (char*)malloc(sizeof(char) * 600);
			if (fichario->classe[i]->groupo[j]->ajudante->texto == NULL) {
				printf("Falha na alocação de memória classe descricao.\n");
				return;
			}

			fichario->classe[i]->groupo[j]->ajudante->tipo_pergunta = PERGUNTA_INFORMACAO;
			fichario->classe[i]->groupo[j]->ajudante->opcao = true;
			fichario->classe[i]->groupo[j]->ajudante->opcao_selecionada = 0;
		}
	}
}

void criar_fichario(struct Fichario* fichario) {


	fichario->posicoes = malloc(sizeof(struct Posicoes_fichario_box));
	if (fichario->posicoes == NULL) {
		printf("Falha na alocação de memória posicoes.\n");
		return 1;
	}

	fichario->selecao = malloc(sizeof(struct Selecao));
	if (fichario->selecao == NULL) {
		printf("Falha na alocação de memória selecao.\n");
		return 1;
	}

	fichario->posicoes->titulo28 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 28, 0);
	fichario->posicoes->subtitulo22 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 22, 0);
	fichario->posicoes->descricao18 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 18, 0);
	fichario->posicoes->tag16 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 16, 0);

	strcpy(
		fichario->ajudante->texto,
		"A taxonomia e a ciencia que classifica e organiza seres vivos em grupos com base em caracteristicas compartilhadas, incluindo reino, filo, classe, ordem, familia, genero e especie, para entender suas relacoes e diversidade. Em biologia, esses sao os principais niveis de classificacao, usados na taxonomia. Essa hierarquia taxonomica ajuda a organizar a diversidade da vida em grupos com base em suas caracteristicas compartilhadas e relacoes evolutivas."
	);

	strcpy(fichario->classe[0]->titulo, "Ordem");
	strcpy(fichario->classe[0]->groupo[0]->titulo, "Rodentia");
	strcpy(
		fichario->classe[0]->groupo[0]->ajudante->texto, 
		"Rodentia e a ordem de mamiferos caracterizada por animais com incisivos afiados em constante crescimento, incluindo ratos, esquilos e porquinhos-da-india. Eles sao encontrados em todo o mundo e tem um papel ecologico significativo."
	);
	strcpy(fichario->classe[0]->groupo[1]->titulo, "Carnivora");
	strcpy(
		fichario->classe[0]->groupo[1]->ajudante->texto,
		"Carnivora e a ordem de mamiferos que inclui uma variedade de animais carnivoros, como leoes, tigres, lobos e ursos. Eles sao conhecidos por seus dentes afiados e adaptacoes para a caca. Os carnivoros sao encontrados em varias partes do mundo e desempenham papeis importantes nos ecossistemas como predadores."
	);
	strcpy(fichario->classe[0]->groupo[2]->titulo, "Lepidoptera");
	strcpy(
		fichario->classe[0]->groupo[2]->ajudante->texto,
		"Lepidoptera e a ordem de insetos que inclui borboletas e mariposas, conhecidos por suas asas com escamas e por passar por metamorfose completa.Eles sao importantes polinizadores e sao encontrados em habitats variados ao redor do mundo."
	);

	strcpy(fichario->classe[1]->titulo, "Familia");
	strcpy(fichario->classe[1]->groupo[0]->titulo, "Dendrobatidae");
	strcpy(
		fichario->classe[1]->groupo[0]->ajudante->texto,
		"Rodentia e a ordem de mamiferos caracterizada por animais com incisivos afiados em constante crescimento, incluindo ratos, esquilos e porquinhos-da-india. Eles sao encontrados em todo o mundo e tem um papel ecologico significativo."
	);
	strcpy(fichario->classe[1]->groupo[1]->titulo, "Carcharhinidae");
	strcpy(
		fichario->classe[1]->groupo[1]->ajudante->texto,
		"Rodentia e a ordem de mamiferos caracterizada por animais com incisivos afiados em constante crescimento, incluindo ratos, esquilos e porquinhos-da-india. Eles sao encontrados em todo o mundo e tem um papel ecologico significativo."
	);
	strcpy(fichario->classe[1]->groupo[2]->titulo, "Labridae");
	strcpy(
		fichario->classe[1]->groupo[2]->ajudante->texto,
		"Rodentia e a ordem de mamiferos caracterizada por animais com incisivos afiados em constante crescimento, incluindo ratos, esquilos e porquinhos-da-india. Eles sao encontrados em todo o mundo e tem um papel ecologico significativo."
	);

	strcpy(fichario->classe[2]->titulo, "Genero");
	strcpy(fichario->classe[2]->groupo[0]->titulo, "Phyllobates");
	strcpy(fichario->classe[2]->groupo[1]->titulo, "Rana");
	strcpy(fichario->classe[2]->groupo[2]->titulo, "Bufo");

	strcpy(fichario->classe[3]->titulo, "Especie");
	strcpy(fichario->classe[3]->groupo[0]->titulo, "Phyllobates terribilis");
	strcpy(fichario->classe[3]->groupo[1]->titulo, "Phyllobates bicolor");
	strcpy(fichario->classe[3]->groupo[2]->titulo, "Ranitomeya variabilis");

	fichario->selecao->classe = 0;
	fichario->selecao->grupo = 0;

	fichario->status = FICHARIO_ABERTO;
	fichario->selecao->grupo_selecionado = false;
	fichario->ajudante->opcao = false;
	fichario->ajudante->opcao_selecionada = 0;
}

void destruir_fichario(struct Fichario* fichario) {
	free(fichario->selecao);

	al_destroy_font(fichario->posicoes->titulo28);
	al_destroy_font(fichario->posicoes->subtitulo22);
	al_destroy_font(fichario->posicoes->descricao18);
	al_destroy_font(fichario->posicoes->tag16);
	free(fichario->posicoes);

}