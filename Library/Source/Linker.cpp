#include "../Header/Linker.h"

Linker::Linker() : Object()
{
	this->task = NULL;
}
Linker::Linker(int (*task)()) : Object()
{
	this->task = task;
}
Linker::Linker(Point point) : Object(point) {setLink(NULL);}
Linker::Linker(string content) : Object(content) {setLink(NULL);}
Linker::Linker(string content, Point point) : Object(content, point) {setLink(NULL);}
Linker::Linker(string content, Point point, int (*task)()) : Object(content, point) {setLink(task);}
Linker::Linker(Object * up, Object * down, Object * left, Object * right)
: Object(up, down, left, right) {setLink(NULL);}
Linker::Linker(string content, Point point, Object * up, Object * down, Object * left, Object * right)
: Object(content, point, up, down, left, right) {setLink(NULL);}

void Linker::setLink(int (*task)())
{
	this->task = task;
}
void Linker::run()
{
	if (this->task != NULL)
		task();
}
string Linker::getClassName()
{
	return "Linker";
}


