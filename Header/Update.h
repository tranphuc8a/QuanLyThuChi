#pragma once
#include "Program.h"

void setDecorUpdateMenu(Date);
void setLinkerUpdateMenu(Date);
void setInputUpdateMenu(Date);

void Update(Date);
int Update();

bool CheckMoney(string &);
int Okay();
int PreviousPage();
int NextPage();

void setPreviousDay();
void setNextDay();

