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
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "Map.h"


#define RozX 1280 
#define RozY 720
#define OKNO ALLEGRO_WINDOWED  

using namespace std;




class Engine{
public:
    
    int RO1 = 0, RO2 = 0;
    int ow = 0;
    int predkosc = 10;
    
    int border[2] = { 181,1028 };
    int stop = 0;
    ALLEGRO_KEYBOARD_STATE klawiatura;
    ALLEGRO_MOUSE_STATE mysz;
    ALLEGRO_DISPLAY* display = NULL;
   // ALLEGRO_DISPLAY* firstDisplay = NULL;
    ALLEGRO_FONT* font = NULL;
    ALLEGRO_EVENT_QUEUE* kolejka = NULL;
    ALLEGRO_EVENT ev1;
    ALLEGRO_TIMER* timer_FPS = NULL;

    

    int done = 0;
   

    //static void setCheck(bool check);
    

    void inicjalizacja();
   
    void klaw();
    
    void ekran();

    void displayFullScren();
    
    void czysc();
    
    void punkty();
    
    void wynik();
    
    void rysuj_gre();
    
    void usuwanie_bitmap();

    void mouse();
  
    
};
