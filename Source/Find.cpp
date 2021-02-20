#include "../Header/Header.h"

Menu * findMenu;

int Find()
{
	findMenu = new Menu();
	setFindMenu();
	findMenu->run();
	findMenu->clear();
	delete findMenu;
	return 1;
}

int FindOkay()
{
	string & getDay = findMenu->inputs[0]->defaultValue;
	string & getMonth = findMenu->inputs[1]->defaultValue;
	string & getYear = findMenu->inputs[2]->defaultValue;
	if (!checkDay(getDay) || !checkMonth(getMonth) || !checkYear(getYear))
	{
		findMenu->addDecor("Ngay ban nhap khong hop le!", Point(4, 10));
		return 1;
	}
	int d, m, y;
	d = stoi(getDay); m = stoi(getMonth); y = stoi(getYear);
	if (!checkDate(d, m, y))
	{
		findMenu->addDecor("Ngay ban nhap khong hop le!", Point(4, 10));
		return 1;
	}
	
	Update(Date(d, m, y));
	
	return 0;
}

void setFindMenu()
{
	findMenu->addDecor("TIM KIEM", Point(30, 0));
	Input * inputDay, * inputMonth, * inputYear;
	Linker * OK, * Back;
	inputDay 	= new Input("Nhap ngay: "	, Point(4, 2));
	inputMonth 	= new Input("Nhap thang: "	, Point(4, 3));
	inputYear 	= new Input("Nhap nam: "	, Point(4, 4));
	OK 			= new Linker("Okay"			, Point(4, 5), FindOkay);
	Back 		= new Linker("Back"			, Point(4, 6), NULL);
	inputDay->setGrad(Back, inputMonth, Back, inputMonth);
	inputMonth->setGrad(inputDay, inputYear, inputDay, inputYear);
	inputYear->setGrad(inputMonth, OK, inputMonth, inputYear);
	OK->setGrad(inputYear, Back, inputYear, Back);
	Back->setGrad(OK, inputDay, OK, inputDay);
	
	findMenu->addInput(inputDay);
	findMenu->addInput(inputMonth);
	findMenu->addInput(inputYear);
	findMenu->addLinker(OK);
	findMenu->addLinker(Back);
	
	findMenu->point = inputDay;
	
}

bool checkDay(string & date)
{
	for (string::iterator it = date.begin(); it != date.end(); it++)
	{
		while (it != date.end() && *it == ' ')
			date.erase(it);
		if (it != date.end() && !('0' <= *it && *it <= '9'))
			return false;
	}
	while (date.front() == '0') date.erase(date.begin());
	if (date.size() < 1 || date.size() > 2) return false;
	int day;
	if (date.size() == 1) day = date[0] - '0';
	else day = 10 * date[0] + date[1] - 11 * '0';
	if (!(1 <= day && day <= 31)) return false;
	return true;
}

bool checkMonth(string & month)
{
	for (string::iterator it = month.begin(); it != month.end(); it++)
	{
		while (it != month.end() && *it == ' ')
			month.erase(it);
		if (it != month.end() && !('0' <= *it && *it <= '9'))
			return false;
	}
	while (month.front() == '0') month.erase(month.begin());
	if (month.size() < 1 || month.size() > 2) return false;
	int m;
	if (month.size() == 1) m = month[0] - '0';
	else m = 10 * month[0] + month[1] - 11 * '0';
	if (!(1 <= m && m <= 12)) return false;
	return true;
}

bool checkYear(string & year)
{
	for (string::iterator it = year.begin(); it != year.end(); it++)
	{
		while (it != year.end() && *it == ' ') year.erase(it);
		if (it != year.end() &&  !('0' <= *it && *it <= '9'))
			return false;
	}
	while (year.front() == '0') year.erase(year.begin());
	if (year.size() < 1) year = "0";
	return true;
}

bool checkDate(int d, int m, int y)
{
	if (!(y >= 0)) return false;
	if (!(1 <= m && m <= 12)) return false;
	int maxday = Date::countDay(m, y);
	if (!(1 <= d && d <= maxday)) return false;
	return true;
}

