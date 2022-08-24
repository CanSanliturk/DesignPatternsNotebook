#include <string>
#include <sstream>
#include <iostream>

using namespace std;

int main() {

	// assume we are writing a backend server that returns an HTML text as string.
	auto text = "hello";
	string output;
	output += "<p>";
	output += text;
	output += "</p>";
	cout << output << endl;

	// this approach does not really scale. for example, add list arguments
	string words[] = { "hello", "world" };
	ostringstream oss;
	oss << "<ul>";
	for (auto& w : words)
		oss << "	<li>" << w << "</li>" << endl;
	oss << "</ul" << endl;
	cout << oss.str() << endl;

	// with builders, we can define oop design that can transform this straightforward,
	// unscaleable approach to a well-defined set of procedures.

	return 0;
}