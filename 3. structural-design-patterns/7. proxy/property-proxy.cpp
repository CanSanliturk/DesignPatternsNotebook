#include <iostream>

using namespace std;

template <typename T>
struct Property {
	
	T value;
	
	Property(T value) {
		*this = value;
	}

	operator T() { return value; }

	T operator=(T new_value) {
		cout << "Assignment!" << endl;
		return value = new_value;
	}
};

struct Creature {
	Property<int> strength{ 10 };
	Property<int> agility{ 5 };
};

int main() {

	Creature c;
	c.strength = 11;
	int x = c.agility;

	return 0;
}