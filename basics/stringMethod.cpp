#include <iostream>
#include <string>

using namespace std;

int main()
{

	string str1 = " The little dog laughed.";
	string str2 = " The little dog laughed.";
	string str3 = " The little dog laughed.";
	int strLength;

	strLength = str1.size();
	str3 = str1;

	cout << " The size of str1 is: " << strLength << endl;

	return 0;
}
