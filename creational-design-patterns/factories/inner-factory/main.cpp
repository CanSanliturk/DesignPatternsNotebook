#include <iostream>
#include <cmath>

using namespace std;

/*
	what can be done to overcome the problem of violating OCP (see factory directory under factories directory)
	is moving factory class to Point class to make it an inside class, which can access the private members of the
	outer class. if outer class stores a single instance of inner class only via using static keyword, problem solved.
*/

class Point {
	
	Point(float x, float y) : x(x), y(y) { }
	float x, y;

	class PointFactory {

		PointFactory () { }
public:
		static Point NewCartesian(float x, float y) {
			return {x, y};
		}

		static Point NewPolar(float rho, float theta) {
			return { rho * cos(theta), rho * sin(theta) };
		}
	};

public:
	static PointFactory factory;
};

int main() {

	auto p = Point::factory.NewPolar(1, 1);

	return 0;
}