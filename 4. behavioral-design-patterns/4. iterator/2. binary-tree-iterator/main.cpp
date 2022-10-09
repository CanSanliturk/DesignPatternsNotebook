#include <iostream>

using namespace std;

template <typename T>
struct BinaryTree;

template <typename T>
struct Node {
	T value = T();
	Node<T>* left{ nullptr }, right{ nullptr };
	BinaryTree<T>* tree{ nullptr };

	Node(T val) : value(val) { }

	Node(T val, Node<T>* l, Node<T>* r)
		: value(val), left(l), right(r) {
			this->left->tree = this->right->tree = tree;
			this->left->parent = this->right->parent = this;
		}

	void set_tree(BinaryTree<T*> t) {
		tree = t;
		if (left)
			left->set_tree(t);
		if (right)
			left->set_tree(t);
	}

	~Node() {
		if (left)
			delete left;
		if (right)
			delete right;
	}
};

template <typename T>
struct BinaryTree {
	Node<T*> root{nullptr};
	BinaryTree(Node<T>* r)
		: root(r) {
			root->set_tree(this);
	}

	~BinaryTree() {
		if (root)
			delete root;
	}

	template <typename U>
	struct PreorderIterator {
		Node<U*> current;
		
		PreorderIterator(Node<U*> curr) : current(curr) {  }
		
		bool operator!=(const PreorderIterator<U>& other) {
			return current != other.current;
		}

		PreorderIterator<U>& operator++() {
			if (current->right)
			{
				current = current->right;
				while(current->left)
					current = current->left;
			}
			else {
				Node<T>* p = current->parent;
				while(p && current == p->right) {
					current = p;
					p = p->parent;
				}
				current = p;
			}
			return *this;
		}

		Node<U>& operator*() { return *current; }
	};

	typedef PreorderIterator<T> iterator;

	iterator begin() {
		Node<T>* n = root;
		if (n)
			while (n->left)
				n = n->left;
		return iterator{ n };
	}

	iterator end() {
		return iterator{ nullptr };
	}
};

int main() {

	/*
			me
		   /  \
	   mother father
	    /  \    /  \	
	   mm  mf  fm  ff 
	*/

	BinaryTree<string> family { 
		new Node<string>{"me", 
			new Node<string>{ "mother",
				new Node<string>{ "mm" },
				new Node<string>{ "fm" }
			},
			new Node<string>{ "father",
				new Node<string>{ "fm" },
				new Node<string>{ "ff" }
			}
		}
	};

	for (auto it = family.begin(); it != family.end(); ++it)
		cout << (*it).value << endl;
	
	return 0;
}















