#include <stdio.h>

int main()
{
	int sum=0;
	for(int i=0;i<1000;i++)
	{
		if(i%3==0)
		{
			sum+=i;
		}
		if(i%5==0)
		{
			sum+=i;
		}
		if(i%15==0) //3의 배수와 5의 배수에서 중복되는 15의 배수들은 2번 계산됨으로 한번 감산해준다.
		{
			sum-=i;
		}
	}
	printf("%d",sum);
}