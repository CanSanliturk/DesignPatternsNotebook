#define _USE_MATH_DEFINES
#define _HAS_AUTO_PTR_ETC 1
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>
#include <map>
#include <ostream>
#include <cstdint>
#include <functional>
#include <typeindex>
#include <any>

using namespace std;

/*
C and old C++ aproach
struct House {
	union {
		string houseName;
		int houseNumber;
	};

	enum class Type { name, number } type;
};
*/

// This is classic functor approach to be used by std::visit, can be replaced by a lambda
struct AddressPrinter {
	void operator()(const string& houseName) const {
		cout << "A house called " << houseName << endl;
	}

	void operator()(const int houseNumber) const {
		cout << "House number: " << houseNumber << endl;
	}
};

int main() {

	variant<string, int> house;
	
	house = "Montefiore Castle";
	AddressPrinter ap;
	visit(ap, house);

	// example with lambda
	house = 123;
	visit(
		[](auto& arg) {
			using T = decay_t<decltype(arg)>;
			if constexpr (is_same_v<T, string>) {
				cout << "A house called " << arg << endl;
			}
			else {
				cout << "House number: " << arg << endl;
			}
		}, house
	);

	return 0;
} 