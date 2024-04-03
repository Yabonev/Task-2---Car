#ifndef _FILEWORK_HEADER_INCLUDED_
#define _FILEWORK_HEADER_INCLUDED_

#include "Car.h"
#include <fstream>

void WriteCarsOnTextFile(ofstream& out, const Car& car);
void ReadCarsFromTextFile(ifstream& in, Car& car);
#endif // !_FILEWORK_HEADER_INCLUDED_

