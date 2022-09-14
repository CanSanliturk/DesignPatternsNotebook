# MOTIVATION

* Ordinary C++ statements are perishable

	* Cannot undo a field/property assignment

	* Cannot directly serialize a sequence of actions (calls)

	* Want an object that represents operation

* Want an object that represents an operation

	* X should change its fields Y to the value Z

	* X should do W()

* Uses: GUI commands, multi-level undo/redo, macro recording and more!

# DEFINITION

* An object which represents an instruction to perform a particular action. Contains all the information necessary for the action to be taken.

# COMMAND QUERY SEPERATION

* Command: asking for an action or change (e.g., please set your attack value to 2)

* Query: asking for information (e.g., please give me your attack value)

* CQS: having seperate means of sending commands and queries

* In GoF context, both commands and queries are represented with the Command design pattern

# SUMMARY

* Encapsulate all the details of an operation in a seperate object

* Define instruction for applying the command (either in the command itself, or elsewhere)

* Optionally define instructions for undoing command

* Can create composite commands (a.k.a. macros)