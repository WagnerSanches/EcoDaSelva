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

	fichario->todas_respostas_selecionadas = false;
	fichario->opcao_finalizar_jogo = false;
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


	fichario->posicoes->espacamento_fichario_fora = (PIXEL_SIZE * 2);
	fichario->posicoes->espacamento_fichario_dentro = PIXEL_SIZE;
	fichario->posicoes->size_font_titulo = 24;
	fichario->posicoes->size_font_subtitulo = 20;
	fichario->posicoes->size_font_description = 18;
	fichario->posicoes->size_font_tag = 16;

	fichario->posicoes->titulo = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", fichario->posicoes->size_font_titulo, 0);
	fichario->posicoes->subtitulo = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", fichario->posicoes->size_font_subtitulo, 0);
	fichario->posicoes->descricao = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", fichario->posicoes->size_font_description, 0);
	fichario->posicoes->tag = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", fichario->posicoes->size_font_tag, 0);

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
	strcpy(fichario->classe[0]->groupo[1]->titulo, "Anura");
	strcpy(
		fichario->classe[0]->groupo[1]->ajudante->texto,
		"A ordem Anura e representada pelos anfibios sem cauda: sapos, ras e pererecas. Apresentam o corpo adaptado para saltar.O corpo e compacto, com coluna vertebral curta e rigida; as vertebras estao ligadas de modo a restringir movimentos laterais."
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
		"Os membros deste grupo tem a particularidade de produzirem toxinas potentes que se encontram na sua pele, mais de 100 toxinas foram ja identificadas nas secrecoes cutaneas de membros deste grupo."
	);
	strcpy(fichario->classe[1]->groupo[1]->titulo, "Carcharhinidae");
	strcpy(
		fichario->classe[1]->groupo[1]->ajudante->texto,
		"Carcharhinidae e uma familia de tubaroes da ordem Carcharhiniformes, Os membros desta familia possuem as caracteristicas usuais dos carcariniformes. Os olhos sao redondos, as barbatanas peitorais localizam-se totalmente atras das cinco fendas branquiais."
	);
	strcpy(fichario->classe[1]->groupo[2]->titulo, "Labridae");
	strcpy(
		fichario->classe[1]->groupo[2]->ajudante->texto,
		"A familia Labridae e marinha e ocorre nos oceanos Atlantico, Indico e Pacifico. E dominante na ictiofauna que vive associada a corais e comunidades de gramas marinhas, em regioes tropicais."
	);

	strcpy(fichario->classe[2]->titulo, "Genero");
	strcpy(fichario->classe[2]->groupo[0]->titulo, "Phyllobates");
	strcpy(
		fichario->classe[2]->groupo[0]->ajudante->texto,
		"Phyllobates tem uma coloracao marcante e intensa, exibindo tons vibrantes de amarelo ou laranja brilhante. Essa coloracao extraordinaria atua como um aviso visual para possiveis predadores, sinalizando que e um animal venenoso e perigoso. Eles sao um dos animais mais venenoso do planeta, possuindo toxinas suficientemente letais para ameacar varias vidas humanas."
	);
	
	strcpy(fichario->classe[2]->groupo[1]->titulo, "Rana");
	strcpy(
		fichario->classe[2]->groupo[1]->ajudante->texto,
		"Rana e um genero de anfibio anuro pertencente a familia Ranidae. Os representantes desta especie sao popularmente chamados ras,o genero Rana contem 239 especies."
	);

	strcpy(fichario->classe[2]->groupo[2]->titulo, "Bufo");
	strcpy(
		fichario->classe[2]->groupo[2]->ajudante->texto,
		"Bufo e um genero de sapos da familia Bufonidae, o abocanhamento ou ingestao de sapos pode causar problemas brandos a graves em caes e gatos."
	);

	strcpy(fichario->classe[3]->titulo, "Especie");
	strcpy(fichario->classe[3]->groupo[0]->titulo, "Phyllobates terribilis");
	strcpy(
		fichario->classe[3]->groupo[0]->ajudante->texto,
		"O sapo Phyllobates terribilis e considerado um dos animais mais toxicos da Terra. Um unico especime de cinco centimetros tem veneno suficiente para matar dez pessoas em idade adulta. O povo indigena embera, da Colombia, ha seculos utiliza o poderoso veneno em suas zarabatanas durante a caca."
	);

	strcpy(fichario->classe[3]->groupo[1]->titulo, "Phyllobates bicolor");
	strcpy(
		fichario->classe[3]->groupo[1]->ajudante->texto,
		"Phyllobates bicolor, ou mais comumente referido como sapo dardo venenoso de pernas pretas, e o segundo sapo dardo mais toxico do mundo. Sob o genero Phyllobates, este organismo e frequentemente confundido com Phyllobates terribilis, a ra venenosa dourada, pois ambos sao morfologicamente semelhantes."
	);

	strcpy(fichario->classe[3]->groupo[2]->titulo, "Ranitomeya variabilis");
	strcpy(
		fichario->classe[3]->groupo[2]->ajudante->texto,
		"Ranitomeya variabilis, anteriormente conhecido como Dendrodates variabilis, e uma especie de pequeno sapo venenoso distribuido no norte do Peru, ao longo da encosta leste dos Andes, na bacia de drenagem do alto Rio Huallaga. Seu nome comum e sapo venenoso de Zimmerman"
	);

	fichario->selecao->classe = 0;
	fichario->selecao->grupo = 0;

	fichario->status = FICHARIO_ABERTO;
	fichario->selecao->grupo_selecionado = false;
	fichario->ajudante->opcao = false;
	fichario->ajudante->opcao_selecionada = 0;
}

void destruir_fichario(struct Fichario* fichario) {
	free(fichario->selecao);

	al_destroy_font(fichario->posicoes->titulo);
	al_destroy_font(fichario->posicoes->subtitulo);
	al_destroy_font(fichario->posicoes->descricao);
	al_destroy_font(fichario->posicoes->tag);
	free(fichario->posicoes);

}