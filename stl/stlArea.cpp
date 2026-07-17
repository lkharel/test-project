#include <iostream>
using namespace std;

int main () {
    int x1 =  area_rect (10, 5);
    double x2 = area_rect (10.5, 5.5);
    float x3 = area_rect (1.9f, 5.2f);
    cout << x1 << " , " << x2 << " , " << x3 << endl;
    return 0;
}

template <typename T>
T area_rect(T a , T b) {
    return a * b;
}