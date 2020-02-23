#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <memory.h>

#define swap(a,b){int t = a; a = b; b = t;}
#define MAX_NODE 100001

using namespace std;

// depth :: ����� ����(����)
// ac[x][y] :: x�� 2^y��° ������ �ǹ�
int depth[MAX_NODE];
int ac[MAX_NODE][20];
int parent[MAX_NODE];

typedef pair<int, int> pii;
vector<int> graph[MAX_NODE];

int max_level;

void make_tree(int here, int parent)
{
	// here�� ���̴� �θ������ + 1
	depth[here] = depth[parent] + 1;

	// here�� 1��° ������ �θ���
	ac[here][0] = parent;

	// MAX_NODE�� log2�� ���� ������ ���ش�.
	max_level = (int)floor(log2(MAX_NODE));

	for (int i = 1; i <= max_level; i++)
	{
		// tmp :: here�� 2^(i-1)��° ����
		/*
		��, ac[here][i] = ac[tmp][i-1]��
		here�� 2^i��° ������ tmp�� 2^(i-1)��° ������ 2^(i-1)��° ����� ���ٴ� �ǹ�
		������� i = 3�϶�
		here�� 8��° ������ tmp(here�� 4��° ����)�� 4��° ����� ����.
		i =  4�϶� here�� 16��° ������ here�� 8��° ����(tmp)�� 8��°�� ����.
		*/
		int tmp = ac[here][i - 1];
		ac[here][i] = ac[tmp][i - 1];
	}

	// dfs �˰���
	int len = graph[here].size();
	for (int i = 0; i < len; i++)
	{
		int there = graph[here][i];
		if (there != parent)
			make_tree(there, here);
	}
}

int main()
{
	int tc, n;

	cin >> tc;
	while (tc--)
	{
		memset(depth, 0, sizeof(depth));
		memset(ac, 0, sizeof(ac));
		memset(parent, 0, sizeof(parent));
		for (int i = 0; i < MAX_NODE; i++)
			graph[i].clear();

		cin >> n;

		// ����� �׷��� ����
		for (int i = 1; i < n; i++)
		{
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);

			parent[to] = from;
		}

		// make_tree�� 1,0�� ���⶧���� 0�� -1�� ����
		int root;
		for (int i = 1; i <= n; i++)
			if (parent[i] == 0)
			{
				root = i;
				break;
			}

		depth[0] = -1;

		// ��Ʈ ����� 1�� ������ Ʈ�� ����
		make_tree(root, 0);

		int a, b;
		cin >> a >> b;

		if (depth[a] != depth[b])
		{
			// depth[b] >= depth[a]�� �ǵ��� swap
			if (depth[a] > depth[b])
				swap(a, b);

			// b�� �÷��� depth�� �����ش�.
			for (int i = max_level; i >= 0; i--)
			{
				// b�� 2^i��° ������ a�� depth���� ũ�ų� ������ ��� ������ Ÿ����.
				if (depth[a] <= depth[ac[b][i]])
					b = ac[b][i];
			}
		}

		int lca = a;

		// a�� b�� �ٸ��ٸ� ���� ���̰� ������
		// ���̸� ��� �÷� ������ ������ ������ �ݺ��Ѵ�.
		if (a != b)
		{
			for (int i = max_level; i >= 0; i--)
			{
				if (ac[a][i] != ac[b][i])
				{
					a = ac[a][i];
					b = ac[b][i];
				}
				lca = ac[a][i];
			}
		}
		printf("%d\n", lca);
	}

	return 0;
}