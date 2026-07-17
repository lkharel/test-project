#include <iostream>
using namespace std;

int main()
{
	float radius;
	const float PI = 3.14159F;

	cout << "\nEnter the radius of the circle: ";
	cin >> radius;

	float areaOfCircle = PI * radius * radius;
	cout << "\nThe area of the circle having the radius " << radius << " cm is " << areaOfCircle << " square cm" << endl;

	return 0;
}