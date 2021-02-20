#ifndef MENU_H
#define MENU_H

#include "../Header/Header.h"

class Menu
{
public:
	vector <Object *> decors;
	vector <Linker *> linkers;
	vector <Input *> inputs;
	Object * point;
	Pointer * pointer;
	Menu();
	void clear();
	void clearDecor();
	void clearLinker();
	void clearInput();
	void addDecor(string content, Point vitri);
	void addLinker(Linker * linker);
	void addInput(Input * input);
	void show();
	void run();
	void hide();
};

#endif
