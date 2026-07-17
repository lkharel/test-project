#include <iostream>
using namespace std;

void customLine(char, int);
int main()
{
	customLine('=', 22);
	cout << " GAS             PRICE\n";
	customLine('=', 22);
	cout << " UNLEADED         $4.58" << endl;
	cout << " PREMIUM          $4.98" << endl;
	cout << " DIESEL           $5.99" << endl;
	customLine('=', 22);

	return 0;
}

void customLine(char myChar, int n)
{
	for (int i = 0; i < 22; i++)
		cout << '=';
	cout << endl;
}