#include <iostream>
#include <string>

using namespace std;

int main()
{
	string username;
	string passwrord;

	cout << "Please enter your username: ";
	getline(cin, username, '\n');

	cout << "Please enter your password: ";
	getline(cin, passwrord, '\n');

	cout << " Login wuth username and password: " << endl;

	string user;
	string pass;

	getline(cin, user, '\n');
	getline(cin, pass, '\n');

	if (user == username && pass == passwrord)
	{
		cout << " You have entered the correct username and password." << endl;
	}
	else if (user != username && pass == passwrord)
	{
		cout << " Invalid user id! Please try again!" << endl;
	}
	else if (user == username && pass != passwrord)
	{
		cout << " Wrong password, Please try again." << endl;
	}
	else
	{
		cout << " Invalid user id and password." << endl;
	}

	return 0;
}