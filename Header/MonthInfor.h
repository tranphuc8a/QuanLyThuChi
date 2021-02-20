#ifndef MONTHINFOR_H
#define MONTHINFOR_H

#include "Header.h"

class MonthInfor
{
private:
	int month;
	int year;
	vector <DateInfor *> listDate;
	vector <Note *> listNote;
public:
	MonthInfor();
	MonthInfor(int month, int year);
	MonthInfor(int month, int year, vector <DateInfor *> listDate);
	MonthInfor(int month, int year, vector <Note *> listNote);
	MonthInfor(int month, int year, vector <DateInfor *> listDate, vector <Note *> listNote);
	MonthInfor(vector <DateInfor *> listDate);
	MonthInfor(vector <Note *> listNote);
	MonthInfor(vector <DateInfor *> listDate, vector <Note *> listNote);
	~MonthInfor();
	void clear();
public:
	void setMonth(int month);
	void setYear(int year);
	void setDate(int month, int year);
	void setListDate(vector <DateInfor *> listDate);
	void setListNote(vector <Note *> listNote);
	int getMonth();
	int getYear();
	vector <DateInfor *> getListDate();
	vector <Note *> getListNote();
public:
	void addDate(DateInfor * date);
	void addNote(Note * note);
	int calculateEatMoney();
	int calculateOther();
	int calculateReceive();
	int ketXuat();
};

#endif
