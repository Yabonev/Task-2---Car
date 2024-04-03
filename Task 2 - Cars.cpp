



#include "FileWork.h"



// General naming convention for files: filework.h, filework.cpp, person.h, person.cpp, car.h, car.cpp


int main() {
    Person p("willy", "smith", 1994, 1);
    Person p1("adad", "sadafaw",124, 1);

    Car car("Jaguar", p, 2000);
    ofstream out = ofstream("Cars.txt", ios::beg);
    ifstream in = ifstream("Car.txt", ios::beg);
    WriteCarsOnTextFile(out, car);
    Car car2("Panther", p1, 1);
    ReadCarsFromTextFile(in, car2);
    cout << car2.getBrand();


}