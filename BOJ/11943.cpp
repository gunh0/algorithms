#include <iostream>

using namespace std;

int main()
{
	int Aa = 0, Ob = 0;	// ù ��° �ٱ���
	cin >> Aa >> Ob;
	int Ac = 0, Od = 0;	// �� ��° �ٱ���
	cin >> Ac >> Od;

	if (Aa + Od > Ob + Ac)
		cout << Ob + Ac << endl;
	else
		cout << Aa + Od << endl;

	return 0;
}