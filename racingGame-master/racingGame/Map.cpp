#include "Map.h"
#include "Drawer.h"

Drawer MapCreator;
ALLEGRO_BITMAP* Map::losuj_mape() //losowanie mapy ktora ma byc wczytana
{
	int a=0;
			a = rand() % BITMAP_COUNT;
			return map_list[a];
}


void Map::update_map() //wczytanie mapy
{

	for (int i = 0; i < BITMAP_COUNT; i++) {
		if (wys[i] >= RozY) {
			wys[i] = -RozY;
			cur_bitmaps[i] = losuj_mape();
		}
	}
}

void Map::init() //inizjaclowanie 
{
	for (int i = 0; i < BITMAP_COUNT; i++) {
		ALLEGRO_BITMAP* bitmap = MapCreator.create_bitmap(tab_map[i]);
		map_list.push_back(bitmap);
	}

	
	
}

void Map::tworz_mape() //tworzenie mapy
{
	init();
	int posY= 0;
	for (int i = 0; i < BITMAP_COUNT; i++) {
		cur_bitmaps[i] = losuj_mape();
		wys[i] = posY;
		posY += RozY;
	}
}
void Map::rysuj_mape() //rysowanie mapy
{
	for (int i = 0; i < BITMAP_COUNT; i++) {
		MapCreator.draw_bitmap(cur_bitmaps[i], 0, wys[i]);
	}
}

	void Map::przesuwaj_mape(int predkosc) //przesuwanie mapy (leci w dol)
	{
		update_map();
		for (int i = 0; i < BITMAP_COUNT; i++) {
			wys[i] += predkosc;
		}
	}

	
	