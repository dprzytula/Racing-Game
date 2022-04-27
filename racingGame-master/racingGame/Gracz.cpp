#include "Gracz.h"
#include "Engine.h"
#include "Other.h"
Engine eng1;
Other* otherEffect = new Other;
void Gracz::rysuj_gracza() //rysowanie obiektu gracza 
{
    gracz = al_load_bitmap("gracz.png");
    borderG[0] += 0;
    borderG[1] += 0;
    borderG[2] += 0;
    borderG[3] += 0;
    al_draw_bitmap(gracz, borderG[0], borderG[2], 0);
    al_destroy_bitmap(gracz);
}

void Gracz::rysuj_graczaG() //rysowanie gracza przemieszczenie
{
    gracz = al_load_bitmap("gracz.png");
    borderG[0] += 0;
    borderG[1] += 0;
    borderG[2] -= predkosc;
    borderG[3] -= predkosc;
    al_draw_bitmap(gracz, borderG[0], borderG[2], 0);
    al_destroy_bitmap(gracz);
}

void Gracz::rysuj_graczaD() //rysowanie gracza przemieszczenie
{
    gracz = al_load_bitmap("gracz.png");
    borderG[0] += 0;
    borderG[1] += 0;
    borderG[2] += predkosc;
    borderG[3] += predkosc;
    al_draw_bitmap(gracz, borderG[0], borderG[2], 0);
    al_destroy_bitmap(gracz);
}

void Gracz::rysuj_graczaL() //rysowanie gracza z przesunieciem o 45
{

    graczL = al_load_bitmap("graczL.png");
    borderG[0] -= predkosc;
    borderG[1] -= predkosc;
    borderG[2] += 0;
    borderG[3] += 0;
    al_draw_bitmap(graczL, borderG[0], borderG[2], 0);
    al_destroy_bitmap(graczL);
}

void Gracz::rysuj_graczaR() //rysowanie gracza z przesunieciem o 45
{

    graczR = al_load_bitmap("graczR.png");
    borderG[0] += predkosc;
    borderG[1] += predkosc;
    borderG[2] += 0;
    borderG[3] += 0;
    al_draw_bitmap(graczR, borderG[0], borderG[2], 0);
    al_destroy_bitmap(graczR);

}

void Gracz::rysuj_graczaSTOP() //zamienia z 45 stopni na normaleny obiekt
{

    graczR = al_load_bitmap("gracz.png");
    borderG[0] += 0;
    borderG[1] += 0;
    borderG[2] += 0;
    borderG[3] += 0;
    al_draw_bitmap(graczR, borderG[0], borderG[2], 0);
    al_destroy_bitmap(graczR);

}



void Gracz::sterowanie() //sterowanie graczem za ppomoca klawiatury
{



    eng1.klaw();
    if (al_key_down(&eng1.klawiatura, ALLEGRO_KEY_W))
    {
        if (borderG[2] <=0)                       //brak mozliwosci wyjazdu poza dolna granice
        {
            
            borderG[2] = 15;
            borderG[3] = 15 + 94;
        }
        rysuj_graczaG();

    }
    else if (al_key_down(&eng1.klawiatura, ALLEGRO_KEY_S))
    {
        if (borderG[3] >= 720)                       //brak mozliwosci wyjazdu poza dolna granice
        {
            borderG[2] = RozY - 109;
            borderG[3] = RozY-15;
        }
        rysuj_graczaD();
    }
    else if (al_key_down(&eng1.klawiatura, ALLEGRO_KEY_D))
    {
        rysuj_graczaR();
    }
    else if (al_key_down(&eng1.klawiatura, ALLEGRO_KEY_A))
    {
        rysuj_graczaL();
        
    }
    else if (al_key_down(&eng1.klawiatura, ALLEGRO_KEY_UP))
    {
        if (borderG[2] <= 0)                       //brak mozliwosci wyjazdu poza dolna granice
        {
            borderG[2] = 15;
            borderG[3] = 15 + 94;
        }
        rysuj_graczaG();
    }
    else if (al_key_down(&eng1.klawiatura, ALLEGRO_KEY_DOWN))
    {
        if (borderG[3] >= 720)                       //brak mozliwosci wyjazdu poza dolna granice
        {
            borderG[2] = RozY - 109;
            borderG[3] = RozY - 15;
        }
        rysuj_graczaD();
        
    }
    else if (al_key_down(&eng1.klawiatura, ALLEGRO_KEY_RIGHT))
    {
        rysuj_graczaR();
        
    }
    else if (al_key_down(&eng1.klawiatura, ALLEGRO_KEY_LEFT))
    {
        rysuj_graczaL();
    }
}