#include <iostream>

using namespace std;

class Game {

protected:
	int numberOfPlayers;
	virtual void start() = 0;
	virtual bool haveWinner() = 0;
	virtual void takeTurn() = 0;
	virtual int getWinner() = 0;
	int currentPlayer;

public:
	Game(int numOfPlayers) : numberOfPlayers(numOfPlayers) { }
	void run() {
		start();
		while (!haveWinner())
			takeTurn();
		cout << "Player " << getWinner() << " wins." << endl;
	}
};

class Chess : public Game {

	int turn = 0;
	int maxNumOfTurn = 10;

protected:
	void start() override {
		cout << "Starting a game of chess with " << numberOfPlayers << endl;
	}

	bool haveWinner() override {
		return turn == maxNumOfTurn;
	}

	void takeTurn() override {
		cout << "Turn " << turn << " taken by player " << currentPlayer << endl;
		++turn;
		currentPlayer = (currentPlayer + 1) % 2;
	}

	int getWinner() override {
		return 0;
	}

public: 
	Chess() : Game(2) { Game::currentPlayer = 0; }
};

int main() {

	Chess c;
	c.run();

	return 0;
}