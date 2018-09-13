#include <iostream>
#include <string>
#include <locale>
#include "postfixUtility.h"
#include "genericLinkedListStack.h"

using namespace std; 

//takes a normal expression and returns an equivalent postfix notation
string getPostfix(string nexp) {
    //create an empty stack for keeping operators
    genericLinkedListStack<char> operators; 
    string output;
    
    //iterate through string
    for(int i = 0; i < nexp.length(); i++) {
        char c = nexp[i];
        char nextc = nexp[i+1];
        //add numbers directly to output string
        if(isdigit(c)) {
            output += c;
            if(!isdigit(nextc)) {
                output += ' ';
            }
        } else {
            if(c == '(') {
                operators.push(c);
            } else if (c == ')') {
                // do until left parenthesis
                if(!operators.empty()){
                    char topElem = operators.top();
                    while(topElem != '(') {
                        output += topElem;
                        output += ' ';
                        // pop and append to output
                        operators.pop();
                        // peek at top
                        topElem = operators.top();
                    }
                    //remove left parenthesis from stack
                    operators.pop();
                }
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if(!operators.empty()) {
                    char nextElem = operators.top();
                    //cout << nextElem << endl;
                    //if operator has greater precedence (i.e. * has greater precedence than + )
                    // then pop and add to output string
                    if((nextElem == '*' || nextElem == '/' || nextElem == '+' || nextElem == '-')
                        && (c == '+' || c == '-')) {
                        output += nextElem;
                        output += ' ';
                        operators.pop();
                    }
                }
                operators.push(c);
            }
        }
    } 
    //adds last operator to postfix output, clears stack
    while(!operators.empty()) {
        char a = operators.top();
        output += a;
        output += ' ';
        operators.pop(); 
    }
    return output;
}


//use implementation of genericLinkedListStack to evaluate
float evaluatePostfix(string pexp) {
    genericLinkedListStack<float> operands; //initialize empty stack 
    float d = 0.0;
    float b = 0.0;
    float a = 0.0;
    float sum = 0.0;
    float difference = 0.0;
    float product = 0.0;
    float quotient = 0.0;

    //iterate over entire length of string
    int i = 0;
    while( i < pexp.length() ){
        char c = pexp[i];
        string operand;
        //cout << c << endl;
        //if character is a number, then push onto stack
        if(isdigit(c)) {
            operand += c;
            int j = i + 1;
            char nextc = pexp[j];
            while(isdigit(nextc)) {
                operand += nextc;
                j = j + 1;
                nextc = pexp[j];
            }
            i = j - 1;
            d = atof(operand.c_str()); //convert all numbers to float first
            operands.push(d);
        } else {
            //check if there are enough operands on the stack (at least 2)
            if(operands.size() >= 2 && !isspace(c)) {
                //pop two operands
                b = operands.top();
                operands.pop();
                a = operands.top();
                operands.pop();
                //if character is a primitive operator
                //then compute value and push result onto stack
                if(c == '+') {
                    sum = a + b; 
                    operands.push(sum);
                } else if(c == '-') {
                    difference = a-b;
                    operands.push(difference);
                } else if( c == '*') {
                    product = a*b;
                    operands.push(product);
                } else if( c == '/') {
                    quotient = a/b;
                    operands.push(quotient);
                }
            }
        }
        i++;
    }
    //verify stack only has one operand, and pop final result  
    float result = operands.top();
    operands.pop(); //stack should now be empty 
    return result; 
}