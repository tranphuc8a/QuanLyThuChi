#include "../Header/Pointer.h"

Pointer::Pointer()
{
	point = Point(0, 0);
	character = "->";
}
Pointer::Pointer(int x, int y)
{
	*this = Pointer();
	this->point = Point(x, y);
}
Pointer::Pointer(Point point)
{
	*this = Pointer(point.x, point.y);
}
Pointer::Pointer(string character)
{
	*this = Pointer();
	this->character = character;
}
Pointer::Pointer(int x, int y, string character)
{
	*this = Point(x, y);
	this->character = character;
}
Pointer::Pointer(Point point, string character)
{
	*this = Pointer(point.x, point.y, character);
}
void Pointer::show()
{
	System.gotoXY(point.x, point.y);
	cout << character;
}
void Pointer::show(Point point)
{
	show(point.x, point.y);
}
void Pointer::show(int x, int y)
{
	hide();
	*this = Point(x, y);
	show();
}
void Pointer::hide()
{
	System.gotoXY(point.x, point.y);
	for (int i = 1; i <= character.size(); i++) cout << " ";	
}


