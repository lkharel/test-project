#include <iostream>
using namespace std;

int main()
{

	char operand;
	float num1, num2;

	cout << "Please select the operand option (+, -, *, /, ): ";
	cin >> operand;

	cout << " Please enter any two numbers: " << endl;
	cin >> num1 >> num2;

	// switch cases
	switch (operand)
	{
	case '+':
		/* code */
		cout << " The sum of two number is: " << num1 + num2 << endl;
		break;
	case '-':
		cout << " The difference of " << num1 << " and " << num2 << "is: " << num1 - num2 << endl;
		break;
	case '*':
		cout << "The product of " << num1 << " and " << num2 << " is: " << num1 * num2 << endl;
		break;
	case '/':
		cout << " The quiotent of " << num1 << " and " << num2 << " is: " << num1 / num2 << endl;
		break;
	default:
		break;
	}

	return 0;
}