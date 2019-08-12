#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string str;
	cin >> str;
	vector<char> vec;
	int result = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(') vec.push_back(str[i]);
		else
		{
			vec.pop_back();
			if (str[i - 1] == '(')	// 레이저인 경우
				result += vec.size();
			else result++;
		}
	}
	cout << result << endl;
	return 0;
}
