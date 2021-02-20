#include "../Header/Object.h"

Object::Object()
{
	*this = Object("", Point(0, 0), NULL, NULL, NULL, NULL);
}
Object::Object(Point point)
{
	*this = Object();
	this->point = point;
}
Object::Object(string content)
{
	*this = Object();
	this->content = content;
}
Object::Object(string content, Point point)
{
	*this = Object(point);
	this->content = content;
}
Object::Object(Object * up, Object * down, Object * left, Object * right)
{
	*this = Object("", Point(0, 0), up, down, left, right);
}
Object::Object(string content, Point point, Object * up, Object * down, Object * left, Object * right)
{
	setContent(content);
	setPoint(point);
	setGrad(up, down, left, right);
}
void Object::setGrad(Object * up, Object * down, Object * left, Object * right)
{
	setUp(up);
	setDown(down);
	setLeft(left);
	setRight(right);
}
void Object::setUp(Object * up)
{
	this->up = up;
	if (up != NULL) up->down = this;
}
void Object::setDown(Object * down)
{
	this->down = down;
	if (down != NULL) down->up = this;
}
void Object::setLeft(Object * left)
{
	this->left = left;
	if (left != NULL) left->right = this;
}
void Object::setRight(Object * right)
{
	this->right = right;
	if (right != NULL) right->left = this;
}
void Object::setContent(string content)
{
	this->content = content;
}
void Object::setPoint(Point point)
{
	this->point = point;
}
void Object::setPoint(int x, int y)
{
	this->point = Point(x, y);
}
string Object::getClassName()
{
	return "Object";
}
void Object::show()
{
	SYSTEM System;
	System.gotoXY(point.x, point.y);
	cout << content;
}
void Object::hide()
{
	SYSTEM System;
	System.gotoXY(point.x, point.y);
	for (int i = 1; i <= content.size(); i++) cout << " ";
}
void Object::run()
{
	
}
