#include <stdio.h>

int cntDivisor(int n)
{
	int a,b,cnt=1;

	for(b=0; (n&1)==0; b++, n>>=1);
	cnt*=(b+1);

	for(a=3; n>=a; a+=2)
	{
		for(b=0; n%a==0; n/=a, b++);
		cnt*=(b+1);
	}
	return cnt;
}

int EulerProject12()
{
	int num=3,i;
	for(i=3;cntDivisor(num)<500;num+=i++);
	printf("500개 이상의 약수를 갖는 가장 작은 삼각수는 %d입니다.\n",num);
	return 0;
}

int main()
{
	EulerProject12();
}
