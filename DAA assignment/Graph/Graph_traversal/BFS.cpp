#include <iostream>
#include <queue>
using namespace std;

class Graph
{
    int V;
    int adj[10][10];

public:
    Graph(int v)
    {
        V = v;

        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v)
    {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void BFS(int start)
    {
        bool visited[10] = {false};
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int v = 0; v < V; v++)
            {
                if (adj[u][v] == 1 && !visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "BFS Traversal: ";
    g.BFS(0);

    return 0;
}