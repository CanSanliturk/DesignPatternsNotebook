#include <tuple>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

/*
First Motivation: High-level modules should not depend on low-level modules. Both should depend
on abstractions.

Second Motivation: Abstractions should not depend on details. Details should depend on abstractions.
*/

/*
Commented-out part violates dependency inversion principle. it is a high-level module,
but it depends on the fact that relations field of Relationships class is public and 
its type is vector. however, both can change.

enum class Relationship {
	parent,
	child,
	sibling
};

struct Person {
	string name;
};

struct Relationships { // low-level 
	vector<tuple<Person, Relationship, Person>> relations;

	void addParentAndChild(const Person& parent, const Person& child) {
		relations.push_back({parent, Relationship::parent, child});
		relations.push_back({child, Relationship::child, parent});
	}
};

struct Research { // high-level
	Research(Relationships& relationships) {
		for (auto&& [first, rel, second] : relationships.relations)
			if (first.name == "John" && rel == Relationship::parent)
				cout << "John has a child called " << second.name << endl;
	}
};
*/

enum class Relationship {
	parent,
	child,
	sibling
};

struct Person {
	string name;
};

struct RelationshipBrowser {
	virtual vector<Person> findAllChildrenOf(const string& name) = 0;
};

struct Relationships : RelationshipBrowser{ // low-level 
	vector<tuple<Person, Relationship, Person>> relations;

	void addParentAndChild(const Person& parent, const Person& child) {
		relations.push_back({parent, Relationship::parent, child});
		relations.push_back({child, Relationship::child, parent});
	}

	vector<Person> findAllChildrenOf(const string& name) override {
		vector<Person> result;

		for (auto&& [first, rel, second] : relations)
			if (first.name == name && rel == Relationship::parent)
				result.push_back(second);

		return result;
	}
};

struct Research {
	Research(RelationshipBrowser& browser) {
		for (auto& child : browser.findAllChildrenOf("John"))
			cout << "John has a child called " << child.name << endl;
	}
};

int main() {

	Person parent{"John"};
	Person child1{"Chris"}, child2{"Matt"};

	Relationships relationships;
	relationships.addParentAndChild(parent, child1);
	relationships.addParentAndChild(parent, child2);

	Research _(relationships);

	return 0;
}
