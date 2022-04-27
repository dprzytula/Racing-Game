#include "GameStat.h"
#include "Drawer.h"
#include "Map.h"
#include "Engine.h"
#include "Gracz.h"
#include "Przeciwnik.h"
#include "Bonus.h"
#include "Other.h"
Map* nowaMapa = new Map;
Drawer GameCreator;
Engine eng;
Gracz* nowyG = new Gracz;
Bonus* bonus = new Bonus;
int bonus_czasomierz = 0;
Other* other = new Other;
Przeciwnik newEnemies;
int temp = 0; // zmienna zaobiegajaca aby utwor gameover wykonywal sie w nieskonczonosc - patrz funckja func_gameover
int tempMenu = 0; // j.w tylko dla MENU
void GameStat::reset_possition()
{
	nowyG->borderG[0] = 500;
	nowyG->borderG[1] = 545;
	nowyG->borderG[2] = 500;
	nowyG->borderG[3] = 594;
	Przeciwnik::RestartGameAction();
	nowyG->RestartGame();
}
int GameStat::return_player_coordinate(int i)
{
	return nowyG->borderG[i];
}

void GameStat::create_menu() //rysowanie menu
{
	menu = GameCreator.create_bitmap("menu.png");
	start = new Button("startButton.png");
	settings = new Button("optionsButton.png");
	quit = new Button("quitButton.png");
}

float GameStat::centerButton(ALLEGRO_BITMAP* main, ALLEGRO_BITMAP* temp)
{

	return (al_get_bitmap_width(main) / 2) - (al_get_bitmap_width(temp) / 2);

}

void GameStat::create_gameover() { //rysowanie ekranu gameover

	gameover = GameCreator.create_bitmap("gameover.png");
	playAgain = new Button("playAgain.png");
	titleGameOver = new Button("gameover2.png");

}

void GameStat::create_options() //rysowanie ekranu opcji
{

	options = GameCreator.create_bitmap("options.png");


	oFPS = new Button("FPS.png");
	o30 = new Button("template_square30.png");
	o60 = new Button("template_square60.png");
	fullSs = new Button("template_button_fullScreen.png");
	reso = new Button("RESOULUTION.png");
	currentReso = new Button("template_button_1280x720.png");
	backToMenu = new Button("template_button_menu.png");

}



void GameStat::init() { 
	create_menu();
	create_gameover();
	create_options();
	nowaMapa->tworz_mape();
	crashSound = al_load_sample("crashsound.mp3");

	myzyka1 = al_load_sample("muzyka1.mp3");

	myzyka2 = al_load_sample("gameOverTheme.ogg"); 


}






float GameStat::generateButtonNextToEachOtherOptions(ALLEGRO_BITMAP* main, ALLEGRO_BITMAP* button, chooseSideDraw option)
{

	if (option == 0)
		return ((al_get_bitmap_width(main) / 2) - (al_get_bitmap_width(button) / 2)) - ((al_get_bitmap_width(button) / 2) - 5);


	if (option == 1)
		return ((al_get_bitmap_width(main) / 2) - (al_get_bitmap_width(button) / 2)) + ((al_get_bitmap_width(button) / 2) + 5);



}



void GameStat::func_menu() // metoda odpowiadajaca za logike menu etc
{
	// menu 
	
	
	GameCreator.draw_bitmap(menu, 0, 0);
	start->buttonCreator(centerButton(menu, start->button), 40);
	settings->buttonCreator(centerButton(menu, settings->button), 160);
	quit->buttonCreator(centerButton(menu, quit->button), 280);
	
	if (tempMenu == 0)
	{
		other->theme_menu();
	}
	tempMenu++;


	if (start->update(eng)) // button Start Game
	{
		//drop_menu();
		reset_possition();
		
		other->destroyTheme();
		stat = 3;
		al_play_sample(myzyka1, 1, 0.0, 1, ALLEGRO_PLAYMODE_LOOP, 0);

	}

	if (settings->update(eng)) // button Options 
	{
		//drop_menu();
		stat = 4;

	}

	if (quit->update(eng)) // button Quit
	{
		//drop_menu();
		checkGame = true;
	}
}

void GameStat::func_game()  // funkcja odpowiedzialna za logike gry
{
	nowaMapa->przesuwaj_mape(eng.predkosc);
	nowaMapa->rysuj_mape();
	newEnemies.create_enemy();

	other->draw_tree();
	//newEnemy.drop_enemy();
	if (al_key_down(&eng.klawiatura, ALLEGRO_KEY_W) || al_key_down(&eng.klawiatura, ALLEGRO_KEY_A) || al_key_down(&eng.klawiatura, ALLEGRO_KEY_S) || al_key_down(&eng.klawiatura, ALLEGRO_KEY_D) ||
		al_key_down(&eng.klawiatura, ALLEGRO_KEY_RIGHT) || al_key_down(&eng.klawiatura, ALLEGRO_KEY_LEFT) || al_key_down(&eng.klawiatura, ALLEGRO_KEY_DOWN) || al_key_down(&eng.klawiatura, ALLEGRO_KEY_UP))
	{

		nowyG->sterowanie();
	}
	else  nowyG->rysuj_graczaSTOP();


	if (Przeciwnik::CzyKolidujeZGraczem(nowyG->borderG[0], nowyG->borderG[2], 40, 84) || nowyG->colission()) {
		stat = 2;//Game over
		other->destroyTheme();
		//al_play_sample(crashSound,1,0.0,1,ALLEGRO_PLAYMODE_ONCE,0);
		al_play_sample(myzyka2, 1, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
	}

	if (bonus_czasomierz <= 0) {
		bonus->rysuj_bonus();
		if (bonus->CzyKolidujeZGraczem(nowyG->borderG[0], nowyG->borderG[2], 40, 84)) {
			bonus->borderB[2] = -200;
			bonus_czasomierz = 60 * 6;
			score += 50;
		}

		if (bonus->borderB[3] < -100) {
			bonus->borderB[0] = bonus->losuj_RO();
			bonus->borderB[1] = bonus->borderB[0] + 45;
			bonus->borderB[2] = 800;
			bonus->borderB[3] = 894;
			bonus_czasomierz = 60 * 20;
		}
	}

	bonus_czasomierz--;



	
}

void GameStat::func_gameover() // funkcja odpowiedzialna za logike jak przegramy
{
	
	temp++;
	GameCreator.draw_bitmap(gameover, 0, 0);
	titleGameOver->buttonCreator(centerButton(gameover, titleGameOver->button), 20);
	playAgain->buttonCreator(centerButton(gameover, playAgain->button), 150);
	quit->buttonCreator(centerButton(gameover, quit->button), 280);
	

	if (temp == 1)
		other->theme_GameOver();
	
	
	if (playAgain->update(eng)) // button Play Again 
	{
		//GameCreator.delete_bitmap(gameover);
		other->destroyTheme();
		al_play_sample(myzyka1, 1, 0.0, 1, ALLEGRO_PLAYMODE_LOOP, 0);
		stat = 3;
		std::cout << stat << endl;
		std::cout << "PLay again" << endl;
		temp = 0;
	}

	if (quit->update(eng)) // button Quit
	{
		//GameCreator.delete_bitmap(gameover);
		std::cout << "Quit" << endl;
		other->destroyTheme();
		checkGame = true;
	}

	

}

void GameStat::func_startgame()
{
	reset_possition();
	stat = 1;
	bonus_czasomierz = 0;

	//reset bonusa
	bonus->borderB[0] = bonus->losuj_RO();
	bonus->borderB[1] = bonus->borderB[0] + 45;
	bonus->borderB[2] = 800;
	bonus->borderB[3] = 894;
}

void GameStat::func_options() // funkcja odpowiedizlana za logike w opcjach
{
	GameCreator.draw_bitmap(options, 0, 0);
	oFPS->buttonCreator(centerButton(options, oFPS->button), 200);
	o30->buttonCreator(generateButtonNextToEachOtherOptions(options, (o30->button), LEFT), 300);
	o60->buttonCreator(generateButtonNextToEachOtherOptions(options, (o60->button), RIGHT), 300);
	reso->buttonCreator(centerButton(options, reso->button), 380);
	fullSs->buttonCreator(generateButtonNextToEachOtherOptions(options, (fullSs->button), LEFT), 480);
	currentReso->buttonCreator(generateButtonNextToEachOtherOptions(options, (currentReso->button), RIGHT), 480);
	backToMenu->buttonCreator(centerButton(options, backToMenu->button), 600);


	if (o30->update(eng))
	{

		std::cout << "30 FPS" << endl;
		FPS = 30;

	}
	if (o60->update(eng))
	{

		std::cout << "60 FPS" << endl;
		FPS = 60;
	}

	if (fullSs->update(eng) && !needToReinitDisplay)
	{
		checkFullScreen = true;
		std::cout << "FULL SCREEN" << endl;
		al_set_new_display_flags(ALLEGRO_FULLSCREEN);
		needToReinitDisplay = true;
		eng.mysz.buttons = 0;

	}
	if (currentReso->update(eng) &&!needToReinitDisplay)
	{
		checkFullScreen = false;
		std::cout << "1280x720 resolution" << endl;
		al_set_new_display_flags(ALLEGRO_NOFRAME);
		needToReinitDisplay = true;
		eng.mysz.buttons = 0;

	}
	if (backToMenu->update(eng))
	{

		std::cout << "Back To Menu" << endl;
		stat = 0;

	}
}



void GameStat::game_stat() { //glowna funkcja odpowiadajaca za wpuszczanie odpowiednej sceny



	eng.klaw();
	switch (stat) {
	case 0: { func_menu(); }break;
	case 1: // game
	{
		
		func_game();
	}break;
	case 2: // gameover
	{
		
		func_gameover();
	}break;
	case 3: // Start Game
	{
		func_startgame();
	}break;
	case 4: // Options
	{

		func_options();

	}
	}
}

void GameStat::drop_menu() //usuwanie menu
{
	GameCreator.delete_bitmap(menu);
}
void GameStat::drop_gameover() // usuwanie gameover
{
	GameCreator.delete_bitmap(gameover);
}
void GameStat::drop_options() //usuwanie sceny opcji
{
	GameCreator.delete_bitmap(options);
}