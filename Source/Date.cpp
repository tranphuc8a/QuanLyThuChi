

#include "../Header/Date.h"


Date::Date()
{
	*this = Date(1, 1, 0);
}
Date::Date(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}
Date::Date(string date)
{
	*this = Date();
	setDate(date);
}
Date::~Date(){}

void Date::setDay(int day)
{
	if (day <= 0) day = 1;
	else if (day > 31) day = 31;
	this->day = day;
}
int Date::getDay()
{
	return this->day;
}
void Date::setMonth(int month)
{
	if (month < 1) month = 1;
	else if (month > 12) month = 12;
	this->month = month;
}
int Date::getMonth()
{
	return this->month;
}
void Date::setYear(int year)
{
	if (year < 0) year = 0;
	this->year = year;
}
int Date::getYear()
{
	return this->year;
}
void Date::setDate(int day, int month, int year)
{
	*this = Date(day, month, year);
}
void Date::setDate(string date)
{
	int day = 10 * date[0] + date[1] - 11 * '0';
	int month = 10 * date[3] + date[4] - 11 * '0';
	int year = 0;
	for (int i = date.size() - 1, j = 0; i >= 6; i--, j++)
		year += (date[i] - '0') * pow(10, j);
	if (!(1 <= day && day <= 31 && 1 <= month && month <= 12 && 0 <= year))
	{
		*this = Date();
		return;
	}
	*this = Date(day, month, year);
}
int Date::getTH()
{
	return Date::DayTH(*this);
}

int Date::DayTH(Date date)
{
	int dis = (date - Date(22, 4, 2001));
	return (((6 + dis) % 7) + 7) % 7 + 2;
}
bool Date::isNamNhuan(int year)
{
	if (year % 400 == 0) return true;
	if (year % 100 == 0) return false;
	if (year % 4 == 0) return true;
	return false;
}
int Date::countDay(int month, int year)
{
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			return 31;
		case 4: case 6: case 9: case 11:
			return 30;
		case 2:
			if (Date::isNamNhuan(year)) return 29;
			return 28;
		default:
			return -1;
	}
}
Date Date::today()
{
	time_t now = time(0);
	tm *DateStruct = localtime(&now);
	int y = 1900 + DateStruct->tm_year;
	int m = 1 + DateStruct->tm_mon;
	int d = DateStruct->tm_mday;
	return Date(d, m, y);
}
int Date::countDayFromNewYear(Date today)
{
	int cntday = 0;
	int year = today.getYear();
	for (int i = 1; i < today.getMonth(); i++)
		cntday += Date::countDay(i, year);
	cntday += today.getDay();
	return cntday;
}
int Date::countDayFromStarting(Date today)
{
	int cntday = 0;
	int year = today.getYear();
	int cntNamNhuan = (year - 1)/4 - (year - 1)/100 + (year - 1)/400 + 1;
	cntday += cntNamNhuan * 366 + (year - cntNamNhuan) * 365;
	
	cntday += Date::countDayFromNewYear(today);
	return cntday;
}
int Date::distance(Date date1, Date date2)
{
	return Date::countDayFromStarting(date1) - countDayFromStarting(date2);
}

Date Date::next()
{
	int d = day, m = month, y = year;
	d++;
	if (d > Date::countDay(m, y));
	{
		d = 1;
		m++;
		if (m > 12)
		{
			m = 1;
			y++;
		}
	}
	return Date(d, m, y);
}
Date Date::previous()
{
	int d = day, m = month, y = year;
	d--;
	if (d < 0)
	{
		m--;
		if (m < 0)
		{
			m = 12;
			y--;
			if (y < 0) y = 0;
		}
		d = Date::countDay(m, y);
	}
	return Date(d, m, y);
}
bool Date::equals(Date date)
{
	return (month == date.getMonth()) && (day == date.getDay()) && (year == date.getYear());
}
bool Date::isAfter(Date date)
{
	if (year > date.getYear()) return true;
	if (year < date.getYear()) return false;
	if (month > date.getMonth()) return true;
	if (month < date.getMonth()) return false;
	return day > date.getDay();
}
bool Date::isBefore(Date date)
{
	if (year > date.getYear()) return false;
	if (year < date.getYear()) return true;
	if (month > date.getMonth()) return false;
	if (month < date.getMonth()) return true;
	return day < date.getDay();	
}

Date Date::operator ++()
{
	*this = next();
	return *this;
}
Date Date::operator ++(int)
{
	Date tmp(*this);
	*this = next();
	return tmp;
}
Date Date::operator --()
{
	*this = previous();
	return *this;
}
Date Date::operator --(int)
{
	Date tmp(*this);
	*this = previous();
	return tmp;
}
Date Date::operator += (int k)
{
	for (int i = 1; i <= k; i++)
		this->operator++();
	return *this;
}
Date Date::operator -= (int k)
{
	for (int i = 1; i <= k; i++)
		this->operator--();
	return *this;
}
int Date::operator - (Date date)
{
	return countDayFromStarting(*this) - countDayFromStarting(date);
}
bool Date::operator ==(Date date)
{
	return equals(date);
}
bool Date::operator > (Date date)
{
	return isAfter(date);
}
bool Date::operator >=(Date date)
{
	return equals(date) || isAfter(date);
}
bool Date::operator < (Date date)
{
	return isBefore(date);
}
bool Date::operator <=(Date date)
{
	return equals(date) || isBefore(date);
}
bool Date::operator !=(Date date)
{
	return !equals(date);
}

void Date::show(ostream & out)
{
	out << toString();
}
string Date::toString()
{
	string res = "";
	if (day < 10) res += "0";
	res += (to_string(day) + "/");
	if (month < 10) res += "0";
	res += (to_string(month) + "/");
	res += to_string(year);
	return res;
}
ostream & operator << (ostream & out, Date date)
{
	out << date.toString();
	return out;
}


