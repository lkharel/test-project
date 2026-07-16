#include <iostream>
#include "simpleCalculator.h"
using namespace std;

int main()
{
	char operand;
	int num1, num2;

	cout << " Please choose the operand ( =, -, /, * ): ";
	cin >> operand;

	cout << " Please enter any two numbers: " << endl;
	cin >> num1 >> num2;

	// switch statement
	switch (operand)
	{
	case '+':
		/* code */
		cout << " The sume of the two number " << num1 << " and " << num2 << " is: " << add(num1, num2) << endl;
		break;

	case '-':
		cout << " The difference of the two number " << num1 << " and " << num2 << " is: " << subtract(num1, num2) << endl;
		break;

	case '/':
		cout << "The quiotent of the two number " << num1 << " and " << num2 << " is: " << remainder(num1, num2) << endl;
		break;

	case '*':
		cout << " The product of the two number " << num1 << " and " << num2 << "is: " << multiplication(num1, num2) << endl;
		break;

	default:
		cout << " You have entered: " << operand << ", this ia a/an invalid operand, please try again. " << endl;
		break;
	}

	return 0;
}