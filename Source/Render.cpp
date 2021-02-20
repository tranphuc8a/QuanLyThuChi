
#include "../Header/Render.h"


Menu * renderMenu;
Menu * renderFollowMonthMenu;
Menu * renderFollowYearMenu;

int KetXuat()
{
	renderMenu = new Menu();
	setRenderMenu(renderMenu);
	renderMenu->run();
	renderMenu->clear();
	delete renderMenu;
	return 1;
}

int renderFollowMonth()
{
	renderFollowMonthMenu = new Menu();
	setRenderFollowMonthMenu(renderFollowMonthMenu);
	renderFollowMonthMenu->run();
	renderFollowMonthMenu->clear();
	delete renderFollowMonthMenu;
	return 1;
}

int renderFollowYear()
{	
	renderFollowYearMenu = new Menu();
	setRenderFollowYearMenu(renderFollowYearMenu);
	renderFollowYearMenu->run();
	renderFollowYearMenu->clear();
	delete renderFollowYearMenu;
	return 1;
}

int renderTenYear()
{
	Menu * render = new Menu();

	vector <double> SUM(12, 0);

	int year = Date::today().getYear();
	render->addDecor("KET XUAT 10 NAM (" + to_string(year - 10) + " - " + to_string(year) + ")", Point(4, 1));
	render->addDecor("Year", Point(4, 3));
	render->addDecor("Money", Point(15, 3));
	for (int i = year - 10, j = 1; i <= year; i++, j++)
	{
		int line = j + 3;
		vector <MonthInfor *> monthInfors(13, NULL);
		for (int k = 1; k <= 12; k++)
		{
			monthInfors[k] = new MonthInfor(k, i);
			Read(monthInfors[k]);
			SUM[j] += monthInfors[k]->ketXuat();
		}
		for (auto it : monthInfors) delete it;

		render->addDecor(to_string(i), Point(4, line));
		render->addDecor(to_string((int) SUM[j]), Point(15, line));
	}

	render->show();
	getch();
	render->clear();
	delete render;

	return 1;
}

void setRenderMenu(Menu * renderMenu)
{
	renderMenu->addDecor("KET XUAT", Point(30, 0));
	
	Linker * followMonth = new Linker("Theo thang", Point(4, 2), renderFollowMonth);
	Linker * followYear = new Linker("Theo nam", Point(4, 3), renderFollowYear);
	Linker * tenYear = new Linker("10 nam gan day", Point(4, 4), renderTenYear);
	Linker * back = new Linker("Back", Point(4, 5), NULL);

	followMonth->setGrad(back, followYear, back, followYear);
	followYear->setGrad(followMonth, tenYear, followMonth, tenYear);
	tenYear->setGrad(followYear, back, tenYear, back);
	back->setGrad(tenYear, followMonth, tenYear, followMonth);
	
	if (renderMenu->point == NULL)
		renderMenu->point = followMonth;
		
	renderMenu->addLinker(followMonth);
	renderMenu->addLinker(followYear);
	renderMenu->addLinker(tenYear);
	renderMenu->addLinker(back);
}

int OkayForMonth()
{
	string & month = renderFollowMonthMenu->inputs[0]->defaultValue;
	string & year = renderFollowMonthMenu->inputs[1]->defaultValue;
	bool a = checkMonth(month);
	bool b = checkYear(year);
	if (!(a && b))
	{
		renderFollowMonthMenu->addDecor("Input khong hop le!", Point(4, 10));
		return 1;
	}
	int m = stoi(month), y = stoi(year);
	if (!(2001 <= y && y <= 2101))
	{
		renderFollowMonthMenu->addDecor("Input khong hop le!", Point(4, 10));
		return 1;
	}
	MonthInfor * monthInfor = new MonthInfor(m, y);
	Read(monthInfor);
	
	Menu * render = new Menu();
	vector <string> decors(5, "");
	decors[1] = "Ket xuat thang " + month + " nam " + year;
	decors[2] = "Tien an: " + to_string(monthInfor->calculateEatMoney());
	decors[3] = "Tieu vat: " + to_string(monthInfor->calculateOther());
	decors[4] = "SUM = " + to_string(monthInfor->ketXuat());

	for (int i = 1; i <= 4; i++)
		render->addDecor(decors[i], Point(4, 2 + i));

	render->show();
	getch();

	render->clear();
	delete render;
	return 1;
}

void setRenderFollowMonthMenu(Menu * renderFollowMonthMenu)
{
	renderFollowMonthMenu->addDecor("KET XUAT THEO THANG", Point(30, 0));

	Input * inputMonth = new Input("Nhap thang: ", Point(4, 2));
	Input * inputYear = new Input("Nhap nam: ", Point(4, 3));
	Linker * Okay = new Linker("Okay", Point(4, 4), OkayForMonth);
	Linker * Back = new Linker("Back", Point(4, 5), NULL);

	inputMonth->setGrad(Back, inputYear, Back, inputYear);
	inputYear->setGrad(inputMonth, Okay, inputMonth, Okay);
	Okay->setGrad(inputYear, Back, inputYear, Back);
	Back->setGrad(Okay, inputMonth, Okay, inputMonth);

	renderFollowMonthMenu->addInput(inputMonth);
	renderFollowMonthMenu->addInput(inputYear);
	renderFollowMonthMenu->addLinker(Okay);
	renderFollowMonthMenu->addLinker(Back);

	if (renderFollowMonthMenu->point == NULL)
		renderFollowMonthMenu->point = inputMonth;
}

int OkayForYear()
{
	string & year = renderFollowYearMenu->inputs[0]->defaultValue;
	if (!checkYear(year))
	{
		renderFollowYearMenu->addDecor("Input sai!", Point(4, 10));
		return 1;
	}
	int y = stoi(year);
	if (!(2001 <= y && y <= 2101))
	{
		renderFollowYearMenu->addDecor("Input sai!", Point(4, 10));
		return 1;
	}
	vector <MonthInfor *> monthInfors(13, NULL);

	for (int i = 1; i <= 12; i++)
	{
		monthInfors[i] = new MonthInfor(i, y);
		Read(monthInfors[i]);
	}

	Menu * render = new Menu();
	render->addDecor("Ket xuat nam " + to_string(y), Point(4, 1));
	render->addDecor("Thang", Point(4, 3));
	render->addDecor("Tien", Point(15, 3));
	double SUM = 0;
	for (int i = 1; i <= 12; i++)
	{
		int line = i + 3;
		render->addDecor(to_string(i), Point(4, line));
		string content = to_string(monthInfors[i]->ketXuat());
		render->addDecor(content, Point(15, line));
		SUM += monthInfors[i]->ketXuat();
	}
	render->addDecor("Tong", Point(4, 16));
	render->addDecor(to_string((int) SUM), Point(15, 16));

	render->show();
	getch();
	render->clear();
	delete render;
	for (auto it : monthInfors) delete it;
	return 1;
}

void setRenderFollowYearMenu(Menu * renderFollowYearMenu)
{
	renderFollowYearMenu->addDecor("KET XUAT THEO NAM", Point(30, 0));

	Input * inputYear = new Input("Nhap nam: ", Point(4, 2));
	Linker * Okay = new Linker("Okay", Point(4, 3), OkayForYear);
	Linker * Back = new Linker("Back", Point(4, 4), NULL);

	inputYear->setGrad(Back, Okay, Back, Okay);
	Okay->setGrad(inputYear, Back, inputYear, Back);
	Back->setGrad(Okay, inputYear, Okay, inputYear);

	renderFollowYearMenu->addInput(inputYear);
	renderFollowYearMenu->addLinker(Okay);
	renderFollowYearMenu->addLinker(Back);

	if (renderFollowYearMenu->point == NULL)
		renderFollowYearMenu->point = inputYear;	
}

