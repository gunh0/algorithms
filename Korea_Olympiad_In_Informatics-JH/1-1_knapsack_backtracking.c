#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

float boundf(int i,int val,int str);
//void sort();

int s[6]={0,3,4,7,8,9}; // Weight
int v[6]={0,4,5,10,11,13}; // Value
int bestset[6]; // MaxValue goods
int include[6]; // Including?

int sackw;

float bound; // Upper boundary of the gains
int maxval, numbest; // At the time of maximum value of goods

void sort()
{
	float r[6], temp;
	int i,j;

	for(i=1;i<6;i++)
		r[i]=(float)v[i]/(float)s[i];

	for(i=1;i<5;i++)
	{
		for(j=i+1;j<6;j++)
		{
			if(r[i]<r[j])
			{
				temp=r[i];
				r[i]=r[j];
				r[j]=temp;

				temp=s[i];
				s[i]=s[j];
				s[j]=(int)temp;

				temp=v[i];
				v[i]=v[j];
				v[j]=(int)temp;
			}
		}
	}
}

// Life-saving function on the upper limit values of benefits
float boundf(int i,int val,int str)
{
	int dif,j;

	bound=val;
	for(j=i;j<6;j++)
	{
		str+=s[j];
		if(str<=sackw) bound+=(float)v[j];
		else
		{
			str-=s[j];
			dif=sackw-str;
			bound+=(float)v[j]*dif/(float)s[j];
			break;
		}
	}

	return bound;
}

void knapsack(int i,int val,int str)
{
	int j;

	// Case comes out is hugely valuable than the maximum value
	if(str<=sackw && val>maxval && i<6)
	{
		maxval=val;
		numbest=i;
		for(j=1;j<=numbest;j++)
			bestset[j]=include[j]; // Stored goods
		printf(" %d", numbest);
	}

	// Bounding Function
	if(str<=sackw && maxval<bound && i<6)
	{
		include[i+1]=1;	// 1:As put
		bound=boundf(i+1,val,str);
		knapsack(i+1,val+v[i+1],str+s[i+1]);
		include[i+1]=0; // 0:As unput
		bound=boundf(i+2,val,str);
		knapsack(i+1,val,str);
	}
}

void main()
{
	int i, val;

	system("cls");

	sackw=17;
	maxval=0;
	numbest=0;

	// Reset
	for(i=0;i<6;i++)
	{
		bestset[i]=0;
		include[i]=0;
	}

	sort();
	bound=boundf(0,0,0);
	knapsack(0,0,0);

	// Print result
	val=0;
	printf("\n");
	for(i=1;i<=numbest;i++)
	{
		if(bestset[i]==1)
		{
			printf("Choice : %d\n",s[i]);
			val+=v[i];
		}
	}
	printf("The Maximum Value is %d\n",val);
}