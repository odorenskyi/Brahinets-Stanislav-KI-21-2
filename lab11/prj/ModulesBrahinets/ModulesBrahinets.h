#ifndef MODULESBRAHINETS_H_INCLUDED
#define MODULESBRAHINETS_H_INCLUDED

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include "struct_type_project_3.h"

using namespace std;

void WriteToDataFile(char file_name[], BusStation* rase);
void ReadDataFile(char file_name[], BusStation* rase);
BusStation* AddExample(char file_name[], BusStation* rase);
void WriteToTxtFile(fstream &file, BusStation* rase);

#endif // MODULESBRAHINETS_H_INCLUDED
