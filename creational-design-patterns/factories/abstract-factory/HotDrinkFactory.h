#pragma once

#include "HotDrink.h"

// this is the abstract factory
struct HotDrinkFactory {
	virtual shared_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory {
	shared_ptr<HotDrink> make() const override {
		return make_shared<Tea>();
	}
};

struct CoffeeFactory : HotDrinkFactory {
	shared_ptr<HotDrink> make() const override {
		return make_shared<Coffee>();
	}
};