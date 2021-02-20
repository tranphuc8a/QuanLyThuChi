#include "../Header/Input.h"

Input::Input() : Object()
{
	this->defaultValue = "";
	this->reply = NULL;
}
Input::Input(string defaultValue) : Object()
{
	this->defaultValue = defaultValue;
	this->reply = NULL;
}
Input::Input(Point point) : Object(point){}
Input::Input(string content, string defaultValue) : Object(content) {this->defaultValue = defaultValue;}
Input::Input(string content, Point point) : Object(content, point) {}
Input::Input(Object * up, Object * down, Object * left, Object * right)
: Object(up, down, left, right) {}
Input::Input(string content, Point point, Object * up, Object * down, Object * left, Object * right)
: Object(content, point, up, down, left, right) {}

void Input::setDefaultValue(string defaultValue)
{
	this->defaultValue = defaultValue;
}
void Input::setReply(string content, Point toado)
{
	this->reply = new Object(content, toado);
}
string Input::getClassName()
{
	return "Input";
}
void Input::show()
{
	System.gotoXY(point.x, point.y);
	if (this->content != "")
	{
		cout << content;
		System.gotoXY(point.x + content.size(), point.y);
	}
	cout << defaultValue;
}
void Input::hide()
{
	System.gotoXY(point.x, point.y);
	if (this->content != "")
	{
		for (int i = 1; i <= content.size(); i++) cout << " ";
		System.gotoXY(point.x + content.size(), point.y);
	}
	for (int i = 1; i <= defaultValue.size(); i++) cout << " ";
}
void Input::run()
{
	string oldValue = defaultValue;
	hide();
	defaultValue = "";
	show();
	if (this->content == "") System.gotoXY(point.x, point.y);
	else System.gotoXY(point.x + content.size(), point.y);
	System.ShowPtr();
	getline(cin, defaultValue);
	if (defaultValue == "") defaultValue = oldValue;
	System.HidePtr();
//	show();
}
