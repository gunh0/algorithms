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
		if(i%15==0) //3�� ����� 5�� ������� �ߺ��Ǵ� 15�� ������� 2�� �������� �ѹ� �������ش�.
		{
			sum-=i;
		}
	}
	printf("%d",sum);
}