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

class LightSwitch;
struct State {
	virtual void on(LightSwitch* ls) { cout << "Light is already on" << endl; };
	virtual void off(LightSwitch* ls) { cout << "Light is already off" << endl; };
};

struct OnState : State {
	OnState() {
		cout << "Light is turned on" << endl;
	}

	void off(LightSwitch* ls) override;
};

struct OffState : State {
	OffState() {
		cout << "Light is turned off" << endl;
	}
	
	void on(LightSwitch* ls) override;	
};

class LightSwitch {
	State* state;
public:
	LightSwitch() {
		state = new OffState();
	}

	void setState(State* state) {
		this->state = state;
	}

	void on() {
		state->on(this);
	}

	void off() {
		state->off(this);
	}
};

int main() {

	LightSwitch ls;
	ls.on();
	ls.off();
	ls.off();

	return 0;
}


void OnState::off(LightSwitch* ls) {
	cout << "Switching light off..." << endl;
	ls->setState(new OffState());
	delete this;
};


void OffState::on(LightSwitch* ls) {
	cout << "Switching light on..." << endl;
	ls->setState(new OnState());
	delete this;
};

