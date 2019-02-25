#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	scanf_s("%d %d", &a, &b);
	scanf_s("%d %d", &c, &d);
	if (a + d >= b + c) printf("%d", b + c);
	else printf("%d", a + d);
}