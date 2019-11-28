/*
���� Vi���� ����Ͽ� ��� ������ �ѹ����� �湮�ϰ� ���� ��������
�ǵ��ƿ��� ��θ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ��ΰ� ���ٸ� "impossible"�� ����Ͻÿ�.
*/

#include <stdio.h>

int w[6][6] = { 0,1,0,1,1,0,
	1,0,1,1,0,0,
	0,1,0,0,0,1,
	1,1,0,0,0,0,
	1,0,0,0,0,1,
	0,0,1,0,1,0 };	// �׷����� ����� �����࿭
int path[6];	// �湮�� �������� ���
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
		if (i == 5) {	// ��� ������ �湮������ ���
			for (j = 0; j < 6; j++)
				printf("V%d->", path[j]);
			printf("V%d\n", path[0]);
			flag = 1;
		}
		else
		{
			for (j = 2; j <= 6; j++)	// j=1�� ��� �����̹Ƿ� ����
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
