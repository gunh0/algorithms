/*
가장 높은 탑 쌓기
밑면이 정사각형인 직육면체 벽돌들을 사용하여 탑을 쌓고자 한다.
탑은 벽돌을 한 개씩 아래에서 위로 쌓으면서 만들어 간다.
아래의 조건을 만족하면서 가장 높은 탑을 쌓을 수 있는 방법을 구현한다.

1) 벽돌은 회전시킬 수 없다. 즉, 옆면을 밑면으로 사용할 수 없다.
2) 밑면의 넓이가 같은 별돌은 없으며, 또한 무게가 같은 벽돌도 없다.
3) 벽돌들의 높이는 같을 수도 있다.
4) 탑을 쌓을 때 밑면이 좁은 벽돌 위에 밑면이 넓은 벽돌을 놓을 수 없다.
4) 무게가 무거운 벽돌을 무게가 가벼운 벽돌 위에 놓을 수 없다.

입력의 첫줄은 입력될 벽돌의 수가 주어진다.
입력으로 주어지는 벽돌의 수는 최대 100개이다.
둘째 줄부터는 각 줄에 한개의 벽돌에 관한 정보인 벽돌 밑면의 넓이, 높이, 무게가 차례대로 양의 정수로 주어진다.

출력의 첫줄은 사용된 벽돌의 수를 출력한다.
두 번째 줄 부터는 탑의 가장 위 벽돌부터 가장 아래 벽돌까지 차례로 출력한다.
*/

#include <stdio.h>

int number[5] = { 1,2,3,4,5 };	// 벽돌 번호
int width[5] = { 25,4,9,16,1 };	// 넓이
int height[5] = { 3,4,2,2,5 };	// 높이
int weight[5] = { 4,6,3,5,2 };	// 무게
int block[5];	// i번째에서 아래에 높이는 벽돌 번호
int highest[5];	// i번째에서의 최고 높이

void sort()	// 버블 정렬
{
	int i = 0, j = 0, temp = 0, flag = 1;

	for (i = 4; i > 0 && flag == 1; i--)
	{
		flag = 0;
		for (j = 1; j <= i; j++)
		{
			if (width[j - 1] < width[j])	// 넓이 기준
			{
				temp = number[j];
				number[j] = number[j - 1];
				number[j - 1] = temp;

				temp = width[j];
				width[j] = width[j - 1];
				width[j - 1] = temp;

				temp = height[j];
				height[j] = height[j - 1];
				height[j - 1] = temp;

				temp = weight[j];
				weight[j] = weight[j - 1];
				weight[j - 1] = temp;

				flag = 1;
			}
		}
	}
}

void dynamic()
{
	int i = 0, j = 0;
	for (i = 0; i < 5; i++)
	{
		highest[i] = height[i];
		block[i] = -1;	// 아래에 아무것도 없다.
	}
	for (i = 1; i < 5; i++)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (weight[i] < weight[j]) {	// 무게가 무거워야 아래에 놓일 수 있다.
				if (highest[i] < highest[j] + height[i]) {
					highest[i] = highest[j] + height[i];
					block[i] = j;
				}
			}
		}
	}
}

void print_result()
{
	int max = 0;
	int num, cnt, i, path[5];

	for (i = 0; i < 5; i++)	// 최고 높이를 찾는다.
	{
		if (max < highest[i]) {
			max = highest[i];
			num = i;
		}
	}
	cnt = 0;
	path[cnt] = number[num];
	cnt++;
	while (block[num] != -1)
	{
		path[cnt] = number[block[num]];
		cnt += 1;
		num = block[num];
	}
	path[cnt] = -1;

	printf("쌓이는 벽돌의 갯수 : %d\n", cnt);
	for (i = 0; path[i] != -1; i++)
		printf("쌓이는 벽돌의 순서 %d : %d\n", i, path[i]);
}

int main()
{
	sort();
	dynamic();
	print_result();
	return 0;
}
