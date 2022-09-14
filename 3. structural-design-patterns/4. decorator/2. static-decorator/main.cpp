#include <string>
#include <iostream>

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

// mixin inheritance
// perfect forward

/*
with the template approach, we can decorate classes and call underlying objects
specific methods. however, if we want to restraint template type T to some classes,
we can use C++ 20 feature, concepts
*/


template <typename T>
concept IsAShape = std::is_base_of<Shape, T>::value;

template <IsAShape T>
struct ColoredShape2 : T {
	string color;
	
	ColoredShape2() { }
	
	template <typename ...Args>
	ColoredShape2(const string& color, Args ...args)
		: T(forward<Args>(args)...), color{color} { }

	string str() const override {
		string res = "";
		res += T::str() + " has the color " + color;
		return res;
	}
};


int main() {

	ColoredShape2<Circle> green_circle("green", 5);
	cout << green_circle.str() << endl;

	
	return 0;
}
