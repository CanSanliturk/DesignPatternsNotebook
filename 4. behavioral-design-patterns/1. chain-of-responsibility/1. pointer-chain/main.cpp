#include <iostream>

using namespace std;

struct Creature {
	string name;
	int attack, defense;
	Creature(const string& name, int attack, int defense)
		: name(name), attack(attack), defense(defense) { }


	friend ostream& operator <<(ostream& os, const Creature& creature) {
		os << "name: " << creature.name << " attack: " << creature.attack 
			<< " defense: " << creature.defense;
		return os;
	}
};

class CreatureModifier {
	CreatureModifier* next { nullptr };
protected:
	Creature& creature;
public:
	CreatureModifier(Creature& creature) : creature(creature) {  }

	void add(CreatureModifier* cm) {
		if(next)
			next->add(cm);
		else
			next = cm;
	}

	virtual void handle() {
		if (next)
			next->handle();
	}
};

class DoubleAttackModifier : public CreatureModifier {
public:
	DoubleAttackModifier(Creature& creature) : CreatureModifier(creature) { }
	void handle() override {
		creature.attack *= 2;
		CreatureModifier::handle(); // this is the important part
	}
};

class IncreasedDefenseModifier : public CreatureModifier {
public:
	IncreasedDefenseModifier(Creature& creature) : CreatureModifier(creature) { }
	void handle() override {
		if (creature.attack < 3)
			creature.defense++;
		CreatureModifier::handle();
	}
};

class NoBonusesModifier : public CreatureModifier {
public:
	NoBonusesModifier(Creature& creature) : CreatureModifier(creature) { }
	void handle() override { } // cancel base class implementation
};


int main() {

	Creature goblin("Goblin", 1, 1);
	CreatureModifier root(goblin);
	DoubleAttackModifier r1(goblin);
	DoubleAttackModifier r1_2(goblin);
	IncreasedDefenseModifier r2(goblin);

	/*
	STOPPER
	NoBonusesModifier curse(goblin);
	root.add(&curse);
	*/

	root.add(&r1);
	root.add(&r1_2);
	root.add(&r2);

	root.handle();

	cout << goblin << endl;

	return 0;
}
