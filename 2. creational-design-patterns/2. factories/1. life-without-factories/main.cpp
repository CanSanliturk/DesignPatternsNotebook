#include <iostream>
#include <cmath>

using namespace std;

enum class PointType {
	cartesian,
	polar
};

struct Point {
	float x, y;
/*
	// constuctor for cartesian coordinates
	Point(float x, float y) : x(x), y(y) { }

	we cannot overload constructor with same set of arguments. So, we cannot
	have a seperate constructor for polar coordinates

	// constructor for polar coordinates
	Point(float rho, float thete) { }	
*/

/*
	having an enum class to state the type of point will reduce number of constructors to one.
	however, arguments names are not descriptive for this case.
*/
	
	Point(float a, float b, PointType type = PointType::cartesian) {
		if (type == PointType::cartesian)
		{
			x = a;
			y = b;
		}
		else {
			x = a * cos(b);
			y = a * sin(b);
		}
	}
};

int main() {
	return 0;
}