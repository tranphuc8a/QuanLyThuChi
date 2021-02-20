#include "../Header/Menu.h"

Menu::Menu()
{
	pointer = new Pointer(Point(0, 0), "->");
	point = NULL;
}
void Menu::clear()
{
	clearDecor();
	clearLinker();
	clearInput();
}
void Menu::clearDecor()
{
	for (auto x : this->decors)
		delete x;
	this->decors = vector <Object *>();
}
void Menu::clearLinker()
{
	for (auto x : linkers)
		delete x;
	this->linkers = vector <Linker *>();
}
void Menu::clearInput()
{
	for (auto x : inputs)
		delete x;
	this->inputs = vector <Input *>();
}
void Menu::addDecor(string content, Point vitri)
{
	this->decors.push_back(new Object(content, vitri));
}
void Menu::addLinker(Linker * linker)
{
	this->linkers.push_back(linker);
}
void Menu::addInput(Input * input)
{
	this->inputs.push_back(input);
}
void Menu::show()
{
	system("cls");
//	SYSTEM().clrscr();
	for (auto x : decors)
		x->show();
	for (auto x : linkers)
		x->show();
	for (auto x : inputs)
		x->show();
	if (point != NULL) 
		pointer->show(point->point.x - 3, point->point.y);	
}
void Menu::hide()
{
	for (auto x : decors)
		x->hide();
	for (auto x : linkers)
		x->hide();
	for (auto x : inputs)
		x->hide();	
}
void Menu::run()
{
	show();
	while (1)
	{
		pointer->show(point->point.x - 3, point->point.y);
		Events key = (Events) getch();
		switch (key)
		{
			case ESC:
				exit(0);
			case UP:
				if (point != NULL && point->up != NULL)
					point = point->up;
				break;
			case DOWN:
				if (point != NULL && point->down != NULL)
					point = point->down;
				break;
			case LEFT:
				if (point != NULL && point->left != NULL)
					point = point->left;
				break;
			case RIGHT:
				if (point != NULL && point->right != NULL)
					point = point->right;
				break;
			case ENTER:
				if (point != NULL)
				{
					if (point->getClassName() == "Linker")
					{
						Linker * tmp = (Linker *) point;
						if (tmp->task == NULL) return;
						else
						{
							int cont = tmp->task();
							if (!cont) return;
						}
					}
					else if (point->getClassName() == "Input")
					{
						Input * tmp = (Input *) point;
						tmp->run();
						if (point->right != NULL) point = point->right;
						else if (point->down != NULL) point = point->down;
					}
				}
				show();
				break;
			default:
				break;
		}
	}
}

