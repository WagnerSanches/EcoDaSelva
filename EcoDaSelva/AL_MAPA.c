#include <allegro5/allegro5.h>
#include <AL_MAPA.h>
#include <MAPA.h>

void init_mapa(struct al_mapa* mapa) {
	mapa->NPC_IMAGES[0] = al_load_bitmap("assets/personagem/npc/Character_001.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("assets/personagem/npc/Character_002.png");
	mapa->NPC_IMAGES[2] = al_load_bitmap("assets/personagem/npc/Character_003.png");
	mapa->NPC_IMAGES[3] = al_load_bitmap("assets/personagem/npc/Character_004.png");
	mapa->NPC_IMAGES[4] = al_load_bitmap("assets/personagem/npc/Character_005.png");
	mapa->NPC_IMAGES[5] = al_load_bitmap("assets/personagem/npc/Character_006.png");
	mapa->NPC_IMAGES[6] = al_load_bitmap("assets/personagem/npc/Character_007.png");

	mapa->ITEM_IMAGES[0] = al_load_bitmap("assets/objeto/arvore/Tree2.png");

	carregar_mapa(mapa, 0);
}