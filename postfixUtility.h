#include <iostream>
#include <string>

using namespace std; 

//takes a normal expression and returns an equivalent postfix notation
string getPostfix(string nexp);

//takes a postfix expression and evaluates it
float evaluatePostfix(string pexp);
