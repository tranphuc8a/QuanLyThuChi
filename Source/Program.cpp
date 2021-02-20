
#include "../Header/Header.h"

Menu * mainMenu;
Menu * findingMenu;
Menu * ketXuatMenu;


void Start()
{
	SYSTEM().HidePtr();
	setMainMenu();
	mainMenu->run();
}

void setMainMenu()
{
	mainMenu = new Menu();
	mainMenu->addDecor("QUAN LI THU CHI", Point(6, 0));
	Linker * linker[5];
	linker[1] = new Linker("Cap nhat", Point(4, 2), Update);
	linker[2] = new Linker("Tim kiem", Point(4, 3), Find);
	linker[3] = new Linker("Ket Xuat", Point(4, 4), KetXuat);
	linker[4] = new Linker("Quit", Point(4, 5));
	for (int i = 1; i <= 3; i++) linker[i]->setDown(linker[i + 1]);
	linker[4]->setDown(linker[1]);
	
	for (int i = 1; i <= 4; i++) mainMenu->addLinker(linker[i]);
	mainMenu->point = linker[1];
}




int getMoney(int x, int y, int len = 6)
{
	SYSTEM System;
	System.gotoXY(x, y);
	for (int i = 1; i <= len; i++) cout << " ";
	System.gotoXY(x, y);
	int mon;
	cin >> mon;
	return mon;
}

string getNote(int x, int y, int len = 20)
{
	SYSTEM System;
	System.gotoXY(x, y);
	for (int i = 1; i <= len ; i++)
		cout << " ";
	System.gotoXY(x, y);
	string note;
	getline(cin, note);
	return note;
}

