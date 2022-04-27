#include "Drawer.h"

ALLEGRO_BITMAP* Drawer::create_bitmap(string name) { //tworzenie bitmapy
	return al_load_bitmap(name.c_str());
}

void Drawer::draw_bitmap(ALLEGRO_BITMAP* bitmap,int x,int y) { //rysowanie bitmapy
	al_draw_bitmap(bitmap, x, y, 0);
}

void Drawer::delete_bitmap(ALLEGRO_BITMAP* bitmap) {	 //usuwanie bitmapy												
	al_destroy_bitmap(bitmap);
}