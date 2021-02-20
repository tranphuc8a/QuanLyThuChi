#include "../Header/Update.h"

Menu * updateMenu;
Date today;
bool isFirstOpenUpdateMenu;

void Update(Date date)
{
	today = date;
	updateMenu = new Menu();
	isFirstOpenUpdateMenu = true;
	setDecorUpdateMenu(today);
	setLinkerUpdateMenu(today);
	setInputUpdateMenu(today);
	updateMenu->run();
	updateMenu->clear();
	delete updateMenu;
}

int Update()
{
	Update(Date::today());
	return 1;
}

void setDecorUpdateMenu(Date date)
{
	updateMenu->clearDecor();
	updateMenu->addDecor("CAP NHAT - " + Date::today().toString(), Point(20, 0));
	int month = date.getMonth(), year = date.getYear();
	
	int page = 1;
	if (date.getDay() <= 10) page = 1;
	else if (date.getDay() <= 20) page = 2;
	else page = 3;
	
	int start, end;
	if (page == 1) 		start = 1, end = 10;
	else if (page == 2) start = 11, end = 20;
	else if (page == 3) start = 21, end = Date::countDay(month, year);
	
	string inforpage = "Page " + to_string(page) + "/3";
	string informonth = "Thang " + to_string(month) + "/" + to_string(year);
	updateMenu->addDecor(inforpage, Point(0, 1));
	updateMenu->addDecor("\t\t"	, Point(50, 1));
	updateMenu->addDecor(informonth	, Point(50, 1));
	
	updateMenu->addDecor("Thu"		, Point(0, 2));
	updateMenu->addDecor("Ngay"		, Point(6, 2));
	updateMenu->addDecor("Sang"		, Point(12, 2));
	updateMenu->addDecor("Trua"		, Point(18, 2));
	updateMenu->addDecor("Toi"		, Point(24, 2));
	updateMenu->addDecor("|"		, Point(29, 2));
	updateMenu->addDecor("Thu"		, Point(34, 2));
	updateMenu->addDecor("Chi"		, Point(40, 2));
	updateMenu->addDecor("Ngay"		, Point(46, 2));
	updateMenu->addDecor("Noi dung"	, Point(56, 2));	
	for (int i = start; i <= end; i++)
	{
		int line = i - start + 3;
		int thu = Date(i, month, year).getTH();
		updateMenu->addDecor(to_string(thu)		, Point(0, line));
		updateMenu->addDecor(to_string(i)		, Point(6, line));
		updateMenu->addDecor("|"				, Point(29, line));
	}
}

void setLinkerUpdateMenu(Date date)
{	
	updateMenu->clearLinker();
	Linker * linker[5];
	linker[1] = new Linker("Prev", Point(4, 15), PreviousPage);
	linker[2] = new Linker("Next", Point(45, 15), NextPage);
	linker[3] = new Linker("Back", Point(4, 16), NULL);
	linker[4] = new Linker("OK", Point(45, 16), Okay);
	
	linker[1]->setGrad(NULL, linker[3], linker[2], linker[2]);
	linker[2]->setGrad(NULL, linker[4], linker[1], linker[1]);
	linker[3]->setGrad(linker[1], NULL, linker[4], linker[4]);
	linker[4]->setGrad(linker[2], NULL, linker[3], linker[3]);
	
	for (int i = 1; i <= 4; i++) updateMenu->addLinker(linker[i]);
	if (isFirstOpenUpdateMenu)
	{
		updateMenu->point = linker[1];
		isFirstOpenUpdateMenu = false;
	}
}

void setInputUpdateMenu(Date date)
{
	updateMenu->clearInput();
	
	MonthInfor * monthInfor = new MonthInfor(date.getMonth(), date.getYear());
	Read(monthInfor);
	
	int page = 1;
	if (date.getDay() <= 10) page = 1;
	else if (date.getDay() <= 20) page = 2;
	else page = 3;
	
	int start, end;
	if (page == 1) 		start = 1, end = 10;
	else if (page == 2) start = 11, end = 20;
	else if (page == 3) start = 21, end = Date::countDay(date.getMonth(), date.getYear());

	int count = end - start + 1;
	vector <vector <Input *>> inputs(count + 1, vector <Input *>(4));
	for (int i = 1, k = start; i <= count; i++, k++)
	{
		int line = i + 2;
		for (int j = 1; j <= 3; j++)
		{
			inputs[i][j] = new Input();
			updateMenu->addInput(inputs[i][j]);
			// note:
			
		}
		inputs[i][1]->setDefaultValue(to_string(monthInfor->getListDate()[k]->getBreakfast()));
		inputs[i][2]->setDefaultValue(to_string(monthInfor->getListDate()[k]->getLunch()));
		inputs[i][3]->setDefaultValue(to_string(monthInfor->getListDate()[k]->getDinner()));
		inputs[i][1]->setPoint(Point(12, line));
		inputs[i][2]->setPoint(Point(18, line));
		inputs[i][3]->setPoint(Point(24, line));
		if (k == start)
		{
			inputs[i][1]->setGrad(NULL, inputs[i + 1][1], NULL, inputs[i][2]);
			inputs[i][2]->setGrad(NULL, inputs[i + 1][2], inputs[i][1], inputs[i][3]);
			inputs[i][3]->setGrad(NULL, inputs[i + 1][3], inputs[i][2], NULL);
		}
		else if (k == end)
		{
			inputs[i][1]->setGrad(inputs[i - 1][1], updateMenu->linkers[0], NULL, inputs[i][2]);
			inputs[i][2]->setGrad(inputs[i - 1][2], updateMenu->linkers[0], inputs[i][1], inputs[i][3]);
			inputs[i][3]->setGrad(inputs[i - 1][3], updateMenu->linkers[0], inputs[i][2], NULL);
		}
		else
		{
			inputs[i][1]->setGrad(inputs[i - 1][1], inputs[i + 1][1], NULL, inputs[i][2]);
			inputs[i][2]->setGrad(inputs[i - 1][2], inputs[i + 1][2], inputs[i][1], inputs[i][3]);
			inputs[i][3]->setGrad(inputs[i - 1][3], inputs[i + 1][3], inputs[i][2], NULL);
		}
	}
	updateMenu->linkers[0]->setUp(inputs[count][1]);
	updateMenu->linkers[1]->setUp(inputs[count][3]);
	
	delete monthInfor;
}

int Okay()
{
	MonthInfor * monthInfor = new MonthInfor();
	monthInfor->setDate(today.getMonth(), today.getYear());
	Read(monthInfor);
	
	int page = 1;
	if (today.getDay() <= 10) page = 1;
	else if (today.getDay() <= 20) page = 2;
	else page = 3;
	
	int start, end;
	if (page == 1) 		start = 1, end = 10;
	else if (page == 2) start = 11, end = 20;
	else if (page == 3) start = 21, end = Date::countDay(today.getMonth(), today.getYear());
	
	int count = end - start + 1;
	
	for (int i = 1, k = start; i <= count; i++, k++)
	{
		int b, l, d;
		for (int j = 1; j <= 3; j++)
		{
			int STT = 3*(i - 1) + (j - 1);
			string & getMoney = updateMenu->inputs[STT]->defaultValue;
			if (!CheckMoney(getMoney)) continue;
			if (j == 1) 		b = stoi(getMoney);
			else if (j == 2) 	l = stoi(getMoney);
			else if (j == 3) 	d = stoi(getMoney);
		}
		monthInfor->getListDate()[k]->setInfor(b, l, d);
		// add Note:
	}
	
	Write(monthInfor);
	return 1;
}

bool CheckMoney(string & money)
{
	int countDot = 0;
	for (string :: iterator it = money.begin(); it != money.end(); it++)
	{
		while (it != money.end() && *it == ' ') money.erase(it);
		if (it == money.end()) break;
		if (*it == '.') countDot++;
		else if (!('0' <= *it && *it <= '9'))
		{
			money = "ER!";
			return false;
		}
	}
	if (countDot > 1)
	{
		money = "ER!";
		return false;
	}
	while (money.size() > 0 && money.front() == 0) money.erase(money.begin());
	if (money.size() < 1 || money.front() == '.') money = "0" + money;
	return true;
}

int PreviousPage()
{
	Okay();
	setPreviousDay();
	setDecorUpdateMenu(today);
	setInputUpdateMenu(today);
	updateMenu->run();
	return 0;
}

int NextPage()
{
	Okay();
	setNextDay();
	setDecorUpdateMenu(today);
	setInputUpdateMenu(today);
	updateMenu->run();
	return 0;
}

void setPreviousDay()
{
	if (today.getDay() <= 10)
	{
		if (today.getMonth() == 1)
		{
			today.setMonth(12);
			today.setYear(today.getYear() - 1);
		}
		else today.setMonth(today.getMonth() - 1);
		today.setDay(21);
	}
	else if (today.getDay() <= 20) today.setDay(1);
	else today.setDay(11);
}

void setNextDay()
{
	if (today.getDay() >= 21)
	{
		if (today.getMonth() == 12)
		{
			today.setMonth(1);
			today.setYear(today.getYear() + 1);
		}
		else today.setMonth(today.getMonth() + 1);
		today.setDay(1);
	}
	else if (today.getDay() >= 11)
		today.setDay(21);
	else today.setDay(11);
}
