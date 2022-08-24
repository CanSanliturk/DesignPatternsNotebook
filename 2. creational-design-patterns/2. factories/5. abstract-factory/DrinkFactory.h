#pragma once

#include "HotDrinkFactory.h"
#include <map>
#include <functional>

using namespace std;

class DrinkFactory {
	map<string, shared_ptr<HotDrinkFactory>> hot_factories;
public:
	DrinkFactory() { 
		hot_factories["coffee"] = make_shared<CoffeeFactory>();
		hot_factories["tea"] = make_shared<TeaFactory>();
	}

	shared_ptr<HotDrink> make_drink(const string& name, int vol) {
		auto drink = hot_factories[name]->make();
		drink->prepare(vol);
		return drink;
	}
};

// this class is for functional factory
class DrinkWithVolumeFactory {

	map<string, function<shared_ptr<HotDrink>()>> factories;
public:
	DrinkWithVolumeFactory() {
		factories["tea"] = [](){ 
			auto tea = make_shared<Tea>();
			tea->prepare(200);
			return tea;
		};
		factories["coffee"] = [](){ 
			auto coffee = make_shared<Coffee>();
			coffee->prepare(200);
			return coffee;
		};
	}

	shared_ptr<HotDrink> make_drink(const string& name) {
		return factories[name]();	
	}
};