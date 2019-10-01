#ifndef __PERSON_H
#define __PERSON_H
#include <iostream>
#include <string.h>
const int NAME_SIZE = 30;
class Person
{
protected:
	char name[NAME_SIZE];
	int age;
	char nationality[NAME_SIZE];
	Person(const Person& other);
	virtual ~Person();	//added virtual d'tor (polymorphism) - asaf
public:
	Person(const char* name, int age, const char* nationality);
	virtual void show() const =0; // Set as virtual, so inheritors can override -Amit == changed to abstract - asaf

};

#endif //__PERSON_H
