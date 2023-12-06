struct DialogoConfig {
	int font_size;// = 18;
	ALLEGRO_FONT* dialogue_font;// = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", font_size, 0);
	ALLEGRO_FONT* dialogue15;// = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", 15, 0);

	int dialogue_text_size;// = 18;
	ALLEGRO_FONT* dialogue16;// = al_load_font("assets/font/VCR_OSD_MONO_1.001.ttf", dialogue_text_size, 0);
	ALLEGRO_BITMAP* imagem_doutura;// = al_load_bitmap("assets/personagem/ajudante/doutora_resize.jpg");
};