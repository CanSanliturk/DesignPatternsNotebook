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

enum class OutputFormat {
	markdown = 0,
	html
};

struct ListStrategy {
	virtual void start(ostringstream& oss) {  }
	virtual void addListItem(ostringstream& oss, const string& item);
	virtual void end(ostringstream& oss) {  }
};

struct MarkDownListStrategy : ListStrategy {
	void addListItem(ostringstream& oss, const string& item) override {
		oss << "* " << item << endl;
	}
};

struct HTMLListStrategy : ListStrategy {
	void start(ostringstream& oss) override {
		oss << "<ul>" << endl;		
	}

	void addListItem(ostringstream& oss, const string& item) override {
		oss << "	<li>" << item << "</li>" << endl;
	}

	void end(ostringstream& oss) override {
		oss << "</ul>" << endl;		
	}
};

struct TextProcessor {

	void clear() {
		oss.str("");
		oss.clear();
	}

	void appendList(const vector<string>& items) {
		listStrategy->start(oss);
		for (auto& item : items)
			listStrategy->addListItem(oss, item);
		listStrategy->end(oss);
	}

	void setOutputFormat(const OutputFormat& format) {
		switch (format) {
			case OutputFormat::markdown:
				listStrategy = make_unique<MarkDownListStrategy>();
				break;

			case OutputFormat::html:
				listStrategy = make_unique<HTMLListStrategy>();
				break;

			default:
				break;
		}
	}

	string str() const { return oss.str(); }

private:
	ostringstream oss;
	unique_ptr<ListStrategy> listStrategy;
};

int main() {

	vector<string> items { "foo", "bar", "baz" };
	
	TextProcessor tp;

	tp.setOutputFormat(OutputFormat::markdown);
	tp.appendList(items);
	cout << tp.str() << endl;

	tp.clear();
	
	tp.setOutputFormat(OutputFormat::html);
	tp.appendList(items);
	cout << tp.str() << endl;

	return 0;
}
