#include "Button.h"
using namespace std;

Button::Button(std::string name) //ladowanie buttonu
{
	button = al_load_bitmap(name.c_str());
	


}

void Button::buttonCreator(int x, int y) //tworzenie bitmapy
{
	this->x = x;
	this->y = y;
	al_draw_bitmap(button, x,y,0);
}
bool Button::update(Engine eng)  //sprawdzenie polozenia buttonu jesli jest myszka jest w obebie buttonu to zwroc true
{

	
	eng.mouse();
	if (eng.mysz.buttons & 1)
	{
		if ((eng.mysz.x >= x)
			&& (eng.mysz.x <= (al_get_bitmap_width(button)+x))
			&& (eng.mysz.y >= y) && (eng.mysz.y <= (y + al_get_bitmap_height(button))))
		{

			return true;
		}

		return false;

	}

	return false;
}


