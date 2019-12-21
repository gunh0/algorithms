#include <iostream>

using namespace std;

int main()
{
	int t;
	int h, w, n;
	
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> h >> w >> n;

		if ((n - 1) / h + 1 >= 10)	// µÎ ÀÚ¸®
			cout << (n - 1) % h + 1 << (n - 1) / h + 1 << endl;
		else
			cout << (n - 1) % h + 1 << "0" << (n - 1) / h + 1 << endl;			
	}
	return 0;
}