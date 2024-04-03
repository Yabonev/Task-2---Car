#include "Person.h"

Person::Person() :name(nullptr), surname(nullptr), isMale(0), year(0) {

}
Person::~Person() {
    delete[] name;
    delete[] surname;
}
Person::Person(const char* name, const char* surname, size_t year, const bool isMale) {
    if (name == nullptr || !strcmp(name, "") || surname == nullptr || !strcmp(surname, "")) {
        cerr << "Name can't be null or empty" << endl;
        return;
    }

    int lengthName = strlen(name) + 1;
    int lengthSurname = strlen(surname) + 1;
    this->name = new char[lengthName];
    if (name == nullptr) {
        cerr << "Can't allocate memory for name" << endl;
        return;
    }
    this->surname = new char[lengthSurname];
    if (!surname) {
        cerr << "Can't allocate memory for surname" << endl;
           clearMemory();
        return;
    }
    strcpy_s(this->name, lengthName, name);
    strcpy_s(this->surname, lengthName, surname);

    this->isMale = isMale;
    this->year = year;
}

Person::Person(const Person& other) {
    int lengthName = strlen(other.name) + 1;
    int lengthSurname = strlen(other.surname) + 1;
    this->name = new char[lengthName];
    if (!name) {
        cerr << "Can't allocate memory for name" << endl;
        return;
    }
    this->surname = new char[lengthSurname];
    if (!surname) {
        cerr << "Can't allocate memory for surname" << endl;
        // clearMemory();
        return;
    }
    strcpy_s(this->name, lengthName, other.name);
    strcpy_s(this->surname, lengthName, other.surname);
    this->isMale = other.isMale;
    this->year = other.year;
}
Person& Person::operator=(const Person& other) {
    if (this == &other) {
        return *this;
    }



    if (!other.name || !other.surname) {
        //exception;
        throw bad_alloc();
    }

    if (this->name && this->surname) {
        clearMemory();
    }
    int lengthName = strlen(other.name) + 1;
    int lengthSurname = strlen(other.surname) + 1;
    this->name = new char[lengthName];
    this->surname = new char[lengthSurname];

    strcpy_s(this->name, lengthName, other.name);
    strcpy_s(this->surname, lengthSurname, other.surname);

    this->isMale = other.isMale;
    this->year = other.year;
    return *this;
}

ostream& operator<<(ostream& out, const Person& person) {
    out << person.getName() << endl;
    out << person.getSurname() << endl;
    out << person.getYear() << endl;
    out << person.getIsMale() << endl;
    return out;
}


void Person::clearMemory() {
    delete[] name;
    delete[] surname;
}

char* Person::getName()const {
    return name;
}
char* Person::getSurname()const {
    return surname;
}
size_t Person::getYear() const{
    return year;
}
bool Person::getIsMale()const {
    return isMale;
}