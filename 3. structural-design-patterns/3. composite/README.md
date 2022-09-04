# MOTIVATION

* Objcets use other objects fields/properties/members through inheritance and composition

* Composition lets us make compound objects

	* E.g., a mathematical expression composed of simple expressions; or

	* A grouping of shapes that consists of several shapes

* Composite design pattern is used tı treat both single (scalar) and composite objects uniformly

	* I.e., Foo and Collection\<Foo\> have common APIs


# DEFINITION

* A mechanism for treating individual (scalar) objects and compositions of objects in a uniform manner

# SUMMARY

* Objects can use other ıbjects via inheritance/composition

* Some composed and singular objects need similar/identical behaviors

* Composite design pattern lets us treat both types of objects uniformly

* C++ uses duck typing, epexting enumerable types to provide begin()/end()

* A single object can masquerade as collection

	* Foo* begin() { return this; }
	
	* Foo* end() { return this + 1; }
