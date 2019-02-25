#include <stdio.h>

int getLCM(int num1, int num2)
{  
    int LCM=0;
    if(num1 !=0 && num2 != 0)
        for(LCM=num1; LCM%num1 || LCM%num2;LCM++);
    return LCM;
}

void main()
{
	int gap=1,i=1;
	for(i=1;i<=20;i++)
	{
		gap=getLCM(gap,i);
	}
	printf("%d",gap);
}