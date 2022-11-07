# MOTIVATION

* Need to define a new operation on an entire class hierarchy

	* E.g., make a document model printable to HTML/Markdown

* Do not want to keep modifying every class in the hierarchy

	* Do not violate Open-Closed Principle and Single-Responsibility Principle

* Need to access to the non-common aspects of class in the hierarchy

	* Cannot put everything into a single interface

* Create an external component to handle rendering

	* But preferably avoid type chekcs

# DEFINITION

* Typically a tool for structure traversal than anything else

* A pattern where a component (visitor) is allowed to traverse the entire inheritance hierarchy. Implemented by propagating a single visit() method throughout the entire hierarchy.

# SUMMARY

* Propagate an accept(visitor* v) method throughout the entire hierarchy

* Create a visitor with visit(Foo\*), visit(Bar\*), ... for each element in the hierarchy

* Each accept() simply calls visitor.visit(this)
