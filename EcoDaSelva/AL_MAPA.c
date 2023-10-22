#include <allegro5/allegro5.h>
#include <AL_MAPA.h>
#include <MAPA.h>

void init_mapa(struct al_mapa* mapa) {
	mapa->NPC_IMAGES[0] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_001.png");
	mapa->NPC_IMAGES[1] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_002.png");
	mapa->NPC_IMAGES[2] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_003.png");
	mapa->NPC_IMAGES[3] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_004.png");
	mapa->NPC_IMAGES[4] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_005.png");
	mapa->NPC_IMAGES[5] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_006.png");
	mapa->NPC_IMAGES[6] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\walk\\16x16\\Character_007.png");

	mapa->ITEM_IMAGES[0] = al_load_bitmap("C:\\Users\\wagne\\OneDrive\\Documents\\tiled maps\\trees\\Assets_separately\\Trees\\Tree2.png");

	carregar_mapa(mapa, 0);
}