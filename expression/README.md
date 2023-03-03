# Expressions
In computer science, an expression is a combination of one or more values, variables, operators, and/or functions that are evaluated to produce a single value. Expressions are used to assign values to variables, to pass arguments to functions, and to control the flow of a program.

## Types of Expressions
There are several types of expressions, including arithmetic, logical, relational, and assignment expressions. Each type of expression has its own syntax and semantics, and they are used in different contexts.


## Operators
These are special symbols that perform specific operations on one, two, or three operands, and then return a result. The operands can be variables or values.

### Precedence & Associativity
Operators are evaluated based on their precedence and associativity. Precedence determines the order in which operators are evaluated. Associativity determines the order in which operators of the same precedence are evaluated.

Here's a table that lists some common operators in programming languages, along with their precedence and associativity:

Operator    | Description |	Associativity
------------|-------------|---------------
()	| Function call, grouping |	Left to right
[]	| Array subscripting |	Left to right
->	| Member selection (pointer) |	Left to right
.	| Member selection (non-pointer) |	Left to right
++ --	| Postfix increment/decrement |	Left to right
++ --	| Prefix increment/decrement |	Right to left
! ~	| Logical/bitwise NOT |	Right to left
\* / %	| Multiplication/division/modulus |	Left to right
\+ -	| Addition/subtraction |	Left to right
<< >>	| Bitwise shift |	Left to right
< <= > >=	| Relational operators |	Left to right
== !=	| Equality operators |	Left to right
&	| Bitwise AND |	Left to right
^	| Bitwise XOR |	Left to right
\|	| Bitwise OR |	Left to right
&&	| Logical AND |	Left to right
\|\|	| Logical OR |	Left to right
?:	| Ternary conditional |	Right to left
=	| Assignment |	Right to left
+= -=	| Compound assignment |	Right to left

## Notations
Infix, Postfix and Prefix are three different ways of writing arithmetic expressions that are used in computer programming. Each notation has its own rules for how operators and operands are arranged, and each has its own significance in different contexts. Here's a brief description of each notation:

### Infix Notation
It is the traditional way of writing arithmetic expressions, with operators placed between their operands. Such expressions are commonly used in mathematics, but they can be difficult to parse and evaluate for computers. It may require the use of parentheses to indicate the order of operations, and this can make them more difficult to read and understand. For example, the expression `a + b * c` can be interpreted in two ways: `(a + b) * c` or `a + (b * c)`. In the first case, `b * c` is evaluated first, and then the result is added to `a`. In the second case, `a` is added to `b`, and then the result is multiplied by `c`. The parentheses are used to indicate the order of operations.

### Postfix Notation
It is also known as **Reverse Polish notation (RPN)**, which is a way of writing arithmetic expressions where the operators come after their operands. These expressions can be evaluated more efficiently by computers because they do not require parentheses or a separate algorithm for determining the orders of operations. It is commonly used in calculators, as well as in computer programs that need to perform arithmetic calculations quickly. For example, the expression `a b c * +` can be interpreted as `a + (b * c)`. The expression `a b + c *` can be interpreted as `(a + b) * c`.

### Prefix Notation
It is also known as **Polish Notation**, which is a way of writing arithmetic expressions where the operators come before their operands. Like Postfix notation, prefix notation can be evaluated more efficiently than infix notation, making it a popular choice in computer programming. It is used in Lisp, C and some other programming languages, and it is particularly useful for building parsers and computers. For example, the expression `+ a * b c` can be interpreted as `a + (b * c)`. The expression `* + a b c` can be interpreted as `(a + b) * c`.

In summary, the significance of the evaluation of infix, postfix and prefix expressions depends on the specific requirements of a given application. Infix notation is the most common way of writing arithmetic expressions, but postfix and prefix notations are often used in situations where efficiency is important, such as in calculators or computer programs that need to perform many arithmetic calculations quickly.

## Conversion between Notations

### Infix to Postfix
The algorithm for converting an infix expression to a postfix expression is as follows:

1. Create an empty stack for operators
2. Create an empty string for the postfix expression
3. Scan the infix expressions from left to right
4. If the current token is an operand, append it to the postfix string
5. If the current token is an operator, then:
   1. Pop operators from the stack and append them to the postfix string while their precedence is greater than or equal to the precedence of the current operator and their associativity is left to right
   2. Push the current operator onto the stack
6. If the current token is a left parenthesis, then push it onto the stack
7. If the current token is a right parenthesis, then:
   1. Pop operators from the stack and append them to the postfix string until a left parenthesis is encountered
   2. Pop the left parenthesis from the stack (but don't append it to the postfix string)
8. After all tokens have been processed, pop any remaining operators from the stack and append them to the postfix string

Here's an example of how this algorithm would convert the infix expression `3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3` to postfix notation:

Token  |   Action  |	Postfix
-------|-----------|---------
3      |   Append to postfix |	3
\+     |   Push onto stack |	3
4      |   Append to postfix |	3 4
\*     |   Push onto stack |	3 4 +
2      |   Append to postfix |	3 4 2
/      |   Pop * from stack and append to postfix, then push / |	3 4 2 * /
(      |   Push onto stack |	3 4 2 * / +
1      |   Append to postfix |	3 4 2 * / + 1
\-     |   Push onto stack |	3 4 2 * / + 1
5      |   Append to postfix |	3 4 2 * / + 1 5
)      |   Pop - and append to postfix, then pop \( |	3 4 2 * / + 1 5 -
\^     |   Push onto stack |	3 4 2 * / + 1 5 - 2
\^     |   Pop ^ and append to postfix, then push ^ |	3 4 2 * / + 1 5 - 2 ^

The final postfix expression is `3 4 2 * / + 1 5 - 2 ^`.

### Infix to Prefix
Converting an infix expression to prefix notation is similar to converting to postfix notation, but the order of the operators and operands is reversed. The algorithm for converting an infix expression to a prefix expression is as follows:

1. Reverse the infix expression. This means the leftmost token becomes the rightmost and vice versa.
2. Convert the reversed infix expression to postfix notation using the algorithm described above.
3. Reverse the postfix expression to get the prefix expression

Here's an example of how this algorithm would convert the infix expression `3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3` to prefix notation:

Reverse the infix expression: `3 ^ 2 ^ ( 1 - 5 ) / 2 * 4 + 3`
Convert the reversed infix expression to postfix notation:

Token  |   Action  |	Postfix
-------|-----------|---------
3	|   Append to postfix   |	3
^	|   Push onto stack |	
2	|   Append to postfix   |	3 2
^	|   Push onto stack |	3 2 ^
(	|   Push onto stack |	3 2 ^ 1
1	|   Append to postfix   |	3 2 ^ 1
\-	|   Push onto stack |	3 2 ^ 1 -
5	|   Append to postfix   |	3 2 ^ 1 5
)	|   Pop - and append to postfix, then pop ( |	3 2 ^ 1 5 -
/	|   Pop ^ and append to postfix, then push /    |	3 2 ^ 1 5 - /
2	|   Append to postfix   |	3 2 ^ 1 5 - / 2
\*	|   Push onto stack |	3   | 2 ^ 1 5 - / 2 *
4	|   Append to postfix	3 2 ^ 1 5 - / 2 4
\+	|   Pop * and append to postfix, then push +    |	3 2 ^ 1 5 - / 2 4 * +

The postfix expression is `3 2 ^ 1 5 - / 2 4 * +`.

Reverse the postfix expression to get the prefix expression: `+ * 4 2 / - 5 1 ^ 2 3`

