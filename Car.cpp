#include "Car.h"

Car::Car(const char brand[128], const Person& owner, const size_t prodyear) :
	brand("\0"),
	owner(Person()),
	prodyear(0)
{
	int lengthBrand = strlen(brand);
	strcpy_s(this->brand,lengthBrand+1, brand);

	this->owner = owner;
	this->prodyear = prodyear;
}

// ==> Getters
Person Car::getOwner() const{
	return owner;
}
size_t Car::getProdyear() const{
	return prodyear;
}
const char* Car::getBrand()const {
	return brand;
}

// ==> Setters
void Car::setOwner(const Person& owner) {
	this->owner = owner;
}
void Car::setProdYear(const size_t year) {
	this->prodyear = year;
}
void Car::setBrand(const char* brand) {
	int lengthBrand = strlen(brand);
	strcpy_s(this->brand, lengthBrand+1, brand);
	this->brand[lengthBrand] = '\0';
}




ostream& operator<<(ostream& out, const Car& car) {
	out << car.getOwner() << endl;
	out << car.getBrand() << endl;
	out << car.getProdyear() << endl;

	

	return out;
}
