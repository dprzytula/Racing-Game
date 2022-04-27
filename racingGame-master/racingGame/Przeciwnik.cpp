#include "Przeciwnik.h"
#include "Point2D.h"
#include "Drawer.h"
vector <Point2D> coordinates;
vector <int> speeds;
Drawer enemyDrawer;
int global_ilosc_pojazdow = 7;


ALLEGRO_BITMAP* car;

void Przeciwnik::Init() //inicjowanie przeciwnika
{
    car = al_load_bitmap("obiekt.png");
    
}

void Przeciwnik::Destroy()  //usuwanie przeciwnika
{
    al_destroy_bitmap(car);
}


bool czyTorJestZajety(int nr_toru, int szerokosc_autka) { //sprawdzenie toru czy jest zajety przez istniejacy obiekt 
    for (Point2D p : coordinates)
        if (p.getX() == nr_toru * szerokosc_autka + 226)
            return true;
        else
            continue;

    return false;
}

int losuj() //losowanie polozenia obiektu przeciwnika
{
    int szerokosc_autka = 45;
    int liczba_torow = 828 / szerokosc_autka;

    int wylosowany_tor = rand() % liczba_torow;

    if (global_ilosc_pojazdow < liczba_torow - 1)
        while (czyTorJestZajety(wylosowany_tor, szerokosc_autka))
            wylosowany_tor = rand() % liczba_torow;

    int a = wylosowany_tor * szerokosc_autka + 226;
    return a;
}



bool czyWszyscyPrzejechaliWDol() {  //sprawdzenie czy wszystkie obiekty przeciwnika przelecialy w dol
    for (Point2D p : coordinates) {
        if (p.getY() + p.getHeight() < 720)
            return false;
    }

    return true;
}

void Przeciwnik::spawn() //tworzenie nowych obiektow przeciwnika 
{
    if (coordinates.size() != global_ilosc_pojazdow) {
        coordinates.clear();
        speeds.clear();

        for (int i = 0; i < global_ilosc_pojazdow; i++) {
            coordinates.push_back({ losuj(),losuj() + 45,-194,-100 });
            speeds.push_back((rand() % 5) + 3);
        }

    }
}

void  Przeciwnik::create_enemy() //tworzenie nowych obiektow na mapie
{
    spawn();

    if (czyWszyscyPrzejechaliWDol()) {
        coordinates.clear();
        global_ilosc_pojazdow = (rand() % 7) + 4;
        spawn();
    }
    else {
        aktualizacja_pozycji();
    }

    for (int c = 0; c < coordinates.size(); c++)
    {
        rysowanie_enemy(car,coordinates[c].tab[0], coordinates[c].tab[2]);
    }


    

}

void Przeciwnik::aktualizacja_pozycji() //aktualizowanie pozycji obiektu przeciwnika
{
    for (int j = 0; j < coordinates.size(); j++) {
        coordinates[j].tab[2] += speeds[j];
    }
}

void Przeciwnik::rysuj()
{


    // coordinates[0].tab[2] += 15;
   //  coordinates[0].tab[3] += 15;
  //   rysowanie_enemy(coordinates[0].tab[0], coordinates[0].tab[2]);


}
//enemyOBject[0] - lewa krawedz pojazdu (szerokosc)
//enemyObject[1] - prawa krawdedz pojazdu (szerokosc)
//enemyObject[2] - dolna krawedz pojazdu (wysokosc)
//enemyObject[3] - gorna krawedz pojazdu (wysokosc)


void Przeciwnik::rysowanie_enemy(ALLEGRO_BITMAP* obiekt,int x, int y) // rysowanie przeciwnika
{
    enemyDrawer.draw_bitmap(obiekt, x, y);
}

void Przeciwnik::draw_enemy()
{


}


bool Przeciwnik::CzyKolidujeZGraczem(int x_gracza, int y_gracza, int w_gracza, int h_gracza) //sprawdzenie czy przeciwnik koliduje z obiektem gracza
{
    int enemy_width = 45;
    int enemy_height = 94;
    for (Point2D enemyPos : coordinates)
        if (x_gracza + w_gracza > enemyPos.getX() && x_gracza < enemyPos.getX() + enemy_width && y_gracza + h_gracza > enemyPos.getY() && y_gracza < enemyPos.getY() + enemy_height)
            return true;

    return false;
}

void Przeciwnik::drop_enemy(ALLEGRO_BITMAP* obiekt) //usuwanie przeciwnika
{
    enemyDrawer.delete_bitmap(obiekt);
}

void Przeciwnik::RestartGameAction() //resteowanie wspolrrzednych przeciwnika
{
    coordinates.clear();
    speeds.clear();
}