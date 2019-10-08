#include "person.h"


Person::Person(const char* name, int age, const char* nationality) : age(age) 
{
	strncpy_s(Person::name, name, NAME_SIZE); // Copy NAME_SIZE chars from input into name field.
	Person::name[NAME_SIZE - 1] = '\0'; // In case input was larger than NAME_SIZE adding a null terminator to prevent overflow. 

	strncpy_s(Person::nationality, nationality, NAME_SIZE); // Copy NAME_SIZE chars from input into nationality field.
	Person::nationality[NAME_SIZE - 1] = '\0'; // In case input was larger than NAME_SIZE adding a null terminator to prevent overflow. 
}

Person::Person(const Person& other) : age(other.age) {
	strcpy_s(Person::name, other.name);
	strcpy_s(Person::nationality, other.nationality);
}

Person::~Person()
{
	/*
	delete[] name;
	delete[] nationality;
	*/ //Because the name and nationality are not dynamically allocated.
}

void Person::show() const
{
	std::cout << "Name: " << this->name << "\nAge: " << this->age
		<< "\nNationality: " << this->nationality << std::endl;
}