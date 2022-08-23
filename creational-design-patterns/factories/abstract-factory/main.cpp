#include "DrinkFactory.h"

// this would work, but we have factory abstract factory already
shared_ptr<HotDrink> make_drink(string type, int vol) {
	shared_ptr<HotDrink> drink;

	if (type == "tea")
		drink = make_shared<Tea>();
	else
		drink = make_shared<Coffee>();
	drink->prepare(vol);

	return drink;
}

int main() {

	// with bad method
	auto d = make_drink("tea", 200);

	// with abstract factory
	DrinkFactory df;
	auto c = df.make_drink("coffee", 200);

	// with functional factory
	DrinkWithVolumeFactory dwvf;
	auto t = dwvf.make_drink("tea");

	return 0;
}