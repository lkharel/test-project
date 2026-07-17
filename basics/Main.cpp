#include <iostream>

using namespace std;

int main()
{
	string name, dish;

	cout << " Please enter you name: ";
	getline(cin, name);

	cout << "Please enter your favourite dish: ";
	getline(cin, dish);

	cout << " Hello " << name << " , hope you enjoy your " << dish << " . " << endl;

	return 0;
}