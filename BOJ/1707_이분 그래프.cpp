#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 20000 + 1;
int K, V, E;
vector<int> graph[MAX];
int nodeColor[MAX];

void DFS(int nodeNum, int color)
{
    nodeColor[nodeNum] = color;
    for (int i = 0; i < graph[nodeNum].size(); i++)
    {
        int next = graph[nodeNum][i];
        if (!nodeColor[next])
            DFS(next, 3 - color);
    }
}

bool isBipartiteGraph(void)
{
    for (int i = 1; i <= V; i++)
        for (int j = 0; j < graph[i].size(); j++)
        {
            int next = graph[i][j];
            if (nodeColor[i] == nodeColor[next])
                return false;
        }
    return true;
}

int main(void)
{
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        for (int j = 1; j < MAX; j++)
            graph[j].clear();
        memset(nodeColor, 0, sizeof(nodeColor));
        cin >> V >> E;
        for (int j = 0; j < E; j++)
        {
            int node1, node2;
            cin >> node1 >> node2;
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        for (int j = 1; j <= V; j++)
            if (nodeColor[j] == 0)
                DFS(j, 1);
        if (isBipartiteGraph())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
