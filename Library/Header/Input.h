#ifndef INPUT_H
#define INPUT_H

#include "Header.h"

class Input : public Object
{
	SYSTEM System;
public:
	string defaultValue;
	Object * reply;
	Input();
	Input(string defaultValue);
	
	Input(Point point);
	Input(string content, string defaultValue);
	Input(string content, Point point);
	Input(Object * up, Object * down, Object * left, Object * right);
	Input(string content, Point point, Object * up, Object * down, Object * left, Object * right);
	
	void setDefaultValue(string defaultValue);
	void setReply(string content, Point toado);
	
	string getClassName() override;
	void show() override;
	void hide() override;
	void run() override;
};

#endif
