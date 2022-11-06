# MOTIVATION

* Consider an ordinary telephone

* What do you with it depends on the state of the phone/line

	* If it is ringing or you want to make a call, you can pick it up

	* Phone must be off the hook to talk/make a call

	* If you try calling someone, and it's busy, you put the handset down

* Changes in state can be explicit or in response to event (Observer pattern)

# DEFINITION

* A pattern in which the object's behavior is determined by its state. An object transitions from one state to another (something needs to trigger a transition)

* A formalized construct which manages state and transitions is called state machine

# SUMMARY

* Given sufficient complexity, it pays to formally define possible states and events/triggers

* Can define

	* State entry/exit behaviors

	* Action when a particular event causes a transition

	* Guards conditions when to transitions found for an event

	* Default action when no transitions are found for an event
