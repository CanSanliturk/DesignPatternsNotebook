#include <iostream>
#include <cmath>

using namespace std;

class Point {

	// this is private, cannot be used from outside
	Point(float x, float y) : x(x), y(y) { }

public:
	float x, y;

	/* 
		NewCartesian and NewPolar methods are factory methods whose names are descriptive
		and arguments are well-defined.
	*/

	static Point NewCartesian(float x, float y) {
		return {x, y};
	}

	static Point NewPolar(float rho, float theta) {
		return { rho * cos(theta), rho * sin(theta) };
	}
};

int main() {

	auto polarPoint = Point::NewPolar(5, 3.14 * 0.25);
	auto cartesianPoint = Point::NewCartesian(2, 3);
	return 0;
}