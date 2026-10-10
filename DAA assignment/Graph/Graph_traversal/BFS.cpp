#include <iostream>
#include <queue>
using namespace std;

class Graph
{
    int V;
    int** adj;

public:
    Graph(int v)
    {
        V = v;

        adj = new int*[V];

        for (int i = 0; i < V; i++)
        {
            adj[i] = new int[V];

            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
        }
    }

    void addEdge(int u, int v)
    {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void BFS(int start)
    {
        bool* visited = new bool[V];

        for (int i = 0; i < V; i++)
            visited[i] = false;

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

        delete[] visited;
    }

    ~Graph()
    {
        for (int i = 0; i < V; i++)
            delete[] adj[i];

        delete[] adj;
    }
};

int main()
{
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    if (V <= 0)
    {
        cout << "Invalid number of vertices";
        return 0;
    }

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    if (E < 0)
    {
        cout << "Invalid number of edges";
        return 0;
    }

    cout << "Enter each edge (u v), using vertices 0 to "
         << V - 1 << ":\n";

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= V || v < 0 || v >= V)
        {
            cout << "Invalid edge";
            return 0;
        }

        g.addEdge(u, v);
    }

    int start;

    cout << "Enter starting vertex: ";
    cin >> start;

    if (start < 0 || start >= V)
    {
        cout << "Invalid starting vertex";
        return 0;
    }

    cout << "BFS Traversal: ";
    g.BFS(start);

    return 0;
}