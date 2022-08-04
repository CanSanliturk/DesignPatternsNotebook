#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum class Color {
	red, green, blue
};

enum class Size {
	small, medium,large
};

struct Product {
	string name;
	Color color;
	Size size;
};

/*
struct ProductFilter {

	// this only filters by color. for filtering by size, we need another function
	// which is copy of this. which means new interface for clients etc. this does
	// not scale well. open-closed principles says code must be open to extension but
	// closed to modification. with this approach, we always modify existing classes
	vector<Product*> by_color(vector<Product*>& items, Color color) {
		vector<Product*> result;
		for (auto& p : items)
			if (p->color == color)
				result.push_back(p);
		return result;
	}
};
*/

/*
with the following approach, a generic filter is written. any specification that overrides
specification interface will work fine. this will result in adding new code, not modifying
the existing one. thus, our code is open to extension but closed to modification
*/

template<typename T> 
struct Specification {
	virtual bool isSatisfied(T* item) = 0;
};

template<typename T> 
struct Filter {
	virtual vector<T*> filter(vector<T*> items, Specification<T>& spec) = 0;
};

struct BetterFilter : Filter<Product> {
	vector<Product*> filter(vector<Product*> items, Specification<Product>& spec) override {
		vector<Product*> result;

		for (auto item : items)
			if (spec.isSatisfied(item))
				result.push_back(item);

		return result;
	}
};

struct ColorSpecification : Specification<Product> {
	Color color;
	ColorSpecification(Color color) : color(color) { }
	bool isSatisfied(Product* item) override {
		return item->color == color;
	}
};

struct SizeSpecification : Specification<Product> {
	Size size;
	SizeSpecification(Size size) : size(size) { }
	bool isSatisfied(Product* item) override {
		return item->size == size;
	}
};

template <typename T>
struct AndSpecification : Specification<T> {
	Specification<T>& first;
	Specification<T>& second;
	AndSpecification(Specification<T>& f, Specification<T>& s) : first(f), second(s) { }
	bool isSatisfied(Product* item) override {
		return first.isSatisfied(item) && second.isSatisfied(item);
	}
};

int main() {

	Product apple{ "Apple", Color::green, Size::small };
	Product tree{ "Tree", Color::green, Size::large };
	Product house{ "House", Color::blue, Size::large };
	vector<Product*> products{ &apple, &tree, &house };

	BetterFilter bf;

	ColorSpecification greenFilter(Color::green);
	auto greenItems = bf.filter(products, greenFilter);
	for (auto gi : greenItems)
		cout << gi->name << " is green" << endl;

	SizeSpecification largeFilter(Size::large);
	auto largeItems = bf.filter(products, largeFilter);
	for (auto li : largeItems)
		cout << li->name << " is large" << endl;

	AndSpecification<Product> greenAndLargeFilter(greenFilter, largeFilter);
	auto greenAndLargeItems = bf.filter(products, greenAndLargeFilter);
	for (auto gli : greenAndLargeItems)
		cout << gli->name << " is green and large" << endl;

	return 0;
}
