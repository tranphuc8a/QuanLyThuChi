#ifndef OBJECT_H
#define OBJECT_H

#include <bits/stdc++.h>
#include "Point.h"
#include "System.h"
using namespace std;


class Object
{
protected:
	SYSTEM System;
public:
	string content;
	Point point;
	Object * up;
	Object * down;
	Object * left;
	Object * right;
	Object();
	Object(Point point);
	Object(string content);
	Object(string content, Point point);
	Object(Object * up, Object * down, Object * left, Object * right);
	Object(string content, Point point, Object * up, Object * down, Object * left, Object * right);
	void setGrad(Object * up, Object * down, Object * left, Object * right);
	void setUp(Object * up);
	void setDown(Object * down);
	void setLeft(Object * left);
	void setRight(Object * right);
	void setContent(string content);
	void setPoint(Point point);
	void setPoint(int x, int y);
	virtual string getClassName();
	virtual void show();
	virtual void hide();
	virtual void run();
};

#endif
