#include <string>
#include <iostream>

using namespace std;

struct Address {
	string street, city;
	int suite;

	Address(const string& street, const string& city, int suite)
		: street(street), city(city), suite(suite) { }

	Address(const Address& other)
		: street(other.street), city(other.city), suite(other.suite) { }

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

	Contact(const Contact& other) 
		: name(other.name), address(new Address(*other.address)){

	}

	friend ostream &operator<<(ostream& os, const Contact& contact) {
		os << "name: " << contact.name << " address: " << *contact.address;
		return os;
	}
};

int main() {

	// we have two people with almost same address
	Address johnAddress("123 East Dr", "London", 123);
	Contact john("John Doe", &johnAddress);

	// auto jane = john; // shallow copy
	Contact jane(john); // deep copy
	jane.name = "Jane Smith";
	jane.address->suite = 103;

	cout << "John: " << john << endl;
	cout << "Jane: " << jane << endl;

	// this will work correct since we have a deep copy facilitiy, unlike the example in life-without-prototype


	return 0;
}