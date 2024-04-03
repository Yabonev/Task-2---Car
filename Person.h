#ifndef _PERSON_HEADER_INCLUDED_
#define  _PERSON_HEADER_INCLUDED_
#include <iostream>
using namespace std;
class Person {
public:
	Person();
	~Person();
	Person(const Person&);
	Person(const char* name, const char* surname, size_t year, const bool isMale);
	Person& operator=(const Person&);

	char* getName()const;
	char* getSurname()const;
	size_t getYear()const;
	bool getIsMale()const;

	friend ostream& operator<<(ostream&, const Person&);
	
private:
	char* name;
	char* surname;
	size_t year;
	bool isMale;
	void clearMemory();

};
#endif // !_PERSON_HEADER_INCLUDED_
