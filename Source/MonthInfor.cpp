#include "../Header/MonthInfor.h"

int month;
int year;
vector <DateInfor *> listDate;
vector <Note *> listNote;

MonthInfor::MonthInfor()
{
	this->month = 1;
	this->year = 0;
	listDate = vector<DateInfor *>(1, new DateInfor());
	listNote = vector<Note *>(1, new Note());
}
MonthInfor::MonthInfor(int month, int year)
{
	*this = MonthInfor();
	setDate(month, year);
}
MonthInfor::MonthInfor(int month, int year, vector <DateInfor *> listDate)
{
	*this = MonthInfor();
	setDate(month, year);
	setListDate(listDate);
}
MonthInfor::MonthInfor(int month, int year, vector <Note *> listNote)
{
	*this = MonthInfor();
	setDate(month, year);
	setListNote(listNote);
}
MonthInfor::MonthInfor(int month, int year, vector <DateInfor *> listDate, vector <Note *> listNote)
{
	setDate(month, year);
	setListNote(listNote);
	setListDate(listDate);
}
MonthInfor::MonthInfor(vector <DateInfor *> listDate)
{
	*this = MonthInfor();
	setListDate(listDate);
}
MonthInfor::MonthInfor(vector <Note *> listNote)
{
	*this = MonthInfor();
	setListNote(listNote);
}
MonthInfor::MonthInfor(vector <DateInfor *> listDate, vector <Note *> listNote)
{
	*this = MonthInfor();
	setListNote(listNote);
	setListDate(listDate);
}
MonthInfor::~MonthInfor(){}
void MonthInfor::clear()
{
	for (DateInfor * x : listDate)
		delete x;
	for (Note * x : listNote)
		delete x;
	listDate = vector <DateInfor *>(1, new DateInfor());
	listNote = vector <Note *>(1, new Note());
}

void MonthInfor::setMonth(int month)
{
	this->month = month;
}
void MonthInfor::setYear(int year)
{
	this->year = year;
}
void MonthInfor::setDate(int month, int year)
{
	setMonth(month);
	setYear(year);
	clear();
}
void MonthInfor::setListDate(vector <DateInfor *> listDate)
{
	this->listDate = listDate;
}
void MonthInfor::setListNote(vector <Note *> listNote)
{
	this->listNote = listNote;
}
int MonthInfor::getMonth()
{
	return this->month;
}
int MonthInfor::getYear()
{
	return this->year;
}
vector <DateInfor *> MonthInfor::getListDate()
{
	return listDate;
}
vector <Note *> MonthInfor::getListNote()
{
	return listNote;
}

void MonthInfor::addDate(DateInfor * date)
{
	listDate.push_back(date);
}
void MonthInfor::addNote(Note * note)
{
	listNote.push_back(note);
}
int MonthInfor::calculateEatMoney()
{
	int res = 0;
	for (int i = 1; i < listDate.size(); i++)
	{
		res += (listDate[i]->getBreakfast() + listDate[i]->getLunch() + listDate[i]->getDinner());
	}
	return res;
}
int MonthInfor::calculateOther()
{
	int res = 0;
	for (auto x : listNote)
	{
		res += x->getChi();
	}
	return res;
}
int MonthInfor::calculateReceive()
{
	int res = 0;
	for (auto x : listNote)
	{
		res += x->getThu();
	}
	return res;
}
int MonthInfor::ketXuat()
{
	return calculateEatMoney() + calculateOther() + calculateReceive();
}
