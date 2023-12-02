#include <allegro5/allegro5.h>
#include <AL_MAPA.h>
#include <AJUDANTE.h>
#include <MAPA_PRAIA.h>
#include <MAPA_ESQUERDA_PRAIA.h>
#include <MAPA_DIREITA_PRAIA.h>
#include <MAPA_VILA.h>
#include <MAPA_DIREITA_VILA.h>
#include <MAPA_ESQUERDA_VILA.h>
#include <MAPA_FLORESTA_DESMATADA.h>
#include <MAPA_ESQUERDA_FLORESTA_DESMATADA.h>
#include <MAPA_DIREITA_FLORESTA_DESMATADA.h>
#include <PLAYER.h>

void init_mapa(struct al_mapa* mapa) {
	int praia = 7;
	mapa->criado = false;

	carregar_mapa(mapa, praia);
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
		printf("Falha na alocação de memória npc interacao.\n");
		return 1;
	}

	mapa->next_mapa = malloc(sizeof(struct al_next_mapa));
	if (mapa->next_mapa == NULL) {
		printf("Falha na alocação de memória next mapa.\n");
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
			printf("Falha na alocação de memória npc.\n");
			return -1;
		}

		mapa->npc[i]->nome = (char*)malloc(sizeof(char) * 30);
		if (mapa->npc[i]->nome == NULL) {
			printf("Falha na alocação de memória npc nome.\n");
			return -1;
		}

		mapa->npc[i]->nome_item_quest = (char*)malloc(sizeof(char) * 30);
		if (mapa->npc[i]->nome_item_quest == NULL) {
			printf("Falha na alocação de memória npc nome_item_quest.\n");
			return -1;
		}

		mapa->npc[i]->tag = (char*)malloc(sizeof(char) * 15);
		if (mapa->npc[i]->tag == NULL) {
			printf("Falha na alocação de memória npc tag.\n");
			return -1;
		}

		for (int j = 0; j < 3; j++) {
			mapa->npc[i]->dialogo[j] = malloc(sizeof(struct Dialogo));
			if (mapa->npc[i]->dialogo[j] == NULL) {
				printf("Falha na alocação de memória dialogo.\n");
				return -1;
			}

			mapa->npc[i]->dialogo[j]->texto = (char*)malloc(sizeof(char) * 600);
			if (mapa->npc[i]->dialogo[j]->texto == NULL) {
				printf("Falha na alocação de memória dialogo texto.\n");
				return -1;
			}

			mapa->npc[i]->quest_terminada = false;
			mapa->npc[i]->dialogo[j]->opcao_selecionada = 0;
			mapa->npc[i]->npc_quest = false;
		}

	}

	for (int i = 0; i < MAX_ITEM_PER_MAP; i++) {
		mapa->item[i] = malloc(sizeof(struct Item));
		if (mapa->item[i] == NULL) {
			printf("Falha na alocação de memória item.\n");
			return -1;
		}

		mapa->item[i]->nome = (char*) malloc(sizeof(char) * 30);
		if (mapa->item[i]->nome == NULL) {
			printf("Falha na alocação de memória item.\n");
			return -1;
		}

		mapa->item[i]->item_pegado = false;

		mapa->item[i]->ajudante = malloc(sizeof(struct Ajudante));
		if (mapa->item[i]->ajudante == NULL) {
			printf("Falha na alocação de memória ajudante.\n");
			return 1;
		}

		mapa->item[i]->ajudante->texto = (char*)malloc(sizeof(char) * 600);
		if (mapa->item[i]->ajudante->texto == NULL) {
			printf("Falha na alocação de memória ajudante texto.\n");
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
		carregar_mapa_esquerda_floresta_desmatada(mapa);
		break;
	case 1:
		carregar_mapa_floresta_desmatada(mapa);
		break;
	case 2:
		carregar_mapa_direita_floresta_desmatada(mapa);
		break;
	case 3:
		carregar_mapa_esquerda_vila(mapa);
		break;
	case 4:
		carregar_mapa_vila(mapa);
		break;
	case 5:
		carregar_mapa_direita_vila(mapa);
		break;
	case 6:
		carregar_mapa_esquerda_praia(mapa); 
		break;
	case 7:
		carregar_mapa_praia(mapa); 
		break;
	case 8:
		carregar_mapa_direita_praia(mapa);
		break;
	}
}

void validar_mapa(struct Player* player, struct al_mapa* mapa) {

	for (int i = 0; i < mapa->quantidade_item; i++) {
		if (mapa->item[i]->item_missao) {
			for (int j = 0; j < player->quantidade_itens_pegados; j++) {
				if (strcmp(player->itens_pegados[j], mapa->item[i]->nome) == 0) {
					mapa->item[i]->item_pegado = true;
					mapa->item[i]->ajudante->opcao = false;
					mapa->matriz[mapa->item[i]->matriz_position_y ][mapa->item[i]->matriz_position_x] = 0;
				}
			}
		}
	}

	printf("player->missao->quantiade_missoes_concluidas = %d\n\n", player->missao->quantidade_missoes_concluidas);
	for (int i = 0; i < mapa->quantidade_npc; i++) {
		for (int j = 0; j < player->missao->quantidade_missoes_concluidas; j++) {
			if (strcmp(player->missao->missoes_concluidas[j], mapa->npc[i]->nome_item_quest) == 0) {
				mapa->npc[i]->quest_terminada = true;
				mapa->npc[i]->dialogo_lido = 2;
			}
		}
	}

}