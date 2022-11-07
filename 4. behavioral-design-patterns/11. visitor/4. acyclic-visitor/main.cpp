#include <sstream>
#include <iostream>

using namespace std;

template <typename Visitable>
struct Visitor {
	virtual void visit(Visitable& obj) = 0;
};

struct VisitorBase {
	virtual ~VisitorBase() = default;
};

struct Expression {
	virtual ~Expression() = default;

	// we want to make sure that visitor base is of Visitor<T>
	virtual void accept(VisitorBase& obj) {
		if (auto ev = dynamic_cast<Visitor<Expression>*>(&obj))
			ev->visit(*this);
	}
};

struct DoubleExpression : Expression {
	double value;

	DoubleExpression(double value) : value(value) { }
	
	void accept(VisitorBase& obj) override {
		if (auto dev = dynamic_cast<Visitor<DoubleExpression>*>(&obj))
			dev->visit(*this);
	}	
};

struct AdditionExpression : Expression {
	Expression* left; 
	Expression* right; 

	AdditionExpression(Expression* left, Expression* right)
		: left(left), right(right) {  }

	~AdditionExpression() {
		delete left;
		delete right;
	}

	void accept(VisitorBase& obj) override {
		if (auto dev = dynamic_cast<Visitor<AdditionExpression>*>(&obj))
			dev->visit(*this);
	}
};

struct ExpressionPrinter
	: VisitorBase, Visitor<DoubleExpression>, Visitor<AdditionExpression> {

	void visit(DoubleExpression& obj) override {
		oss << obj.value;
	}

	void visit(AdditionExpression& obj) override {
		oss << "(";
		obj.left->accept(*this);
		oss << "+";
		obj.right->accept(*this);
		oss << ")";
	}

	string str() const { return oss.str(); }

private:

	ostringstream oss;

};

int main() {

	auto e = new AdditionExpression(
		new DoubleExpression(1),
		new AdditionExpression(
			new DoubleExpression(2),
			new DoubleExpression(3)
		)
	);

	ExpressionPrinter ep;
	ep.visit(*e);
	cout << ep.str() << endl;

	return 0;
}
