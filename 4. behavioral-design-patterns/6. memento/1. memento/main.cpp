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

	int balance = 0;

public:

	BankAccount(int balance) : balance(balance) { }

	Memento deposit(int amount) {
		balance += amount;
		return balance;
	}

	void restore(const Memento& m) {
		balance = m.balance;
	}

	friend ostream& operator<<(ostream& os, const BankAccount& account) {
		os << "balance: " << account.balance;
		return os;
	}
};



int main() {

	BankAccount ba(100);
	auto m1 = ba.deposit(50);
	auto m2 = ba.deposit(25);

	cout << ba << endl;
	
	cout << "back to m1" << endl;
	ba.restore(m1);
	cout << ba << endl;

	cout << "back to m2" << endl;
	ba.restore(m2);
	cout << ba << endl;

	return 0;
}