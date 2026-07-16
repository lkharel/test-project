#include <iostream>
using namespace std;

int main () {
    int x;

    while (true){
        cout << "\nEnter an integer: ";
        cin >> x;
        if(cin.good()) {
            cin.ignore(10, '\n');
            break;
        }
        cin.clear();
        cout << "\nYou have entered an incorrect input!";
        cin.ignore(10, '\n');
    }
    cout << " Number entered is: " << x << endl;
    return 0;
}