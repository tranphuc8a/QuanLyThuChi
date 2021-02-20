
#include "../Header/System.h"

void SYSTEM::clrscr()
{
	for (int i = 0; i<=20; i++)
	{
		gotoXY(0, i);
		for (int j = 1; j<=10; j++)
			cout << "\t";
		cout << endl;
	}
	gotoXY(0, 0);
	// system("cls");
}	
void SYSTEM::SetColor(int x)
{ 
    HANDLE hConsoleColor;
    hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsoleColor, x);
}
void SYSTEM::gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SYSTEM::Srand()
{
	srand((int) time(0));
}
int SYSTEM::Random()
{
	return rand();
}
void SYSTEM::HidePtr()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
}
void SYSTEM::ShowPtr()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = TRUE;
    SetConsoleCursorInfo(hOut,&ConCurInf);
} 

