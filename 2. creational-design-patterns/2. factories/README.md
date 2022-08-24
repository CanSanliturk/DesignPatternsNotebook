# MOTIVATION

* Object creation logic becomes too convoluted.

* Constructor is not descriptive. Constuctor name cannot be changed. It also cannot be overloaded with same set of arguments with different names. Optional parameters can make constructors too complex.

* Object creation can be outsourced to factories. Unlike builders, factories can create object in a non-piecewise matter. This requires a seperate factory function, which might be in a seperate factory class. It can create a hierarchy of factories with Abstract Factory.

* To sum up, factory is a componen that is responsible solely for the wholesale (not piecewise) creation of objects.

* A factory method is a static method that creates objects.

* A factory can take care of objects creation.

* A factory can be external or reside inside the object as an inner class.

* Hierarchies of factories can be used to create related objects.
