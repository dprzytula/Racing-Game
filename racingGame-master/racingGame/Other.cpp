#include "Other.h"
#include "Engine.h"
#include "Gracz.h"
#include "GameStat.h"
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

ALLEGRO_SAMPLE* menuTheme;
ALLEGRO_SAMPLE* gameoverTheme;
ALLEGRO_SAMPLE* effectTurn;
void Other::draw_tree() //rysowanie obiektow odpowiadajacych za wyglad aplikacji
{
   
    tree = al_load_bitmap("tree2.png");
    grass = al_load_bitmap("grass.png");
   
    
    for (int i = 0; i < RozY; i+=100)
    {
        al_draw_bitmap(grass, 0, 15 + i, 0);
        al_draw_bitmap(grass, RozX - 148, 15 + i, 0);
        
        
        al_draw_bitmap(tree, 15, 40 + i, 0);
        al_draw_bitmap(tree, 55, 40 + i,0);
        al_draw_bitmap(tree, 95, 40 + i, 0);

        al_draw_bitmap(tree, RozX - 2*(30), 40 + i, 0);
        al_draw_bitmap(tree, RozX - 2 * (50), 40 + i, 0);
        al_draw_bitmap(tree, RozX - 2 * (70), 40 + i, 0);
    }

    clear_bitmap(tree);
    clear_bitmap(grass);
}


void Other::theme_menu() //muzya w menu
{
    al_reserve_samples(1);
    menuTheme = al_load_sample("muzyka.ogg");
    
    al_play_sample(menuTheme, 0.4, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
    
    
}

void Other::theme_GameOver() //muzya w menu
{

    al_reserve_samples(1);
    gameoverTheme = al_load_sample("gameOverTheme.ogg");
    al_play_sample(gameoverTheme, 0.6, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    
}



void Other::theme_TurnLeftRight() //muzya podczas skrecania w prawo
{
    al_reserve_samples(1);
    effectTurn = al_load_sample("effectTurn.ogg");
    al_play_sample(effectTurn, 0.3, 0.3, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Other::destroyTheme() //usuwanie samplow
{

    al_stop_samples();
    
}

void Other::clear_bitmap(ALLEGRO_BITMAP* obiekt) //czyszczenie bitmapy
{
    al_destroy_bitmap(obiekt);
}