# Equation Calculator

This program evaluates a given normal (not necessarily fully parenthesized) expression by transforming it into an equivalent postfix notation, and evaluating that using stacks.

## To Run: 
```c++
g++ -c postfixUtility.cpp
g++ -o main.o main.cpp postfixUtility.o
```
example command line argument to evaluate: 
./main.o "(4+3* 12)/ ( 12+ 3/ 2+ 46 /4)"
