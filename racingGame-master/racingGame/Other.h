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
class Other
{
public:
	ALLEGRO_BITMAP* tree;
	ALLEGRO_BITMAP* grass;
	
	


	void theme_menu();
	void theme_GameOver();
	void draw_tree();
	void theme_TurnLeftRight();

	void destroyTheme();

	
	
	
	void clear_bitmap(ALLEGRO_BITMAP* obiekt);
};

