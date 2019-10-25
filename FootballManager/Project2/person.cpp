
#include "person.h"


Person::Person(const std::string  name, int age, const std::string  nationality) : name(name), age(age), nationality(nationality)
{
	//strncpy_s(Person::name, name, NAME_SIZE); // Copy NAME_SIZE chars from input into name field.
	//Person::name[NAME_SIZE - 1] = '\0'; // In case input was larger than NAME_SIZE adding a null terminator to prevent overflow. 

	//strncpy_s(Person::nationality, nationality, NAME_SIZE); // Copy NAME_SIZE chars from input into nationality field.
	//Person::nationality[NAME_SIZE - 1] = '\0'; // In case input was larger than NAME_SIZE adding a null terminator to prevent overflow. 
}

Person::Person(const Person& other) : name(other.name), age(other.age), nationality(other.nationality) {

}

Person::Person()
{
}


Person::~Person()
{

	//delete[] name;
	//delete[] nationality;
	//Because the name and nationality are not dynamically allocated.
}

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
