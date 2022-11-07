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
};

// 1+2+3

struct DoubleExpression : Expression {
	double value;
	DoubleExpression(double value) : value(value) { }
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
};

struct ExpressionPrinter {
	ostringstream oss;

	void print(Expression* e) {

		// downside
		// 		* dynamic cast is runtime expensive
		// 		* we might forget to write something

		if (auto de = dynamic_cast<DoubleExpression*>(e)) {
			oss << de->value;
		}
		else if (auto ae = dynamic_cast<AdditionExpression*>(e)) {
			oss << "(";
			print(ae->left);
			oss << "+";
			print(ae->right);
			oss << ")";
		}

	}

	string str() const { return oss.str(); }
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

	ExpressionPrinter ep;
	ep.print(e);
	cout << ep.str() << endl;

	delete e;

	return 0;
}
