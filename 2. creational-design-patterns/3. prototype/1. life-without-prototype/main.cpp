#include <string>
#include <iostream>

using namespace std;

struct Address {
	string street, city;
	int suite;

	Address(const string& street, const string& city, int suite)
		: street(street), city(city), suite(suite) { }

	friend ostream &operator<<(ostream& os, const Address& address) {
		os << "street: " << address.street << " city: " << address.city << 
			" suite: " << address.suite;
		return os;
	}
};

struct Contact {
	string name;
	// Address address;
	Address* address;

	Contact(const string& name, Address* address)
		: name(name), address(address) { }

	friend ostream &operator<<(ostream& os, const Contact& contact) {
		os << "name: " << contact.name << " address: " << *contact.address;
		return os;
	}
};

int main() {

	// we have two people with almost same address
	Address johnAddress("123 East Dr", "London", 123);
	Contact john("John Doe", &johnAddress);
	// Contact jane("Jane Smith", Address{ "123 East Dr", "London", 103 });

	/*
		instead of duplicating code to generate jane object, we can copy john
		and modify its fields that requires change
	*/
	auto jane = john;
	jane.name = "Jane Smith";
	jane.address->suite = 103;

	cout << "John: " << john << endl;
	cout << "Jane: " << jane << endl;

	// since we use value storage, this does not create problem. we can have two
	// different problem. if we change value to pointer, now it is a problem.
	// output is as follows
	// John: name: John Doe address: street: 123 East Dr city: London suite: 123
	// Jane: name: Jane Smith address: street: 123 East Dr city: London suite: 103

	// so now we are changing address storage from value to a pointer. output is
	// as follows
	// John: name: John Doe address: street: 123 East Dr city: London suite: 103
	// Jane: name: Jane Smith address: street: 123 East Dr city: London suite: 103

	// since we are modify the original object using its address, we modify john objects
	// address while modifying the jane objects address. if we had a deep copy, there
	// would not be such problem


	return 0;
}