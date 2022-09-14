#include <string>
#include <iostream>
#include <ostream>

using namespace std;

struct Shape {
	virtual string str() const = 0;
};

struct Circle : Shape {
	float radius;

	Circle() { }

	Circle(float r) : radius(r) { }

	void resize(float factor) { radius *= factor; }

	string str() const override {
		string str =  "A circle of radius ";
		str += to_string(radius);
		return str;
	}
};

struct Square : Shape {
	float side;

	Square() { }

	Square(int sideLen) : side(sideLen) {  }

	string str() const override {
		string str =  "A square of side ";
		str += to_string(side);
		return str;
	}
};

struct ColoredShape : Shape {
	Shape& shape;
	string color;

	ColoredShape(Shape& shape, const string& color) : shape(shape), color(color) { }

	string str() const override {
		string str =  shape.str() + " has the color " + color;
		return str;
	}
};

struct TransparentShape : Shape {
	Shape& shape;
	uint8_t transparency;

	TransparentShape(Shape& shape, uint8_t transparency) : shape(shape), transparency(transparency) { }

	string str() const override {
		return shape.str() + " has " + to_string(static_cast<float>(transparency) / 255.0f * 100.0f) + "% transparency";
	};
};

int main() {
	
	Square square{ 5 };
	ColoredShape red_square{square, "red"};
	cout << square.str() << endl << red_square.str() << endl;

	TransparentShape my_square{red_square, 51};
	cout << my_square.str() << endl;

	// note that we cannot call resize method of circle on colored shape (red_square)

	return 0;
}