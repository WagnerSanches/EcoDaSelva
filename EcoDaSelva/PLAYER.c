#include <PLAYER.h>
#include <config.h>
#include <allegro5/allegro.h>
#include <string.h>
#include <AJUDANTE.h>

void init_player(struct Player* player) {

	ALLEGRO_BITMAP* walk = al_load_bitmap("assets/personagem/player/Character_007.png");

	player->animation[0][0] = al_create_sub_bitmap(walk, 4, 24 * 3 + 7, 16, 16);
	player->animation[0][1] = al_create_sub_bitmap(walk, 24 + 4, 24 * 3 + 7, 16, 16);
	player->animation[0][2] = al_create_sub_bitmap(walk, 4 + (24 * 2), 24 * 3 + 7, 16, 16);
	player->animation[0][3] = al_create_sub_bitmap(walk, 24 * 3 + 4, 24 * 3 + 7, 16, 16);

	player->animation[1][0] = al_create_sub_bitmap(walk, 4, 7, 16, 16);
	player->animation[1][1] = al_create_sub_bitmap(walk, 24 + 4, 7, 16, 16);
	player->animation[1][2] = al_create_sub_bitmap(walk, 24 * 2 + 4, 7, 16, 16);
	player->animation[1][3] = al_create_sub_bitmap(walk, 24 * 3 + 4, 7, 16, 16);

	player->animation[2][0] = al_create_sub_bitmap(walk, 4, 24 + 7, 16, 16);
	player->animation[2][1] = al_create_sub_bitmap(walk, 4 + 24, 24 + 7, 16, 16);
	player->animation[2][2] = al_create_sub_bitmap(walk, 4 + (24 * 2), 24 + 7, 16, 16);
	player->animation[2][3] = al_create_sub_bitmap(walk, 4 + (24 * 3), 24 + 7, 16, 16);

	player->animation[3][0] = al_create_sub_bitmap(walk, 4, 24 * 2 + 7, 16, 16);
	player->animation[3][1] = al_create_sub_bitmap(walk, 4 + 24, 24 * 2 + 7, 16, 16);
	player->animation[3][2] = al_create_sub_bitmap(walk, 4 + (24 * 2), 24 * 2 + 7, 16, 16);
	player->animation[3][3] = al_create_sub_bitmap(walk, 4 + (24 * 3), 24 * 2 + 7, 16, 16);

	for (int i = 0; i < NUMBER_OF_CLASSES; i++) {

		player->respostas[i] = malloc(sizeof(struct Resposta));
		if (player->respostas[i] == NULL) {
			printf("Falha na alocação de memória resposta.\n");
			return 1;
		}

		player->respostas[i]->grupo = (char*)malloc(sizeof(char) * 30);
		if (player->respostas[i]->grupo == NULL) {
			printf("Falha na alocação de memória resposta grupo.\n");
			return 1;
		}

		strcpy(player->respostas[i]->grupo, "Nao classificado");

		player->respostas[i]->selecionado = false;
	}

	player->missao = malloc(sizeof(struct Mission));
	if (player->missao == NULL) {
		printf("Falha na alocação de memória quest.\n");
		return 1;
	}

	player->ajudante = malloc(sizeof(struct Ajudante));
	if (player->ajudante == NULL) {
		printf("Falha na alocação de memória ajudante.\n");
		return 1;
	}

	player->ajudante->texto = (char*) malloc(sizeof(char) * 600);
	if (player->ajudante->texto == NULL) {
		printf("Falha na alocação de memória ajudante texto.\n");
		return 1;
	}


	player->matriz_position_x = 12;
	player->matriz_position_y = 7;

	player->map_position_x = player->matriz_position_x * PIXEL_SIZE;
	player->map_position_y = player->matriz_position_y * PIXEL_SIZE;

	player->status = PARADO;

	player->sum_x_pixel = 0;
	player->sum_y_pixel = 0;

	player->image = player->animation[1][0];
	player->direcao = 2;
	player->animation_next_image = 0;

	player->pressing_key = false;
	player->pressing_multiple_key = false;
	player->missao->quest_aceita = false;
	player->missao->concluida = false;

	player->ajudante->ajudou = false;
	strcpy(player->ajudante->texto, "Ola aventureiro! Seja bemvindo a Oiapoque Voce deve estar estranhando o clima quente mas logo se acostuma Irei te ajudar durante sua pesquisa aqui na vila, soube que esta em busca de informacoes sobre a fauna entao por que nao se enturmar e aprender um pouco com os moradores do vilarejo. Talvez eles tenham informacoes que possam te ajudar.");

	player->velocidade = 2;
}