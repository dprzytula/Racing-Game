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
class Gracz {
public:
	int borderG[4] = { 500,545,500,594 };
	int predkosc = 15;
	ALLEGRO_BITMAP* gracz;
	ALLEGRO_BITMAP* graczR;
	ALLEGRO_BITMAP* graczL;

	void rysuj_gracza();
	void rysuj_graczaG();
	void rysuj_graczaR();
	void rysuj_graczaL();
	void rysuj_graczaD();
	void sterowanie();
	void rysuj_graczaSTOP();

	void RestartGame() {
		borderG[0] = 500;
		borderG[1] = 545;
		borderG[2] = 500;
		borderG[3] = 594;
	}

	int map_border[2] = { 181,1081 };
	bool colission()
	{
		if (map_border[0] >= borderG[0]) {
			return true;
		}
		else if (map_border[1] <= borderG[0]) {
			return true;
		}
		else return false;
	}
};