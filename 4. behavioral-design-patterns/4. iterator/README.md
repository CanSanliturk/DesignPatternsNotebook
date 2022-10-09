# MOTIVATION

* Iterator (traversal) is a core functionality of various data structures

* An iterator is a class that facilitates the traversal

	* Keeps a reference to the current element

	* Knows how to move to a different element

* Can be used implicitly

	* Range-based for

	* Coroutines

# DEFINITION

* An object that facilitates the traversal of the data structure

# SUMMARY

* An object can be iterated (traversed) if it defines a begin()/end() pair

* An iterator specified how you can traverse an object

* Typically requires of != and ++ operators

* ++ is called sporacilly, so cannot be recursive, but...
	
	* Coroutines allow recursion throught generator-yielding functions
