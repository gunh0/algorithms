#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int n, m, x;
char s[11];

int main()
{
	scanf(" %d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf(" %s", &s);
		scanf(" %d", &x);
		if (s[0] == 'a' && s[1] == 'd')
			n |= (1 << x);
		else if (s[0] == 'r')
			n &= ~(1 << x);
		else if (s[0] == 'c')
			printf("%d\n", (n & (1 << x)) == 0 ? 0 : 1);
		else if (s[0] == 't')
			n ^= (1 << x);
		else if (s[0] == 'a' && s[1] == 'l')
			n = (1 << 21) - 1;
		else
			n = 0;
	}
}