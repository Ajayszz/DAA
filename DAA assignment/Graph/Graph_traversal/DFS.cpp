#include <iostream>
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

    void DFS(int u, bool visited[])
    {
        visited[u] = true;
        cout << u << " ";

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] == 1 && !visited[v])
                DFS(v, visited);
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

    bool visited[5] = {false};

    cout << "DFS Traversal: ";
    g.DFS(0, visited);

    return 0;
}