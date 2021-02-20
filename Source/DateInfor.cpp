#include "../Header/DateInfor.h"

DateInfor::DateInfor()
{
	setBreakfast(0);
	setLunch(0);
	setDinner(0);
	date = Date(0, 0, 0);
	note = "";
}
DateInfor::DateInfor(int moneyBreakfast, int moneyLunch, int moneyDinner)
{
	*this = Date();
	setBreakfast(moneyBreakfast);
	setLunch(moneyLunch);
	setDinner(moneyDinner);
}
DateInfor::DateInfor(Date date)
{
	*this = DateInfor();
	this->date = date;
}
DateInfor::DateInfor(string note)
{
	*this = DateInfor();
	this->note = note;
}
DateInfor::~DateInfor(){}

void DateInfor::setInfor(int moneyBreakfast, int moneyLunch, int moneyDinner)
{
	setBreakfast(moneyBreakfast);
	setLunch(moneyLunch);
	setDinner(moneyDinner);
}
void DateInfor::setDate(Date date)
{
	this->date = date;
}
void DateInfor::setDate(int day, int month, int year)
{
	this->date = Date(day, month, year);
}
void DateInfor::setBreakfast(int money)
{
	this->moneyBreakfast = money;
}
void DateInfor::setLunch(int money)
{
	this->moneyLunch = money;
}
void DateInfor::setDinner(int money)
{
	this->moneyDinner = money;
}
Date DateInfor::getDate()
{
	return this->date;
}
int DateInfor::getBreakfast()
{
	return this->moneyBreakfast;
}
int DateInfor::getLunch()
{
	return this->moneyLunch;
}
int DateInfor::getDinner()
{
	return this->moneyDinner;
}
void DateInfor::setNote(string note)
{
	this->note = note;
}
string DateInfor::getNote()
{
	return this->note;
}


