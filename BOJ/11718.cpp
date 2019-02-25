#include <iostream>
#include <string>

using namespace std;

int main()
{
	string result;
	string tmp;

	while (1)
	{
		getline(cin, result);
		if (result == "") break;
		cout << result << endl;
	}

	return 0;
}