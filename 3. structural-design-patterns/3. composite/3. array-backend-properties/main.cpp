#include <array>
#include <iostream>

using namespace std;

/*
class Creature {
	int strength, agility, intelligence;

public:

	int get_strength() const { return strength; }
	int get_agility() const { return agility; }
	int get_intelligence() const { return intelligence; }

	void set_strength(int str) { this->strength  =  str; }
	void set_agility(int agl) { this->agility  =  agl; }
	void set_intelligence(int intel) { this->intelligence  =  intel; }

	// implementation below does not scale well
	double sum() const { return strength + agility + intelligence; }
	double average() const { return (sum() / 3.0); };
	int max() const { return  ::max(::max(strength, agility), intelligence); }

};
*/

class Creature {

	enum Abilities { str = 0, agl, intl, count };
	array<int, count> abilities;
public:
	int get_strength() const { return  abilities[str]; }
	void set_strength(int value) { abilities[str] = value; }

	int get_agility() const { return  abilities[agl]; }
	void set_agility(int value) { abilities[agl] = value; }

	int get_intelligence() const { return  abilities[intl]; }
	void set_intelligence(int value) { abilities[intl] = value; }

	int sum() const { return get_strength() + get_agility() + get_intelligence(); }
	double average() const { return sum() / (double)count; }
	int max() const { return *max_element(abilities.begin(), abilities.end()); }

};

int main() {

	Creature orc;
	orc.set_strength(16);
	orc.set_agility(11);
	orc.set_intelligence(9);

	cout << "The orc has an average stat of " << 
		orc.average() << " and max stat of " << 
		orc.max() << endl;

	return 0;
}