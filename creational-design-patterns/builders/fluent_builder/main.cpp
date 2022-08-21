#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class HtmlElement {
	friend class HtmlBuilder;
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

	/*
	implementation below wont work but since it requires forward declaration etc, but if we
	have done that, we could have done something like

	auto builder = HtmlElement::build("ul").add_child("li", "hello").add_child("li", "world");

	static HtmlBuilder build(string root_name) {
		return { root_name };
	}
	*/
};

struct HtmlBuilder {
	HtmlElement root;
	HtmlBuilder(string root_name) : root(root_name, ""){
	}

	// since this method now returns object itself, we can call method fluently
	HtmlBuilder& add_child(string child_name, string child_text) {
		root.elements.emplace_back( HtmlElement(child_name, child_text) );
		return *this;
	}

	string str() const { return root.str(); }
};

int main() {

	HtmlBuilder builder{ "ul" };

	// pay attention to how the method is called fluently
	builder.add_child("li", "hello").add_child("li", "world");
	cout << builder.str() << endl;

	return 0;
}