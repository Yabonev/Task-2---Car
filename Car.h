#ifndef _CAR_HEADER_INCLUDED_
#define _CAR_HEADER_INCLUDED_
#include "Person.h"
class Car {
public:
	Car(const char brand[128], const Person& owner, const size_t prodyear);

	friend ostream& operator<<(ostream&, const Car&);

	Person getOwner()const;
	size_t getProdyear()const;
	const char* getBrand()const;

	void setOwner(const Person&);
	void setBrand(const char*);
	void setProdYear(const size_t);

private:

	Person owner;
	size_t prodyear; // Better naming would be productionYear. Use camelCase.
	char brand[128];
	
};
#endif // !_CAR_HEADER_INCLUDED_
