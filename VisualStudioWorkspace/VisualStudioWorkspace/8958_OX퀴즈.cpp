#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t = 0, score=0;
	string str;
	cin >> t;
	for (int i = 0; i <= t; i++)
	{
		getline(cin, str);
		
		cout << str << endl;;
	}
}