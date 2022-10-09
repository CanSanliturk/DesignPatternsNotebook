# MOTIVATION

* Textual inputs need to be processed.

	* E.g., turned into OOP structures

* Some examples

	* Programming language compilers, interpreters and IDEs

	* HTML, XML, and similar

	* Numeric expression (3 + 4 / 5)

	* Regular expressions

* Turning strings into OOP based structures in a complicated process

# DEFINITION

* A component that processes structures text data. Does so by turning it into seperate lexical tokens (lexing) and then interpreting sequences of said tokens (parsing).

# SUMMARY

* Barring simple cases, an interpreter acts in two stages

* Lexing turns text into a set of tokens, e.g., 

3x(4+5) -> Lit[3] Star Lparen Lit[4] Plus Lit[5] Rparen

* Parsing tokens into meaningful constructs

-> MultiplicationExpression[
	Integer[3],
	AdditionExpression[
		Integer[4], Integer[5]
	]
]

* Parsed data can then be traversed