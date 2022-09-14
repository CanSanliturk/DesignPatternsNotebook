# MOTIVATION

* You are calling foo.bar()

* This assumes that foo is in the same process as bar()

* What if, later on, you want tı put all Foo-related operations into seperate process
	
	* Can you avoid changing you code?

* Proxy to rescue

	* Same interface, entirely different behavior

* This is called communication proxy
	
	* Other types: logging, virtual, guarding, ...

# DEFINITION

* An interface for accessing a particular resource

* A class the functions as an interface to a particular resource. That resource may be remote, expensive to construct, or may require logging or some other added functionality

# PROXY vs. DECORATOR

* Proxy provides an identical interface; decorator provides an enhanced interface

* Decorator typically aggregates (or has reference to) what it is decorating; proxy does not have to

* Proxy might not even be working with a materialized object

# SUMMARY

* A proxy has the same interface as the underlying object

* To create a proxy, simply replicate the existing interface of an object

* Add relevant functionality to the redefined member functions

* Different proxies (communication, logging, caching, etc.) have completely different behaviors
