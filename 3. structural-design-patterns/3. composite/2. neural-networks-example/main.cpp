#include <vector>
#include <iostream>

using namespace std;

// CRTP
template <typename Self>
struct SomeNeurons {
	template <typename T> void connect_to(T& other) {
		for (Neuron& from : *static_cast<Self*>(this))
		{
			for (Neuron& to : other)
			{
				from.push_back(&to);
				to.in.push_back(&from);
			}
		}
	}
};

struct Neuron : SomeNeurons<Neuron>{
	vector<Neuron*> in, out;
	unsigned int id;

	Neuron() {
		static int id{1};
		this->id = id++;
	}

	Neuron* begin() { return this; }
	Neuron* end() { return this + 1; }

	friend ostream &operator<<(ostream& os, const Neuron& neuron) {
		for (auto n : neuron.in)
			os << n->id << "\t-->\t[" << neuron.id << "]" << endl;

		for (auto n : neuron.out)
			os << "[" << neuron.id << "]\t-->\t" << n->id << endl;
		
		return os;
	}
};

struct NeuronLayer : vector<Neuron>, SomeNeurons<NeuronLayer> {
	NeuronLayer(int count) {
		while (count --> 0)
			emplace_back(Neuron{});
	}

	friend ostream& operator<<(ostream& os, const NeuronLayer& obj) {
		for (auto n : obj)
			os << n;
		return os;
	}
};

int main() {

	// scenario 1
	Neuron n1, n2;
	n1.connect_to(n2);
	cout << n1 << n2 << endl;

	// scenario 2
	NeuronLayer layer1(2), layer2(3);
	n1.connect_to(layer1);
	layer2.connect_to(n2);

	return 0;
}