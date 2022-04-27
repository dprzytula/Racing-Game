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
class Point2D
{
public:

	int tab[4];
	inline int getX() { return tab[0]; }
	inline int getY() { return tab[2]; }
	inline int getWidth() { return tab[1]; }
	inline int getHeight() { return tab[3]; }

	//void changeCoOrdinates(int x0, int x1, int y0, int y1);

		//void printCoOrdinates();

};