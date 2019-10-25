#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#include <string>

const int NAME_SIZE = 30;
class Person
{
protected:
	std::string name;
	int age;
	std::string nationality;
public:
	Person(const std::string  name, int age, const std::string nationality);
	virtual void show() const = 0; // Set as virtual, so inheritors can override -Amit == changed to abstract - asaf
	friend std::ostream& operator<<(std::ostream& os, const Person& person);
};

#endif //__PERSON_H