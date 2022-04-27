#include "Bonus.h"
#include "Engine.h"
#include "Gracz.h"

int Bonus::losuj_RO() //losowanie autka z bonusem
{
    int a;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        a = (rand() % 828) + 226;
    }
    return a;
}


void Bonus::rysuj_bonus() //rysowanie auta z bonusem
{
    bonus = al_load_bitmap("bonus.png");

        borderB[2] -= 10;
        borderB[3] -= 10;
        al_draw_bitmap(bonus, borderB[0], borderB[2], 0);
    
    czysc();
}
void Bonus::czysc() //czyszczenie bonusu
{
    al_destroy_bitmap(bonus);
}