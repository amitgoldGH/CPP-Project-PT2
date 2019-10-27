
#include "person.h"


Person::Person(const std::string  name, int age, const std::string  nationality) : name(name), age(age), nationality(nationality){}

void Person::show() const
{
	std::cout.setf(std::ios::left);
	std::cout.width(10);
	std::cout << name;
	std::cout.width(5);
	std::cout << this->age;
	std::cout.width(13);
	std::cout << this->nationality;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
	os << "Name: " << person.name << "\nAge: " << person.age
		<< "\nNationality: " << person.nationality;
	return os;
}
