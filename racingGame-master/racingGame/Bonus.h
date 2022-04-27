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


class Bonus {
public:
	ALLEGRO_BITMAP* bonus = NULL;
	int borderB[4] = { 0,0,-38,894 };

	int predkosc = 7;
	int losuj_RO();
	void rysuj_bonus();
	void czysc();
	bool CzyKolidujeZGraczem(int x_gracza, int y_gracza, int w_gracza, int h_gracza)
	{
		int bonus_width = 45;
		int bonus_height = 94;

			if (x_gracza + w_gracza > borderB[0] && x_gracza < borderB[0] + bonus_width && y_gracza + h_gracza > borderB[2] && y_gracza < borderB[2] + bonus_height)
				return true;

		return false;
	}
};
