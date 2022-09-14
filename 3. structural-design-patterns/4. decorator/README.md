# MOTIVATION

* Want to augment an object with additional functionality

* Do not want to rewrite or alter existing code (Open-Closed Principle)

* Want to keep new functionality seperate (Single-Responsibility Principle)

* Need to be able to interact with existing structures

* Two options:

	* Aggregate the decorated object

	* Inherit from the decorated object

# DEFINITION

* Facilitates the addition of behaviors to individual objects

# SUMMARY

* A dynamic decorator keeps the reference to the decorated object(s)

	* ColoredShape{Square{}}

* A static decorator uses mixin inheritance

	* ColoredShape\<Square\>

* Both approaches allow limitless composition

	* TransparentShape\<ColoredShape\<Circle\>\>
