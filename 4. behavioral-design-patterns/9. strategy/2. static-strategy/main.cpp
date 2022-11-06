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

template <typename LS>
struct TextProcessor {

	void clear() {
		oss.str("");
		oss.clear();
	}

	void appendList(const vector<string>& items) {
		listStrategy.start(oss);
		for (auto& item : items)
			listStrategy.addListItem(oss, item);
		listStrategy.end(oss);
	}

	string str() const { return oss.str(); }

private:
	ostringstream oss;
	LS listStrategy;
};

int main() {

	vector<string> items { "foo", "bar", "baz" };
	
	TextProcessor<MarkDownListStrategy> tpm;
	tpm.appendList(items);
	cout << tpm.str() << endl;

	TextProcessor<HTMLListStrategy> tph;
	tph.appendList(items);
	cout << tph.str() << endl;

	return 0;
}
