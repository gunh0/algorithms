#include <iostream>

using namespace std;

int main()
{
	int Aa = 0, Ob = 0;	// 첫 번째 바구니
	cin >> Aa >> Ob;
	int Ac = 0, Od = 0;	// 두 번째 바구니
	cin >> Ac >> Od;

	if (Aa + Od > Ob + Ac)
		cout << Ob + Ac << endl;
	else
		cout << Aa + Od << endl;

	return 0;
}