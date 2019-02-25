#include <stdio.h>
#include <math.h>

int main()
{
	int count=0,i,n=2,primeCount=0;
	while(primeCount<10001)
	{
		for(i=1;i<=sqrt(n);i++)
		{
			if(n%i==0)count++;
			if(count>1)break;
		}
		if(count==1)primeCount++;
		n++;
		count=0;
	}
	printf("%i",n-1);
	return 0; 
}