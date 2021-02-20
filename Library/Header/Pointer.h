#ifndef POINTER_H
#define POINTER_H

#include "Header.h"

class Pointer
{
	SYSTEM System;
public:
	Point point;
	string character;
	Pointer();
	Pointer(int x, int y);
	Pointer(Point point);
	Pointer(string character);
	Pointer(int x, int y, string character);
	Pointer(Point point, string character);
	void show();
	void show(Point point);
	void show(int x, int y);
	void hide();
};

#endif
