#pragma once
#include <string>

class Person {
public:
	std::string name;

	/* 
	implementation is hiden within .cpp file, which will be shipped as a library
	with this implementation, there is no need for private file since details are hidden
	*/ 
	class PersonImpl;
	PersonImpl* impl;

	Person();
	~Person();

	void greet();
};