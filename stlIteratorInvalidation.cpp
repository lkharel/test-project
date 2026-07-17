#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    cout << "v.begin() --> " << *v.begin() << endl;

    int *X = &v[6];
    X++;
    *X = -50;

    cout << "last element --> " << v.back() << endl;
    cout << "v.rbegin() --> " << *v.rbegin() << endl;

    return 0;
}