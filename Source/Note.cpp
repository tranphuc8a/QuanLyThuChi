#include "../Header/Note.h"

Note::Note()
{
	setThuChi(0, 0);
	setNote("");
	setDate(Date(1, 1, 0));
}
Note::Note(int chi)
{
	*this = Note();
	setChi(chi);
}
Note::Note(int thu, int chi)
{
	*this = Note();
	setThuChi(0, 0);
}
Note::Note(string note)
{
	*this = Note();
	this->note = note;
}
Note::Node(Date date)
{
	*this = Note();
	this->date = date;
}
Note::Note(int thu, int chi, string note)
{
	*this = Note();
	setThuChi(thu, chi);
	setNote(note);
}
Note::Note(int thu, int chi, string note, Date date)
{
	setThuChi(thu, chi);
	setNote(note);
	setDate(date);
}
Note::~Note(){}

void Note::setThuChi(int thu, int chi)
{
	this->thu = thu;
	this->chi = chi;
}
void Note::setThu(int thu)
{
	this->thu = thu;
}
void Note::setChi(int chi)
{
	this->chi = chi;
}
void Note::setDate(int ngay, int thang, int nam)
{
	this->date = Date(ngay, thang, nam);
}
void Note::setDate(Date date)
{
	this->date;
}
void Note::setNote(string note)
{
	this->note = note;
}
int Note::getThu()
{
	return this->thu;
}
int Note::getChi()
{
	return this->chi;
}
Date Note::getDate()
{
	return this->date;
}
string Note::getNote()
{
	return this->note;
}
	
	
