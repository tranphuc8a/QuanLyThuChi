#include "../Header/InputOutputFile.h"

void Read(MonthInfor * monthInfor)
{
	string path = "Data/";
	path += to_string(monthInfor->getYear()) + "/T";
	path += to_string(monthInfor->getMonth()) + ".txt";
	fstream file;
	file.open(path, ios::in);
	
	monthInfor->clear();
	string date;
	getline(file, date);
	
	// read eat money
	int daysOfMonth;
	file >> daysOfMonth;
	
	
	for (int i = 1; i <= daysOfMonth; i++)
	{
		int b, l, d;
		file >> b >> l >> d;
		DateInfor * tmpDateInfor = new DateInfor(b, l, d);
		tmpDateInfor->setDate(Date(i, monthInfor->getMonth(), monthInfor->getYear()));
		monthInfor->addDate(tmpDateInfor);
	}
	
//	SYSTEM().gotoXY(30, 30);
//	cout << monthInfor->getListDate()[15]->getLunch() << endl;
//	getch();
//	return;
	
	// read note
	int n; file >> n;
	for (int i = 1; i <= n; i++)
	{
		int thu, chi;
		Date dat;
		string ghichu, ngay;
		file >> thu >> chi;
		file.ignore();
		getline(file, ghichu);
		file >> ngay;
		dat = Date(ngay);
		Note * tmpNote = new Note(thu, chi, ghichu, dat);
		monthInfor->addNote(tmpNote);
	}
	
	file.close();
}

void Write(MonthInfor * monthInfor)
{
	string path = "Data/";
	path += to_string(monthInfor->getYear()) + "/T";
	path += to_string(monthInfor->getMonth()) + ".txt";
	
	fstream file;
	file.open(path, ios::out);
		
	//get some data
	int daysOfMonth = Date::countDay(monthInfor->getMonth(), monthInfor->getYear());
	int cntNote = monthInfor->getListNote().size() - 1;
	vector <DateInfor *> lDate = monthInfor->getListDate();
	vector <Note *> lNote = monthInfor->getListNote(); 
	// write month
	file << monthInfor->getMonth() << "/" << monthInfor->getYear() << endl;
	// Write eatmoney
	file << daysOfMonth << endl;
	for (int i = 1; i <= daysOfMonth; i++)
	{		
		file << lDate[i]->getBreakfast() << " "; 
		file << lDate[i]->getLunch() << " ";
		file << lDate[i]->getDinner() << endl;
	}
	// Write note
	if (lNote.size() > 0) file << lNote.size() - 1 << endl;
	else file << 0 << endl;
	for (int i = 1; i < lNote.size(); i++)
	{
		file << lNote[i]->getThu() << " " << lNote[i]->getChi() << endl;
		file << lNote[i]->getNote() << endl;
		file << lNote[i]->getDate() << endl;
	}
	
	file.close();
}

void CreateData()
{
	// from the year of 2001 to 2101
	string path = ".\\Data";
	string cmd = "";
	for (int year = 2001; year <= 2101; year++)
	{
		// create folder year
		cmd = "mkdir " + path + "\\" + to_string(year);
		cout << cmd << endl;
		system(cmd.c_str());
		for (int month = 1; month <= 12; month++)
		{
			cout << cmd << endl;
			// create file month
			string filename = path + "\\" + to_string(year) + "\\T" + to_string(month) + ".txt";
			cmd = "echo >" + filename;
			system(cmd.c_str());
			fstream file;
			file.open(filename, ios::out);
			
			int daysOfMonth = Date::countDay(month, year);
			file << month << "/" << year << endl << daysOfMonth << endl;
			for (int i = 1; i <= daysOfMonth; i++)
				file << "0 0 0" << endl;
			file << 0 << endl;
			
			file.close();
		}
	}
}
void CreateFolder(string path, string name)
{
	//mkdir(path);
	
}

void RemoveFolder(string path, string name)
{
	
	
}

void CreateFile(string path, string name)
{
	fstream file;
	file.open(path, ios::out);
	
	file.close();	
}

void RemoveFile(string path, string name)
{
	
}
