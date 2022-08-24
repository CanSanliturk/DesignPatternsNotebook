# MOTIVATION

* Some objects are simple and can be created in a single constructor call.

* Other objects require a lot of ceremony to create.

* Having an object with 10 constructor arguments is not productive.

* Instead, opt for piecewise construction.

* Builder provides an API for constucting an object step-by-step.

* To make builder fluent, return this parameter to be able to call build methods fluently.

* Different facets of an object can be built with different builders working in tandem via a base class.
