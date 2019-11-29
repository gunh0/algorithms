/*
4X4 체스판에 4명의 여왕을 배치하려고 한다.
이때 어떤 두 여왕도 같은 행, 열, 대각선에 위치해서는 안된다.
이러한 조건을 만족하는 여왕의 배치도를 출력하는 프로그램을 작성하시오.

Bounding Function
두 여왕의 좌표를 Q1(X,Y), Q2(V,W)라고 한다면,
- 같은 행에 위치한다면 X=V 이다.
- 같은 열에 위치한다면 Y=W 이다.
- 같은 대각선에 위치한다면 X+Y=V+W 이거나 X-Y=V-W 이다.
*/

#include <stdio.h>

int p_loc[4][5];	// i번째 여왕이 배치될 수 있는 가능한 위치
int loc[4];	// i번째 여왕이 배치된 위치

int promising_ioc(int qnum)	// 가능한 위치를 추출하고 계속 진행할 수 있는지의 여부조사
{
	int x, y, v, w;
	int i, j;
	int temp[5];

	if (qnum == 0) {	// 첫번째 여왕은 모든 열에 위치할 수 있다.
		for (y = 0; y < 4; y++)
			p_loc[qnum][y] = y;
		p_loc[qnum][y] = -1;
		return 1;
	}
	else {
		for (i = 0; i <= 4; i++)
			temp[i] = 1;

		for (i = 0; i < qnum; i++)
		{
			v = i;
			w = loc[i];	// 배치된 여왕의 위치
			x = qnum;
			for (y = 0; y < 4; y++) {	// x, y는 배치될 여왕의 위치
				if (v == x || w == y || (v + w) == (x + y) || (v - w) == (x - y))
					temp[y] = 0;	// 갈 수 없는 위치
			}
		}

		j = 0;
		for (y = 0; y < 4; y++)
		{
			if (temp[y] == 1)
			{
				p_loc[qnum][j] = y;
				j++;
			}
		}

		p_loc[qnum][j] = -1;	// 더 이상 가능한 열이 없다.
		if (j > 0) return 1;
		else return 0;
	}
}

void queen(int qnum)
{
	int i;

	if (qnum == 4) {
		for (i = 0; i < 4; i++)
			printf("(%d, %d)\n", i, loc[i]);
		printf("\n");
	}
	else if (promising_ioc(qnum))
	{
		i = 0;
		while (p_loc[qnum][i] != -1)
		{
			loc[qnum] = p_loc[qnum][i];	// 가능한 위치중 아직 가보지 않는 위치 탐색
			i++;
			queen(qnum + 1);
		}
	}
}

int main()
{
	queen(0);
	return 0;
}