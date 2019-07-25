#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int room = 0;
	int maxnum = 0;
	int maxnum2 = 0;
	int nums[10] = { 0, };
	int result = 0;
	scanf("%d", &room);

	if (room == 0)
	{
		printf("1");
		return 0;
	}

	while (room != 0)
	{
		nums[(room % 10)]++;
		room /= 10;
	}

	for (int i = 0; i <= 9; i++)
	{
		//printf("%d%d ", i, nums[i]);
		if (result < nums[i])
		{
			result = nums[i];
			maxnum = i;
		}

		if (i != 6 && i != 9)
		{
			if (result < nums[i])
			{
				result = nums[i];
				maxnum2 = i;
			}
		}
	}

	if ((maxnum==6)||(maxnum==9))
	{
		if ((nums[6] + nums[9]) % 2 == 0)
			result = (nums[6] + nums[9]) / 2;
		else
			result = (nums[6] + nums[9])/2 + 1;
		if (result < nums[maxnum2]) result = nums[maxnum2];
	}

	printf("%d", result);

	return 0;
}