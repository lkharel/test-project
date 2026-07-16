#include <iostream>
using namespace std;

int main () {
    float x;
    cout << "Pleas enter a number: ";
    cin >> x;

    if ( x > 100 ){
        cout << "The number you ebtered is greater than 100." << endl;
    }
    else if ( x < 100 ) {
        cout << "The number is less than 100. " << endl;
    }
    else if ( x == 100 ){
        cout << " You have entered exact 100." << endl;
    }
    else {
        cout << "Invalid entry." << endl;
    }
    return 0;
}