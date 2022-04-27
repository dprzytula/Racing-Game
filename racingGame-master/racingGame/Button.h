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

using namespace std;

class Button
{
public:
	int x;
	int y;
	
	ALLEGRO_BITMAP* button;

	Button(std::string name);

	void buttonCreator(int x, int y);
	
	bool update(Engine eng);

	float centerCheck();
};