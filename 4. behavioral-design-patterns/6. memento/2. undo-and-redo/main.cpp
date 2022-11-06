#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <memory>

using namespace std;

class Memento {

	int balance;

public:

	Memento(int balance) : balance(balance) { };

	friend class BankAccount;
};

class BankAccount {

	int balance { 0 };
	vector<shared_ptr<Memento>> changes;
	int current;

public:

	BankAccount(int balance) : balance(balance) {
		changes.emplace_back(make_shared<Memento>(balance));
		current = 0;
	}

	shared_ptr<Memento> deposit(int amount) {
		balance += amount;
		changes.push_back(make_shared<Memento>(balance));
		++current;
		return changes.at(changes.size() - 1);
	}

	void restore(const shared_ptr<Memento> m) {
		if (m) {
			balance = m->balance;
			changes.push_back(m);
			current = changes.size() - 1;
		}
	}

	shared_ptr<Memento> undo() {
		if (current) {
			--current;
			auto m = changes[current];
			balance = m->balance;
			return m;
		}
		return {};
	}

	shared_ptr<Memento> redo() {
		if (current + 1 < changes.size()) {
			++current;
			auto m = changes[current];
			balance = m->balance;
			return m;
		}
		return {};
	}

	friend ostream& operator<<(ostream& os, BankAccount& account) {
		os << "balance: " << account.balance;
		return os;
	}

};

int main() {

	BankAccount ba { 100 };
	cout << "initial state: " << ba << endl;

	ba.deposit(50);
	cout << "first deposit: " << ba << endl;

	ba.deposit(25);
	cout << "second deposit: " << ba << endl;

	ba.undo();
	cout << "after undo: " << ba << endl;

	ba.redo();
	cout << "after redo: " << ba << endl;

	return 0;
}