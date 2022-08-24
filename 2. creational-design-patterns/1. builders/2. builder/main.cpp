#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

struct HtmlElement {
	string name;
	string text;
	vector<HtmlElement> elements;

	const size_t indent_size = 2;

	HtmlElement(const string& name, const string& text) : name(name), text(text) { }

	string str(int indent = 0) const {
		ostringstream oss;
		string i(indent_size * indent, ' ');
		oss << i << "<" << name << ">" << endl;
		if (text.size())
			oss << string(indent_size * (indent + 1), ' ') << text << endl;

		for (const auto& e : elements)
			oss << e.str(indent + 1);

		oss << i << "</" << name << ">" << endl;
		return oss.str();
	}
};

struct HtmlBuilder {
	HtmlElement root;
	HtmlBuilder(string root_name) : root(root_name, ""){
	}

	void add_child(string child_name, string child_text) {
		root.elements.emplace_back( HtmlElement(child_name, child_text) );
	}

	string str() const { return root.str(); }
};

int main() {

	HtmlBuilder builder{ "ul" };
	builder.add_child("li", "hello");
	builder.add_child("li", "world");
	cout << builder.str() << endl;

	return 0;
}