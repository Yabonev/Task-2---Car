#include "Person.h"

Person::Person() :name(nullptr), surname(nullptr), isMale(0), year(0) {

}
Person::~Person() {
    delete[] name;
    delete[] surname;
}
Person::Person(const char* name, const char* surname, size_t year, const bool isMale) {
    // Separate validations, to ensure better error handling.
    // First validate name, then surname with different if-cases.
    // Better to use strcpy(name,"") == 0 instead of !strcmp(name,"") as it's more readable.
    if (name == nullptr || !strcmp(name, "") || surname == nullptr || !strcmp(surname, "")) {
        cerr << "Name can't be null or empty" << endl;
        return;
    }

    // You have setters that do all this work for you, yet you don't use them.
    int lengthName = strlen(name) + 1;
    int lengthSurname = strlen(surname) + 1;
    this->name = new char[lengthName];
    // You will never go into the if statement below because you're not suing new(std::nothrow), if you cannot allocate memory, the program will throw an std::bad_alloc exception. which you don't handle.
    // One way to handle this is to use new(std::nothrow) and check if the pointer is nullptr. and then clearMemory(). 
    // The other is to wrap the new call in a try-catch block and handle the exception and then throw again.
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

    // GENERAL ADVICE FOR THE EXAM: Write good setters and use them. They will save you a lot of time and effort.
    // Setters should: validate the input, throw an exception if input is invalid, deallocate and allocate new memory, copy the data.
    // Then your constructors should set pointers to nullpointer in initializer lists, otherwise the delete[] of setters will crash your program.
    // Refer to the book_strong_exception_safety.cpp in github.
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


    // Do not throw bad_alloc if you don't have allocation fail. Only throw bad alloc if you try to allocate memory and it fails with new(std::nothrow) and the resulting pointer in nullptr.
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