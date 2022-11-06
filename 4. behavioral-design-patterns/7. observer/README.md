# MOTIVATION

* Getting notifications when things happen

* We need to be informed when certain things happen

	* Object's field changes
	
	* Object does something

	* Some external event occurs

* We want to listen events and notified when they occur

* Terminology:

	* event and subscriber

	* signal and slot (basically same thing as event and subscriber)

# DEFINITION

* An observer is an object that wishes to be informed about the events happening in the system. The entity generating the events is called observable.

# SUMMARY

* Two participants:

	* Observable provides a way of subscribing to an event (signal)

	* Observable implementation is always intrusive (observer does not need to be)

* Multithreaded/reentrant use can cause issues

* Ready-made implementations of Observer are available like Boost Signals, but it is not thread-safe