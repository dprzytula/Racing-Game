#include "Engine.h"
#include "Przeciwnik.h"
#include "Gracz.h"
#include "Bonus.h"
#include "Map.h"
#include "GameStat.h"
#include "Other.h"
GameStat* GS = new GameStat();





void Engine::inicjalizacja()  //glowna impementacja
    {
        al_init();
        al_init_font_addon();
        al_init_ttf_addon();
        al_init_image_addon();
        al_install_audio();
        al_init_acodec_addon();
        al_init_acodec_addon();
   
        Przeciwnik::Init();
    }

    void Engine::klaw()  //implementacja klawiatury
    {
        al_install_keyboard();
        al_get_keyboard_state(&klawiatura);
    }

    void Engine::mouse() //implementacja myszki
    {

        al_install_mouse();
        al_get_mouse_state(&mysz);

    }


    void Engine::ekran() //implementacja ekranu
    {
       
            al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);  //SKALOWANIE
            display = al_create_display(RozX, RozY);
        
       
    }

  
   

    void Engine::czysc() //czyszczenie ekranu
    {
        Przeciwnik::Destroy();
        al_destroy_display(display);
        al_destroy_sample(GS->crashSound);
    }
    void Engine::punkty() //dodawanie puntow
    {
        font = al_load_ttf_font("Ausion.ttf", 38, 0);
        ostringstream pkt;
        if (GS->stat == 3) GS->score = 0;
        else if(GS->stat == 1)GS->score += 0.1;
        pkt << "Wynik:" << (int)round(GS->score);                                                               //NOWE
        al_draw_text(font, al_map_rgb(0, 0, 0), 0, 0, 0, pkt.str().c_str());
        al_destroy_font(font);
    }


    void Engine::wynik() //implementacja wyniku
    {
        font = al_load_ttf_font("Ausion.ttf", 58, 0);
        
        ostringstream pkt;
        pkt << "Twoj ostateczny wynik to:" << (int)round(GS->score);                                                               //NOWE
        al_draw_text(font, al_map_rgb(255, 255, 255), al_get_bitmap_width(GS->gameover)/2- al_get_bitmap_width(GS->gameover) / 4, 500, 0, pkt.str().c_str());
        al_destroy_font(font);
    }



    void Engine::rysuj_gre()
    {
        
        kolejka = al_create_event_queue();


        /* Tworzymy timer, obs³ugujemy b³¹d i  rejestujemy go w kolejce */
        GS->init();
        timer_FPS = al_create_timer(1.0 / GS->FPS);

        al_register_event_source(kolejka, al_get_timer_event_source(timer_FPS));
        al_register_event_source(kolejka, al_get_display_event_source(display));
        al_start_timer(timer_FPS);
        //bool grawitacja = false;
        //int x = al_get_display_width(display) / 2;
        //int y = al_get_display_height(display) / 2;
        //int move_x = al_get_display_width(display) / 2;
        
        int czasomierz = 0;
       // Przeciwnik* nowy = new Przeciwnik;
        Map* newMap = new Map;
        Bonus* nowyB = new Bonus;
       
       // Przeciwnik newEnemy;
       // newEnemy.create_enemy();
        

        while (!GS->checkGame)
        {
           

            if (GS->needToReinitDisplay) {//Ustawia fullscreen albo zwykle okno
                GS->needToReinitDisplay = false;
                al_destroy_display(display);
                if (GS->checkFullScreen)
                    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
                else
                    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);  //SKALOWANIE

                display = al_create_display(RozX, RozY);
                al_register_event_source(kolejka, al_get_display_event_source(display));

            }

            al_wait_for_event(kolejka, &ev1);
            switch (ev1.type)
            {
                case ALLEGRO_EVENT_TIMER:
                {
                
                
                
           
                    if (al_key_down(&klawiatura, ALLEGRO_KEY_P)) {
                        GS->stat = 1;
                        GS->drop_menu();
                    }
                      if (al_key_down(&klawiatura, ALLEGRO_KEY_M)) 
                          GS->stat = 0;


                        GS->game_stat();


                    
                    
                }

                if (GS->stat == 1)
                    punkty();
                else if (GS->stat == 2)
                    wynik();

              

                al_flip_display();

            }

        }
        usuwanie_bitmap();
        
        al_destroy_event_queue(kolejka);
        al_destroy_timer(timer_FPS);

    }



   

    void Engine::usuwanie_bitmap()
    {
        
    }


