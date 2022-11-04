# MOTIVATION

* Components may go in and out of a system at any time

	* e.g. chat room participants, players in MMORPG

* It makes no sense for them to have direct references to one another

* Those references may go dead

* Solution: Have then all refer to some central component that facilitates communication

# DEFINITION

* A component that facilitates communication between other components without them necessarily being aware of each other or having direct (reference) access to each other.

# SUMMARY

* Create the mediator and have each object in the system refer to it

	* E.g., in a field

* Mediator engages in bidirectional communication with its connected components

* Mediator has functions the components can call

* Components have functions the mediator can call

* Event processing (E.g, Rx) makes the communication easier to implement