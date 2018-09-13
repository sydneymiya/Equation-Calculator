#include <iostream>
#include <string>
#include "postfixUtility.h"

using namespace std; 

int main( int argc, char** argv) {
    if( argc != 2 ) {
        cout << "User must enter a string containing a normal expression" << endl;
        return 1;
    }

    string postfix; 
    postfix = getPostfix(argv[1]); 

    float result; 
    result = evaluatePostfix(postfix);

    cout << result << endl;


}