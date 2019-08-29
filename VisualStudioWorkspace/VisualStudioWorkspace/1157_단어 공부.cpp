#include <iostream>

using namespace std;

int main()
{
	string str;
	cin >> str;
	int strcnt['Z' - 'A' + 1] = { 0, };
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			strcnt[str[i] - 'a']++;
		}
		if (str[i] >= 'A' && str[i] >= 'Z')
		{
			strcnt[str[i] - 'A']++;
		}
	}

	int max = 0;
	int index = 0;
	for (int j = 0; j < 'Z' - 'A' + 1; j++)
	{
		if (strcnt[j] > max)
		{
			max = strcnt[j];
			index = j;
		}
	}

	int flag = 0;
	for (int k = 0; k < 'Z' - 'A' + 1; k++)
	{
		if (strcnt[k] == max) flag++;
	}
	if (flag >= 2) cout << "?" << endl;
	else if (flag == 1) cout << str[index] << endl;
	else cout << "error!" << endl;
	
	return 0;
}