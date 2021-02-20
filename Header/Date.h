#ifndef DATE_H
#define DATE_H

#include <bits/stdc++.h>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date();
	Date(int day, int month, int year);
	Date(string date);
	~Date();
public:
	void setDay(int day);
	int getDay();
	void setMonth(int month);
	int getMonth();
	void setYear(int year);
	int getYear();
	void setDate(int day, int month, int year);
 	void setDate(string date);
	int getTH();
public:
	static int DayTH(Date date);
	static bool isNamNhuan(int year);
	static int countDay(int month, int year);
	static Date today();
	static int countDayFromNewYear(Date today);
	static int countDayFromStarting(Date today);
	static int distance(Date date1, Date date2);
public:
	Date next();
	Date previous();
	bool equals(Date date);
	bool isAfter(Date date);
	bool isBefore(Date date);
public:
	Date operator ++();
	Date operator ++(int);
	Date operator --();
	Date operator --(int);
	Date operator += (int);
	Date operator -= (int);
	int operator -  (Date);
	bool operator ==(Date date);
	bool operator > (Date date);
	bool operator >=(Date date);
	bool operator < (Date date);
	bool operator <=(Date date);
	bool operator !=(Date date);
public:
	void show(ostream &);
	string toString();
	friend ostream & operator << (ostream & out, Date date);
};


#endif
