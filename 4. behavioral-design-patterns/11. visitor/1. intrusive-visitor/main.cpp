#define _USE_MATH_DEFINES
#define _HAS_AUTO_PTR_ETC 1
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <tuple>
#include <sstream>
#include <memory>
#include <cmath>
#include <map>
#include <ostream>
#include <cstdint>
#include <functional>
#include <typeindex>
#include <any>

using namespace std;

struct Expression {
	virtual ~Expression() = default;
	virtual void print(ostringstream& oss) = 0;
};

// 1+2+3

struct DoubleExpression : Expression {
	double value;
	DoubleExpression(double value) : value(value) { }

	// this is called intrusive becuase we added print method later.
	// normally, printing should be seperate
	void print(ostringstream& oss) override { oss << value; }
};

struct AdditionExpression : Expression {
	// 1+2+3 can be represented as follows:
	//		+
	//	  1	  +
	//		 2  3
	Expression* left;
	Expression* right;

	AdditionExpression(Expression* left, Expression* right)
		: left(left), right(right) {  }

	~AdditionExpression() {
		delete left;
		delete right;
	}

	void print(ostringstream& oss) override { 
		oss << "(";
		left->print(oss);
		oss << "+";
		right->print(oss);
		oss << ")";
	}

};

int main() {

	// (1 + (2 + 3))
	auto e = new AdditionExpression(
		new DoubleExpression(1),
		new AdditionExpression(
			new DoubleExpression(2),
			new DoubleExpression(3)
		)
	);

	ostringstream oss;
	e->print(oss);
	cout << oss.str() << endl;

	return 0;
}
