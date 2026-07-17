#include <iostream>
using namespace std;

void singlePlayerMode() { cout << " Single player Mode selected..\n"; }
void multiPlayerMode() { cout << " Multi player Mode selected..\n"; }
void choosePlayerMode() { cout << " Choose the player..\n"; }
void selectPlayerMode() { cout << " Select your player..\n"; }
void yourPlayerMode() { cout << " Create your player..\n"; }

int main()
{

	int input;

	cout << "1: Single Player Mode...\n";
	cout << "2: Multi Player Mode...\n";
	cout << "3: Choose Player Mode...\n";
	cout << "4: Select Player Mode...\n";
	cout << " Player Option...\n";

	cin >> input;

	switch (input)
	{
	case 1:
		singlePlayerMode();
		break;
	case 2:
		multiPlayerMode();
		break;
	case 3:
		choosePlayerMode();
		break;
	case 4:
		selectPlayerMode();
		break;
	case 5:
		yourPlayerMode();
		break;
	default:
		cout << "Invalid selection, try again!";
	}
	cin.get(); // pause console

	return 0;
}