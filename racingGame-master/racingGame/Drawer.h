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
using namespace std;
class Drawer {
public:
	ALLEGRO_BITMAP* create_bitmap(string name);
	void delete_bitmap(ALLEGRO_BITMAP* bitmap);
	void draw_bitmap(ALLEGRO_BITMAP* bitmap, int x, int y);
};