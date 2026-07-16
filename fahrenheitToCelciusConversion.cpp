#include <iostream>
using namespace std;

int main () {
    int fahtemp;

    cout << "\nPlease enter the temperature in Fahrenheit: ";
    cin >> fahtemp;

    int celtemp = (fahtemp - 32) * 5 / 9;
    cout << " The " << fahtemp << " degree Fahrenheit is equivalent to " << celtemp << " degree celcius." << endl;


    return 0;
}