#include <map>
#include <string>
#include <iostream>

using namespace std;

// assume this is in a text file normally
string capitalstxt[] = {
	"Tokyo",
	"33200000",
	"New York",
	"17800000",
	"Sao Paulo",
	"17700000",
	"Mexico City",
	"17400000",
	"Osaka",
	"16425000",
	"Manila",
	"14750000",
	"Mumbai",
	"14350000",
	"Delhi",
	"14300000",
	"Jakarta",
	"14250000"
};

class SingletonDatabase {

	SingletonDatabase() {
		cout << "Initializing database" << endl;

		for (int i = 0; i < sizeof(capitalstxt) / sizeof(string); i += 2)
			capitals[capitalstxt[i]] = stoi(capitalstxt[i + 1]);
	};

	map<string, int> capitals;

public:

	// constructors are deleted to avoid instansiating object
	SingletonDatabase(SingletonDatabase const&) = delete;
	void operator=(SingletonDatabase const&) = delete;
	
	// return static member
	static SingletonDatabase& get() {

		static SingletonDatabase db;

		return db;
	}

	int get_population(const string& name) { return capitals[name]; }

	void print() {
		for (auto& it : capitals)
			cout << it.first << " " << it.second << endl;
	}
};

int main() {

	string city = "Tokyo";
	auto pop = SingletonDatabase::get().get_population(city);
	cout << city << " has population " << pop << endl;

	return 0;
}
