#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str, a, b,reva,revb;
	int index = 0;
	getline(cin, str);

	for (index = 0; str[index] != ' '; index++)
	{
		a += str[index];
	}

	for (index += 1; index < str.length(); index++)
	{
		b += str[index];
	}

	for (int i = a.length()-1; i >= 0; i--)
	{
		reva += a[i];
	}
	int aval = atoi(reva.c_str());

	for (int i = b.length() - 1; i >= 0; i--)
	{
		revb += b[i];
	}
	int bval = atoi(revb.c_str());

	if (aval > bval)
		cout << aval << endl;
	else cout << bval << endl;

	return 0;
}