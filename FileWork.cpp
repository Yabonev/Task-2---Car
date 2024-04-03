
#include "FileWork.h"
void WriteCarsOnTextFile(ofstream& out, const Car& car) {
	out << strlen(car.getBrand()) << endl;
	out << car.getBrand() << endl;

	out << car.getProdyear() << endl;

	out << strlen(car.getOwner().getName()) << endl;
	out << car.getOwner().getName() << endl;

	out << strlen(car.getOwner().getSurname()) << endl;
	out << car.getOwner().getSurname() << endl;

	out << car.getOwner().getYear() << endl;
	out << car.getOwner().getIsMale() << endl;

}

void ReadCarsFromTextFile(ifstream& in, Car& car) {
	int lengthBrand;
	int lengthName;
	int lengthSurname;

	char Brand[128];

	int year;
	bool ismale;

	//Reading brand
	in >> lengthBrand;
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	in.read(Brand, lengthBrand);

	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//Reading year
	in >> year;

	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//Reading owner
	in >> lengthName;
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	char* name = new char[lengthName];
	in.read(name, lengthName);
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	in >> lengthSurname;
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	char* surname = new char[lengthSurname];
	in.read(surname, lengthSurname);
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	in >> year;
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	in >> ismale;

	Person p(name, surname, year, ismale);

	if (in.good()) {
		car.setBrand(Brand);
		car.setProdYear(year);
		car.setOwner(p);
	}
	

}