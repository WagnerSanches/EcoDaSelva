#include <allegro5/allegro5.h>
#include <AL_MAPA.h>
#include <AJUDANTE.h>
#include <MAPA_CENTRO.h>

void init_mapa(struct al_mapa* mapa) {
	mapa->criado = false;
	mapa->dialogue16 = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 16, 0);

	carregar_mapa(mapa, 0);
}

void excluir_mapa(struct al_mapa* mapa) {
	if (mapa->criado) {
		al_destroy_bitmap(mapa->background);

		free(mapa->next_mapa);

		for (int i = 0; i < mapa->quantidade_npc; i++) {
			al_destroy_bitmap(mapa->NPC_IMAGES[i]);

			al_destroy_bitmap(mapa->npc[i]->image[0]);
			al_destroy_bitmap(mapa->npc[i]->image[1]);
			al_destroy_bitmap(mapa->npc[i]->image[2]);
			al_destroy_bitmap(mapa->npc[i]->image[3]);

			al_destroy_bitmap(mapa->npc[i]->foto);

			if (mapa->npc[i]->npc_quest == false) {
				free(mapa->npc[i]->dialogo[0]->texto);
				free(mapa->npc[i]->nome);
				free(mapa->npc[i]);
			}

		}

		// excluir os items
		for (int i = 0; i < mapa->quantidade_item; i++) {
			al_destroy_bitmap(mapa->item[i]->image);
			free(mapa->item[i]);
		}

		mapa->criado = false;
	}
}

void criar_mapa(struct al_mapa* mapa) {
	for (int k = 0; k < WINDOW_SIZE_PIXEL_Y; k++) {
		for (int j = 0; j < WINDOW_SIZE_PIXEL_X; j++) {
			mapa->matriz[k][j] = 0;
		}
	}

	mapa->objeto_interacao = malloc(sizeof(struct OBJETO_INTERACAO));
	if (mapa->objeto_interacao == NULL) {
		printf("Falha na aloca��o de mem�ria npc interacao.\n");
		return 1;
	}

	mapa->next_mapa = malloc(sizeof(struct al_next_mapa));
	if (mapa->next_mapa == NULL) {
		printf("Falha na aloca��o de mem�ria next mapa.\n");
		return 1;
	}

	mapa->next_mapa->pra_cima = 0;
	mapa->next_mapa->pra_baixo = 0;
	mapa->next_mapa->pra_esquerda = 0;
	mapa->next_mapa->pra_direita = 0;
	mapa->objeto_interacao->matriz_position_x = 0;
	mapa->objeto_interacao->matriz_position_y = 0;
	mapa->quantidade_item = 0;
	mapa->quantidade_npc = 0;

	for (int i = 0; i < MAX_NPC_PER_MAP; i++) {
		mapa->npc[i] = malloc(sizeof(struct NPC));

		if (mapa->npc[i] == NULL) {
			printf("Falha na aloca��o de mem�ria npc.\n");
			return -1;
		}

		mapa->npc[i]->nome = (char*)malloc(sizeof(char) * 30);
		if (mapa->npc[i]->nome == NULL) {
			printf("Falha na aloca��o de mem�ria npc nome.\n");
			return -1;
		}

		mapa->npc[i]->nome_item_quest = (char*)malloc(sizeof(char) * 30);
		if (mapa->npc[i]->nome_item_quest == NULL) {
			printf("Falha na aloca��o de mem�ria npc nome_item_quest.\n");
			return -1;
		}

		for (int j = 0; j < 3; j++) {
			mapa->npc[i]->dialogo[j] = malloc(sizeof(struct Dialogo));
			if (mapa->npc[i]->dialogo[j] == NULL) {
				printf("Falha na aloca��o de mem�ria dialogo.\n");
				return -1;
			}

			mapa->npc[i]->dialogo[j]->texto = (char*)malloc(sizeof(char) * 600);
			if (mapa->npc[i]->dialogo[j]->texto == NULL) {
				printf("Falha na aloca��o de mem�ria dialogo texto.\n");
				return -1;
			}

			mapa->npc[i]->quest_terminada = false;
			mapa->npc[i]->dialogo[j]->opcao_selecionada = 0;
		}

	}

	for (int i = 0; i < MAX_ITEM_PER_MAP; i++) {
		mapa->item[i] = malloc(sizeof(struct Item));
		if (mapa->item[i] == NULL) {
			printf("Falha na aloca��o de mem�ria item.\n");
			return -1;
		}

		mapa->item[i]->nome = (char*) malloc(sizeof(char) * 30);
		if (mapa->item[i]->nome == NULL) {
			printf("Falha na aloca��o de mem�ria item.\n");
			return -1;
		}

		mapa->item[i]->item_pegado = false;

		mapa->item[i]->ajudante = malloc(sizeof(struct Ajudante));
		if (mapa->item[i]->ajudante == NULL) {
			printf("Falha na aloca��o de mem�ria ajudante.\n");
			return 1;
		}

		mapa->item[i]->ajudante->texto = (char*)malloc(sizeof(char) * 600);
		if (mapa->item[i]->ajudante->texto == NULL) {
			printf("Falha na aloca��o de mem�ria ajudante texto.\n");
			return 1;
		}

	}

	mapa->quantidade_npc = 0;
	mapa->quantidade_item = 0;
	mapa->criado = true;
}

void carregar_mapa(struct al_mapa* mapa, int next_mapa) {

	excluir_mapa(mapa);
	criar_mapa(mapa);

	switch (next_mapa) {
	case 0:
		carregar_mapa_centro(mapa);
		break;
	case 1:
		carregar_mapa_centro_cima(mapa);
		break;
	case 2:
		carregar_mapa_centro_baixo(mapa);
		break;
	case 3:
		carregar_mapa_centro_esquerda(mapa);
		break;
	case 4:
		carregar_mapa_centro_direita(mapa);
		break;
	}
}