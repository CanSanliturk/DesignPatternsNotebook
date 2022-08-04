#include <iostream>

using namespace std;

/*
idea of this principle is not creating interfaces too large
*/

struct Document { };


/*
commented-out part is the wrong approach. we have an interface for machine,
which will work perfectly for multipurpose machine. however, when we want a
single purpose machine, since we have to implement all methods, code will not
be expressive. scanner class should actually be responsible for scanning, but
it contains the other methods. we might not implement them or throw exception,
but code will not be clear. instead, we can segregate interfaces
*/
//struct IMachine {
//	virtual void print(Document& doc) = 0;
//	virtual void scan(Document& doc) = 0;
//	virtual void fax(Document& doc) = 0;
//};

//struct MultiFunctionPrinter : IMachine {
//	void print(Document& doc) override { /* do something */ }
//	void scan(Document& doc) override { /* do something */ }
//	void fax(Document& doc) override { /* do something */ }
//};

//struct Scanner : IMachine {
//	void print(Document& doc) override { /* don't do something! */ }
//	void scan(Document& doc) override { /* do something only here */ }
//	void fax(Document& doc) override { /* don't do something! */ }
//};

struct IPrinter {
	virtual void print(Document& doc) = 0;
};

struct IScanner {
	virtual void scan(Document& doc) = 0;
};

struct IFax {
	virtual void scan(Document& doc) = 0;
};

struct PrinterAndScanner : IPrinter, IScanner {
	IPrinter& printer;
	IScanner& scanner;

public:
	PrinterAndScanner(IPrinter& prnter, IScanner& scnnr) : printer(prnter), scanner(scnnr) { }	

	void print(Document& doc) override { /* do something */ }
	void scan(Document& doc) override { /* do something */ }

};

int main() {

	return 0;
}
