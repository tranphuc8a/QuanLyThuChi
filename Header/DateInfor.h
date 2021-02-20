#ifndef DATEINFOR_H
#define DATEINFOR_H

#include "Header.h"

class DateInfor
{
private:
	int moneyBreakfast;
	int moneyLunch;
	int moneyDinner;
	Date date;
	string note;
public:
	DateInfor();
	DateInfor(int moneyBreakfast, int moneyLunch, int moneyDinner);
	DateInfor(Date date);
	DateInfor(string note);
	~DateInfor();
public:
	void setInfor(int moneyBreakfast, int moneyLunch, int moneyDinner);
	void setDate(Date date);
	void setDate(int day, int month, int year);
	void setBreakfast(int money);
	void setLunch(int money);
	void setDinner(int money);
	Date getDate();
	int getBreakfast();
	int getLunch();
	int getDinner();
	void setNote(string note);
	string getNote();
};

#endif
