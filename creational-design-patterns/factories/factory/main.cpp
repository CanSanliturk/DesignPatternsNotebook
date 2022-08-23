#include <iostream>
#include <cmath>

using namespace std;

class Point {
	
	/*
		this violates Open-Closed Principle. if constructor was public, then this wouldn't be
		needed. 
	*/
	friend class PointFactory; 

	// this is private, cannot be used from outside
	Point(float x, float y) : x(x), y(y) { }

public:
	float x, y;
};

struct PointFactory {

	static Point NewCartesian(float x, float y) {
		return {x, y};
	}

	static Point NewPolar(float rho, float theta) {
		return { rho * cos(theta), rho * sin(theta) };
	}
};

int main() {

	auto polarPoint = PointFactory::NewPolar(5, 3.14 * 0.25);
	auto cartesianPoint = PointFactory::NewCartesian(2, 3);
	return 0;
}