/*
좌우에 접시가 있는 양팔저울을 사용해서 무게를 재려고 할때,
사용하는 추의 종류와 갯수를 최소가 되게 하려면 어떤 추를 어떻게 사용해야 하는지를
출력하는 프로그램을 작성하시오.

1. 한쪽 접시만 추를 사용할 수 있는 경우
*/

#include <stdio.h>

int w = 7;
int chu = 1;

void base(int n)
{
	int r;
	if (n == 0) return;
	else {
		r = n % 2;
		if (r == 1) printf("왼쪽에 %dg 추를 놓는다.\n", chu);
		chu *= 2;
		base(n/2);
	}
}

int main()
{
	base(w);
	return 0;
}