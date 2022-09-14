#include <iostream>
#include <string>

using namespace std;

struct Pingable {
	virtual wstring ping(const wstring& message) = 0;
};

struct Pong : Pingable {
	wstring ping(const wstring& message) override {
		return message + L" pong";
	}
};

void tryit(Pingable& pp) {
	wcout << pp.ping(L"ping") << endl;
}

int main() {

	Pong pp;
	for (int i = 0; i < 3; ++i)
		tryit(pp);

	return 0;
}