#include <stdio.h>

void ProFour()
{
	int i,j;
	long long imsi=0;
	long long rev,copy,max=0;

	rev=0;

	for(i=100;i<=999;i++)
	{
		for(j=100;j<=999;j++)
		{
			imsi=i*j;
			copy=imsi;

			rev=0;

			while(imsi>0)
			{
			rev+=imsi%10;
			imsi/=10;
			rev*=10;
			}
			rev/=10;

			if(rev==copy)
			{
				if(max<=copy)
				{
					max=copy;
					printf("%d * %d = %d\n",i,j,max);	
				}
			}
		}
	}
}

void main()
{
	ProFour();
}