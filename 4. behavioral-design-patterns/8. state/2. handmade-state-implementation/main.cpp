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

enum State {
	offHook = 0,
	connecting,
	connected,
	onHold,
	onHook
};

inline ostream& operator<<(ostream& os, const State& s) {
	switch(s) {
		case State::offHook:
			os << "off the hook";
			break;
		case State::connecting:
			os << "connecting";
			break;
		case State::connected:
			os << "connected";
			break;
		case State::onHold:
			os << "on hold";
			break;
		case State::onHook:
			os << "on hook";
			break;
		default:
			break;
	}
	return os;
}

enum class Trigger {
	callDialed = 0,
	hungUp,
	callConnected,
	placedOnHold,
	takenOffHold,
	leftMessage,
	stopUsingPhone
};


inline ostream& operator<<(ostream& os, const Trigger& t) {
	switch(t) {
		case Trigger::callDialed:
			os << "call dialed";
			break;
		case Trigger::hungUp:
			os << "hung up";
			break;
		case Trigger::callConnected:
			os << "call connected";
			break;
		case Trigger::placedOnHold:
			os << "placed on hold";
			break;
		case Trigger::takenOffHold:
			os << "taken off hold";
			break;
		case Trigger::leftMessage:
			os << "left message";
			break;	
		case Trigger::stopUsingPhone:
			os << "putting phone on book";
			break;
		default:
			break;
	}
	return os;
}

int main() {

	map<State, vector<pair<Trigger, State>>> rules {
		{ State::offHook, {{ Trigger::callDialed, State::connecting }, { Trigger::stopUsingPhone, State::onHook }} },
		{ State::connecting, {{ Trigger::hungUp, State::offHook }, { Trigger::callConnected, State::connected }} },
		{ State::connected, {{ Trigger::leftMessage, State::offHook }, { Trigger::hungUp, State::offHook }, { Trigger::placedOnHold, State::onHold }} },
		{ State::onHold, {{ Trigger::takenOffHold, State::connected }, { Trigger::hungUp, State::offHook }} }
	};

	State currentState { State::offHook };
	State exitState { State::onHook };

	while(true) {
		cout << "The phone is currently" << currentState << endl;
	selectTrigger:
			cout << "Select a trigger: " << endl;

			int i = 0;
			for (auto item : rules[currentState])
				cout << i++ << ". " << item.first << endl; 

			int input;
			cin >> input;
			if (input < 0 || input + 1 > rules[currentState].size())
			{
				cout << "Incorrect option. Please try again." << endl;
				goto selectTrigger;
			}

			currentState = rules[currentState][input].second;
			if (currentState == exitState)
				break;
	}

	cout << "We are done using phone." << endl;

	return 0;
}






















