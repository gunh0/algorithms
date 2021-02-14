#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to calculate the degree of kinship (촌수) between two people
int calculateKinship(vector<int> graph[], int n, int start, int end)
{
    vector<bool> visited(n + 1, false); // Track visited nodes
    vector<int> distance(n + 1, 0);     // Distance from start to each node

    queue<int> q;          // Queue for BFS
    visited[start] = true; // Mark the start node as visited
    q.push(start);         // Enqueue the start node

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (current == end)
        {
            return distance[current]; // Return the distance if end node is found
        }

        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i];
            if (!visited[next])
            {
                visited[next] = true;                   // Mark the node as visited
                distance[next] = distance[current] + 1; // Increment the distance
                q.push(next);                           // Enqueue the next node
            }
        }
    }

    return -1; // Return -1 if no path is found
}

int main()
{
    int n, start, end, m;
    cin >> n >> start >> end >> m;

    vector<int> graph[n + 1]; // Graph representation

    // Reading the parent-child relationships
    for (int i = 0; i < m; i++)
    {
        int parent, child;
        cin >> parent >> child;
        graph[parent].push_back(child); // Add child to parent's list
        graph[child].push_back(parent); // Add parent to child's list for bidirectional search
    }

    cout << calculateKinship(graph, n, start, end) << endl;

    return 0;
}
