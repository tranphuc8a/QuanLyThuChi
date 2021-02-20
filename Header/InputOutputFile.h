#ifndef IOFILE_H
#define IOFILE_H

#include "Header.h"

void Read(MonthInfor * monthInfor);

void Write(MonthInfor * monthInfor);

void CreateFolder(string path, string name);

void RemoveFolder(string path, string name);

void CreateFile(string path, string name);

void RemoveFile(string path, string name);

void CreateData();

#endif
