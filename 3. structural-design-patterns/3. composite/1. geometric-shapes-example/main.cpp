#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct GraphicObject {
	virtual void draw() = 0;
};

struct Circle : GraphicObject {
	void draw() override {
		cout << "Circle" << endl;
	}
};

struct Group : GraphicObject {
	string name;

	vector<GraphicObject*> objects;


	Group(const string& name) : name(name) { }

	void draw() override {
		cout << "Group " << name << " contains: " << endl;
		for (auto&& o : objects)
			o->draw();
	}
};

int main() {

	Group root("root");
	Circle c1, c2;
	root.objects.push_back(&c1);

	Group sub("sub");
	sub.objects.push_back(&c2);

	root.objects.push_back(&sub);

	root.draw();

	return 0;
}