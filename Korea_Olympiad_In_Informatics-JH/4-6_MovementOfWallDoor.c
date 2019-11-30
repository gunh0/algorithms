/*
n개의 같은 크기의 벽장들이 일렬로 붙어져 있고 벽장의 문은 n-2개만이 있다.
한 벽장 앞에 있는 문은 이웃 벽장 앞에 문이 없다면 (즉, 벽장이 열려있다면)
그 벽장 앞으로 움직일 수 있다.

예를 들어, 7개의 벽장일 경우 2번 벽장과 5번 벽장이 열려있고, 나머지 벽장은 닫혀있다.
이 상태에서는 1번 벽장을 닫고 있는 벽장문을 오른쪽으로 한칸 이동함으로써 1번 벽장을 사용할 수 있다.
이때 2번 벽장은 닫혀져 사용할 수 없다.
역시 5번 벽장이 열려 있으므로 4번 벽장 또는 6번 벽장 앞의 벽장문을 5번 벽장 앞으로 이동시킬 수 있다.

풀어야 할 문제는 입력으로 주어지는 사용할 벽장의 순서에 따라서 벽장문을 이동하는 순서를 찾는 것이다.
이때 벽장문의 이동횟수를 최소로 하여야 한다. 열려있는 벽장의 갯수는 항상 2개이다.

- 사용하려는 문이 더이상 없을때가 종단 조건이다.
- 현재 상태에서 이동횟수가 최소 이동횟수보다 작아야한다.
- 사용하려는 문이 열려있는 문 번호보다 모두 작을때는 왼쪽 문으로 이동한다.
- 사용하려는 문이 열려있는 문 번호보다 모두 클때는 오른쪽 문으로 이동한다.
*/

#include <stdio.h>

int n = 7;	// 문의 갯수
int open1 = 2, open2 = 5;	// 초기에 열려있는 문 번호
int usecnt = 4;	// 사용할 문의 갯수
int use[4] = { 3,1,6,5 };	// 사용할 문의 번호
int movecnt, mincnt = 100;	// movecnt : 이동횟수, mincnt : 최소 이동횟수

void door(int left, int right, int using, int movecnt) {
	// left : 왼쪽 열린 문, rigth : 오른쪽 열린 문, using : 사용하려는 문, movecnt : 이동횟수
	if (using >= usecnt) {
		if (movecnt < mincnt)
			mincnt = movecnt;
	}
	else if (movecnt < mincnt) {
		if (use[using] <= left) {
			door(use[using], right, using + 1, movecnt + (left - use[using]));
		}	// 사용하려는 문이 열려 있는 문 번호보다 모두 작을 때
		else if (use[using] < right) {
			door(use[using], right, using + 1, movecnt + (use[using] - left));
			door(left, use[using], using + 1, movecnt + (right - use[using]));
		}
		else door(left, use[using], using + 1, movecnt + (use[using] - right));
		// 사용하려는 문이 열려 있는 문 번호보다 모두 클때
	}
}

int main()
{
	door(open1, open2, 0, 0);
	printf("%d", mincnt);
	return 0;
}