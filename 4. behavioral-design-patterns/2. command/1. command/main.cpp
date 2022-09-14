#include <vector>
#include <iostream>

using namespace std;

struct BankAccount {
	int balance{ 0 };
	int overdraft_limit{ -500 };

	void deposit(int amount) {
		balance += amount;
		cout << "deposited " << amount
			<< ", balance is now " << balance << endl;
	}

	bool withdraw(int amount) {
		if (balance - amount >= overdraft_limit)
		{
			balance -= amount;
			cout << "withdrew " << amount
				<< ", balance is now " << balance << endl;
			return true;
		}
		return false;
	}

	friend ostream& operator<<(ostream& os, BankAccount ba) {
		os << "balance: " << ba.balance;
		return os;
	}
};

struct Command {
	bool succeeded;
	virtual void call() = 0;
	virtual void undo() = 0;
};

struct BankAccountCommand : Command {
	BankAccount& account;
	enum Action { deposit, withdraw } action;
	int amount;

	BankAccountCommand(BankAccount& account, Action action, int amount)
		: account(account), action(action), amount(amount) {  succeeded = false; }

	void call() override { 
		switch (action) {
			case deposit:
				account.deposit(amount);
				succeeded = true;
				break;
			case withdraw:
				succeeded = account.withdraw(amount);
				break;
		}
	}

	void undo() override { 

		if (!succeeded)
			return;

		switch (action) {
			case deposit:
				account.withdraw(amount);
				break;
			case withdraw:
				account.deposit(amount);
				break;
		}
	}
};

struct CompositeBankAccountCommand : vector<BankAccountCommand>, Command {
	CompositeBankAccountCommand(const initializer_list<BankAccountCommand>& items) : vector(items) { }

	void call() override {
		for (auto& cmd : *this)
			cmd.call();
	}

	void undo() override {
		for (auto it = rbegin(); it != rend(); ++it)
			it->undo();	
	}
};

struct MoneyTransferCommand : CompositeBankAccountCommand {
	MoneyTransferCommand(BankAccount& from, BankAccount& to, int amount) 
		: CompositeBankAccountCommand(
			{
				BankAccountCommand(from, BankAccountCommand::withdraw, amount),
				BankAccountCommand(to, BankAccountCommand::deposit, amount)
			}
			) 
		{ }
};

int main() {

	BankAccount ba, ba2;
	ba.deposit(100);
	MoneyTransferCommand cmd{ ba, ba2, 50 };
	cmd.call();
	cout << ba << endl << ba2 << endl;
	cmd.undo();
	cout << ba << endl << ba2 << endl;

	return 0;
}
