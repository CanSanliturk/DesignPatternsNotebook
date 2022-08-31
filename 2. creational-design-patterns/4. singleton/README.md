# MOTIVATION

* For some components it only makes sense to have one in the system

	* Database repository

	* Object factory

* E.g., the constructor call is expensive

	* We only do it once

	* We provide everyone with the same instance

* Want to prevent any one creating additional copies

* Need to take case of lazy instantiation and thread safety

* Def: A component which is instantiated only once

# SUMMARY

* Making a safe singleton is easy

	* Hide or delete the type's  constructor, copy constructor, and copy assignment operators

	* Create a static method that returns a reference to a static member

	* Guaranteed to be thread-safe since C++11

* Types with hard dependencies on singletons are difficult to test

	* Cannot decouple the singleton and supply a fake object

* Instead of directly using a singleton, consider depending on an abstraction

* Consider defining singleton lifetime in DI container