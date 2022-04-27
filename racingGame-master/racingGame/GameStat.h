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
#include "Button.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
using namespace std;
enum chooseSideDraw { LEFT, RIGHT };
class GameStat {
public:
	ALLEGRO_BITMAP* menu;
	ALLEGRO_BITMAP* gameover;
	ALLEGRO_BITMAP* options;
	ALLEGRO_SAMPLE* crashSound;
	ALLEGRO_SAMPLE* myzyka1;
	ALLEGRO_SAMPLE* myzyka2;
	/*ALLEGRO_BITMAP* start;
	;
	ALLEGRO_BITMAP* quit;*/
	/*
	ALLEGRO_BITMAP* options;
	ALLEGRO_BITMAP* oFPS;
	ALLEGRO_BITMAP* o30;
	ALLEGRO_BITMAP* o60;
	ALLEGRO_BITMAP* fullSs;
	ALLEGRO_BITMAP* reso;
	ALLEGRO_BITMAP* backToMenu;
	ALLEGRO_BITMAP* currentReso;
	ALLEGRO_BITMAP* playAgain;
	ALLEGRO_BITMAP* titleGameOver;*/
	//0 stat menu
	//1 stat start
	//2 stat gameover
	int stat = 0;
	void init();
	bool checkButton(int x1, int x2, int y1, int y2);
	void generateBittmapButtonMenu(ALLEGRO_BITMAP* main, ALLEGRO_BITMAP* button, int h);
	float generateButtonNextToEachOtherOptions(ALLEGRO_BITMAP* main, ALLEGRO_BITMAP* button, chooseSideDraw option);


	bool checkPositionButton(float x1, float x2, float y1, float y2);

	Button* buttonik;
	Button* start;
	Button* settings;
	Button* quit;


	Button* oFPS;
	Button* o30;
	Button* o60;
	Button* fullSs;
	Button* reso;
	Button* backToMenu;
	Button* currentReso;
	Button* playAgain;
	Button* titleGameOver;

	int FPS = 60;
	bool checkGame = false;
	bool checkFullScreen = false;
	bool needToReinitDisplay = false;
	bool checkFPS = false;
	float score = 0;
	void create_menu();
	void create_gameover();
	void create_options();

	void game_stat();
	void drop_menu();
	void drop_gameover();
	void drop_options();
	int return_player_coordinate(int i);
	void reset_possition();
	float centerButton(ALLEGRO_BITMAP* main, ALLEGRO_BITMAP* temp);


private:
	void func_menu();
	void func_game();
	void func_gameover();
	void func_startgame();
	void func_options();
};