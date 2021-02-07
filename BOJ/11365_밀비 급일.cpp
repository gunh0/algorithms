#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "";
	do
	{
		if (str != "")
		{
			for (int i = str.size() - 1; i >= 0; i--)
				cout << str[i];
			cout << endl;
		}
		getline(cin, str);
	} while (str != "END");
	return 0;
}