#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string str, a, b;
	int index;
	getline(cin, str);

	for (index = 0; str[index] != ' '; index++)
	{
		a += str[index];
	}

	for (index += 1; index < str.length(); index++)
	{
		b += str[index];
	}

	int ain = a.length()-1, bin = b.length()-1;
	a.length() > b.length() ? index = a.length() : index = b.length();

	string tempa, tempb, result;
	int carry = 0;
	for (index -= 1; index >= -1; index--)
	{
		if (ain != -1)
		{
			tempa = a[ain];
			ain--;
		}
		else tempa = "0";

		if (bin != -1)
		{
			tempb = b[bin];
			bin--;
		}
		else tempb = "0";

		result += to_string((carry + atoi(tempa.c_str()) + atoi(tempb.c_str())) % 10);
		carry = (carry + atoi(tempa.c_str()) + atoi(tempb.c_str())) / 10;
	}

	(result[result.length() - 1] == '0') ? index = result.length() - 2 : index = result.length() - 1;
	for(; index >= 0; index--)
	{
		cout << result[index];
	}

	return 0;
}