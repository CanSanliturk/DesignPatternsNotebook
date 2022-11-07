#include <map>
#include <sstream>
#include <iostream>
#include <typeindex>

using namespace std;

struct GameObject;
void collide(GameObject& first, GameObject& second);

struct GameObject {
	virtual type_index type() const = 0;

	virtual void collide(GameObject& other) {
		::collide(*this, other);
	}
};

// CRTP
template <typename T>
struct GameObjectImpl : GameObject {
	type_index type() const override {
		return typeid(T);
	}
};

struct Planet : GameObjectImpl<Planet> { };
struct Asteroid : GameObjectImpl<Asteroid> { };
struct Spaceship : GameObjectImpl<Spaceship> { };

void spaceship_planet() { cout << "spaceship lands on a plant" << endl; }
void asteroid_planet() { cout << "asteroid burns up in the atmosphere" << endl; }
void asteroid_spaceship() { cout << "asteroid hits and destroys spaceship" << endl; }

map<pair<type_index, type_index>, void(*)(void)> outcomes {
	{ { typeid(Spaceship), typeid(Planet) }, spaceship_planet },
	{ { typeid(Asteroid), typeid(Planet) }, asteroid_planet },
	{ { typeid(Asteroid), typeid(Spaceship) }, asteroid_spaceship }
};

void collide(GameObject& first, GameObject& second) {
	auto it = outcomes.find({ first.type(), second.type() });
	if (it == outcomes.end())
	{
		it = outcomes.find({ second.type(), first.type() });
		if (it == outcomes.end())
		{
			cout << "objects pass each other harmlessly" << endl;
			return;
		}
	}
	it->second();
}

int main() {

	Spaceship ss;
	Asteroid as;
	Planet pt;

	collide(pt, ss);
	collide(pt, as);
	collide(ss, as);
	collide(pt, pt);

	return 0;
}
