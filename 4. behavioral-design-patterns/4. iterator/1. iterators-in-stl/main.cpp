#include <vector>
#include <iostream>

using namespace std;

int main() {
	vector<string> names { "john", "jane", "jill", "jack" };
	vector<string>::iterator it = names.begin();
	cout << "first name is " << *it << endl;
	++it;
	it->append(" goodall");
	cout << "second name is " << *it << endl;
	
	while (++it != names.end())
		cout << "name is " << *it << endl;

	cout << "names in reverse order" << endl;
	for (auto ri = names.rbegin(); ri != names.rend(); ++ri)
		cout << *ri << endl;

	vector<string>::const_reverse_iterator jack = names.crbegin();
	// cannot modify this one

	return 0;
}