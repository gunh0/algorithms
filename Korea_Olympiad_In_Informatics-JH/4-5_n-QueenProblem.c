/*
4X4 ü���ǿ� 4���� ������ ��ġ�Ϸ��� �Ѵ�.
�̶� � �� ���յ� ���� ��, ��, �밢���� ��ġ�ؼ��� �ȵȴ�.
�̷��� ������ �����ϴ� ������ ��ġ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

Bounding Function
�� ������ ��ǥ�� Q1(X,Y), Q2(V,W)��� �Ѵٸ�,
- ���� �࿡ ��ġ�Ѵٸ� X=V �̴�.
- ���� ���� ��ġ�Ѵٸ� Y=W �̴�.
- ���� �밢���� ��ġ�Ѵٸ� X+Y=V+W �̰ų� X-Y=V-W �̴�.
*/

#include <stdio.h>

int p_loc[4][5];	// i��° ������ ��ġ�� �� �ִ� ������ ��ġ
int loc[4];	// i��° ������ ��ġ�� ��ġ

int promising_ioc(int qnum)	// ������ ��ġ�� �����ϰ� ��� ������ �� �ִ����� ��������
{
	int x, y, v, w;
	int i, j;
	int temp[5];

	if (qnum == 0) {	// ù��° ������ ��� ���� ��ġ�� �� �ִ�.
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
			w = loc[i];	// ��ġ�� ������ ��ġ
			x = qnum;
			for (y = 0; y < 4; y++) {	// x, y�� ��ġ�� ������ ��ġ
				if (v == x || w == y || (v + w) == (x + y) || (v - w) == (x - y))
					temp[y] = 0;	// �� �� ���� ��ġ
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

		p_loc[qnum][j] = -1;	// �� �̻� ������ ���� ����.
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
			loc[qnum] = p_loc[qnum][i];	// ������ ��ġ�� ���� ������ �ʴ� ��ġ Ž��
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