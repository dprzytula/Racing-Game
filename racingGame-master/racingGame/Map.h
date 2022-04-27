#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <ctime>
#include <list>
#include <vector>
#include <allegro5/allegro_primitives.h>
#include "Engine.h"
#include "Drawer.h"
#define BITMAP_COUNT 3
using namespace std;
class Map {
public:
	int border[2] = { 181,1081 };
	string tab_map[BITMAP_COUNT] = { "droga.png","droga2.png","droga3.png"};
	int szer = 0, wysa = 0, wysb = -720;
	int wys[BITMAP_COUNT];
	ALLEGRO_BITMAP* cur_bitmaps[BITMAP_COUNT];
	vector<ALLEGRO_BITMAP*> map_list;

	

	void init();
	void tworz_mape();
	void rysuj_mape();
	void przesuwaj_mape(int predkosc);
	void draw_tree();
	void kasuj_mape();
	void update_map();
	int colission(int x1,int x2);
	ALLEGRO_BITMAP* losuj_mape();
};