/*
정점 Vi에서 출발하여 모든 정점을 한번씩만 방문하고 원래 정점으로
되돌아오는 경로를 출력하는 프로그램을 작성하시오.
만약 경로가 없다면 "impossible"을 출력하시오.
*/

#include <stdio.h>

int w[6][6] = { 0,1,0,1,1,0,
	1,0,1,1,0,0,
	0,1,0,0,0,1,
	1,1,0,0,0,0,
	1,0,0,0,0,1,
	0,0,1,0,1,0 };	// 그래프를 기억할 인접행열
int path[6];	// 방문한 정점들의 경로
int flag = 0;

int promising(int i) {
	int j;

	if (i == 5 && !w[path[i] - 1][path[0] - 1])
		return 0;
	else if (i > 0 && !w[path[i - 1] - 1][path[i] - 1])
		return 0;
	else if (i > 0)
	{
		for (j = 0; j < i; j++)
		{
			if (path[i] == path[j])
				return 0;
		}
	}

	return 1;
}

void hamiltonian(int i) {
	int j;

	if (promising(i)) {
		if (i == 5) {	// 모든 정점을 방문했으면 출력
			for (j = 0; j < 6; j++)
				printf("V%d->", path[j]);
			printf("V%d\n", path[0]);
			flag = 1;
		}
		else
		{
			for (j = 2; j <= 6; j++)	// j=1은 출발 정점이므로 제외
			{
				path[i + 1] = j;
				hamiltonian(i + 1);
			}
		}
	}
}

int main()
{
	path[0] = 1;
	hamiltonian(0);
	if (flag != 1)
		printf("impossible");

	return 0;
}
