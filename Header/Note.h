#ifndef NOTE_H
#define NOTE_H

#include "Header.h"

class Note
{
private:
	int thu;
	int chi;
	string note;
	Date date;
public:
	Note();
	Note(int chi);
	Note(int thu, int chi);
	Note(string note);
	Node(Date date);
	Note(int thu, int chi, string note);
	Note(int thu, int chi, string note, Date date);
	~Note();
public:
	void setThuChi(int thu, int chi);
	void setThu(int thu);
	void setChi(int chi);
	void setDate(int ngay, int thang, int nam);
	void setDate(Date date);
	void setNote(string note);
	int getThu();
	int getChi();
	Date getDate();
	string getNote();
};

#endif
