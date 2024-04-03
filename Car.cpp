#include "Car.h"

Car::Car(const char brand[128], const Person& owner, const size_t prodyear) :
	brand("\0"),
	owner(Person()),
	prodyear(0)
{
	int lengthBrand = strlen(brand); // in cases where you use strlen and then strcpy_s, make the length of the string one more to include the null terminator.
	strcpy_s(this->brand,lengthBrand+1, brand);

	/* Better:
	* size_t brandLength = strlen(brand) + 1; -> improved naming of variable; clear indication of the length of the string.
	* strcpy_s(this->brand, brandLength, brand); // ALWAYS ensure brand length is <= this->brand length, otherwise this will cause a buffer overflow, resulting is an error.
	* No need to add the null terminator, as strcpy_s will do that for you, if it doesn't fail.
	*/

	this->owner = owner;
	this->prodyear = prodyear; // Better naming would be productionYear. Use camelCase.
}

// ==> Getters
Person Car::getOwner() const{ // Correct, you can also return const Person& to avoid copying the object.
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
void Car::setBrand(const char* brand) { // Same logic as in the constructor
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
