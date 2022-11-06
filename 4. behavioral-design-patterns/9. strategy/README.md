# MOTIVATION

* Many algorithms can be decomposed into higher and lower lever parts

* Making tea can be decomposed into

	* The process of making a hot beverage (boil water, pour into cup)

	* Tea-specific things (put teabag into water)

* The high level algorithm can then be reused for making coffee or hot chocolate

	* Supported by beverage-specific strategies

# DEFINITION

* Enables the exact behavior of a system to be selected either at run-time (dynamic) or compile-time (static)

* Also known as a policy (especially in the C++ world)

# SUMMARY

* Define an algorithm at a high level

* Define the interface you expect each strategy to follow

* Provide for either dynamic or static composition of strategy in the overall algorithm
