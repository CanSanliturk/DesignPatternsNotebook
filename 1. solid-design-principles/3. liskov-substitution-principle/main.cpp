#include <iostream>

using namespace std;

// barbara liskov (?)

// goal is subtypes should be substitutible by base types

class Rectangle {
protected:
	int width;
	int height;

public:
	Rectangle(int w, int h) : width(w), height(h) { }
	
	int getWidth() const { return width; }
	virtual void setWidth(int w) { width = w; }

	int getHeight() const { return height; }
	virtual void setHeight(int h) { height = h; }

	int area() const { return width * height; }
};

void process(Rectangle& r) {
	auto w = r.getWidth();
	r.setHeight(10);
	cout << "expected area = " << (w * 10) << ", got " << r.area() << endl;
}

/*
class Square : public Rectangle {
public:
	Square(int size) : Rectangle(size, size) { }

	by overriding methods like this, methods will behave differently and liskov
	substituion is broken
	void setWidth(int width) override { this->width = this->height = width; }
	void setHeight(int height) override { this->width = this->height = width; }
};
*/

// this would work
struct RectangleFactory {
	static Rectangle createRectangle(int w, int h) { return Rectangle(w, h); };
	static Rectangle createSquare(int size) { return Rectangle(size, size); };
};

int main() {
	Rectangle r(3, 4);
	process(r);

/*
	Square s(5);
	process(s);
*/

	return 0;
}