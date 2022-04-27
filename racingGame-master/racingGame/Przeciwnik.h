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

class Przeciwnik {
public:
    static void Init();
    static void Destroy();

    int enemyObject[4] = { 0,0,721,0 };
    void create_enemy();
    void drop_enemy(ALLEGRO_BITMAP* obiekt);
    void rysowanie_enemy(ALLEGRO_BITMAP* obiekt, int x, int y);
    void draw_enemy();
    void rysuj();

    void spawn();
    void aktualizacja_pozycji();

    static bool CzyKolidujeZGraczem(int x_gracza, int y_gracza, int w_gracza, int h_gracza);
    static void RestartGameAction();
};