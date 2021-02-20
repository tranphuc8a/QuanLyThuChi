
#include "../Header/Graphic.h"

void DrawMain()
{
	system("cls");
	cout << "\t\tQUAN LY THU CHI" << endl;
	cout << "(1) Cap nhat" << endl;
	cout << "(2) Tim kiem" << endl;
	cout << "(3) Ket xuat" << endl;
	cout << "(4) Thoat" << endl;
}

void DrawUpdate()
{
	system("cls");
	cout << "\t\tCAP NHAT" << endl;
	
}

void DrawMonthInfor(MonthInfor monthInfor, Date today)
{
	SYSTEM System;
	System.clrscr();
	int page;
	if (today.getDay() <= 10) page = 1;
	else if (today.getDay() <= 20) page = 2;
	else page = 3;
	System.gotoXY(40, 1);
	cout << "Page " << page << "/3. Thang ";
	cout << monthInfor.getMonth() << "/" << monthInfor.getYear() << endl;
	
	int start, end;
	if (page == 1) start = 1, end = 10;
	else if (page == 2) start = 11, end = 20;
	else start = 21, end = Date::countDay(monthInfor.getMonth(), monthInfor.getYear());
	
	System.gotoXY(0, 2); cout << "Thu";
	System.gotoXY(6, 2); cout << "Ngay";
	System.gotoXY(12, 2); cout << "Sang";
	System.gotoXY(18, 2); cout << "Trua";
	System.gotoXY(24, 2); cout << "Toi";
	System.gotoXY(29, 2); cout << "|";
	System.gotoXY(30, 2); cout << "Thu";
	System.gotoXY(36, 2); cout << "Chi";
	System.gotoXY(42, 2); cout << "Ngay";
	System.gotoXY(52, 2); cout << "Noi dung";
	
	for (int i = start; i <= end; i++)
	{
		int line = i - start + 3;
		System.gotoXY(0, line); cout << Date(i, today.getMonth(), today.getYear()).getTH();
		System.gotoXY(6, line); cout << i;
		System.gotoXY(12, line); cout << monthInfor.getListDate()[i]->getBreakfast();
		System.gotoXY(18, line); cout << monthInfor.getListDate()[i]->getLunch();
		System.gotoXY(24, line); cout << monthInfor.getListDate()[i]->getDinner();
		System.gotoXY(29, line); cout << "|";
		if (i + 1 > monthInfor.getListNote().size()) continue;
		System.gotoXY(30, line); cout << monthInfor.getListNote()[i]->getThu();
		System.gotoXY(36, line); cout << monthInfor.getListNote()[i]->getChi();
		System.gotoXY(42, line); cout << monthInfor.getListNote()[i]->getDate();
		System.gotoXY(52, line); cout << monthInfor.getListNote()[i]->getNote();
	}
	
	System.gotoXY(1, 14); cout << "(1)Prev"; System.gotoXY(50, 14); cout << "(2)Next";
	System.gotoXY(1, 15); cout << "(3)Back"; System.gotoXY(50, 15); cout << "(4)Okay";
	
	System.gotoXY(20, 17); cout << "Eat   Money: " << monthInfor.calculateEatMoney();
	System.gotoXY(20, 18); cout << "Other Money: " << monthInfor.calculateOther();
	System.gotoXY(20, 19); cout << "Total Money: " << monthInfor.ketXuat();
}

void DrawFind();

void DrawKetXuat();


