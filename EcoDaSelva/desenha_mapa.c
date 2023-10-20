#include <config.h>
#include <stdlib.h>
#include <AL_MAPA.h>

void montar_mapa(struct al_mapa* mapas[]) {
	for (int i = 0; i < 4; i++) {
		mapas[i] = (struct al_mapa*)malloc(sizeof(struct al_mapa));

		if (mapas[i] == NULL) {
			printf("Erro na alocação de memória.\n");
			exit(1);
		}

		
	}

}