#include <iostream>
using namespace std;

/*
Variable Data Type
*/

int main () {

    // declare variables
    int a;
    int result;

    // initialize variables with values
    a = 5; // assignment
    int b(3); // constructor
    int c{2}; // uniform init

    // calculateion
    result = a + b;
    result = result - c; //result -= c;

    // print result to the console
    cout << "The result is: " << result << endl;

    
    return 0;

}