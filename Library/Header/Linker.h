#ifndef LINKER_H
#define LINKER_H

#include "Header.h"

class Linker : public Object
{
public:
	int (*task)();
	Linker();
	Linker(int (*task)());
	
	Linker(Point point);
	Linker(string content);
	Linker(string content, Point point);
	Linker(string content, Point point, int (*task)());
	Linker(Object * up, Object * down, Object * left, Object * right);
	Linker(string content, Point point, Object * up, Object * down, Object * left, Object * right);
	
	
	void setLink(int (*task)());
	void run() override;
	string getClassName() override;
};

#endif
