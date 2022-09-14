# MOTIVATION

* Space optimization

* Avoid redundancy when storing data

* E.g., MMORPG

	* Plenty of users with identical first/last names

	* No sense in storing same first/last name over and over again

	* Store a list of names and pointers to them

* E.g., bold or italic text in console

	 * Don't want each character to have a formatting character

	 * Operate on ranges (e.g., line number, start/end positions)

# DEFINITION

* A space optimization technique that lets us use less memory by storing externally the data associated with similar objects

# SUMMARY

* Store common data externally

	* E.g., static map

* Define the idea of ranges on homogeneous collections

	* Store data related to those ranges