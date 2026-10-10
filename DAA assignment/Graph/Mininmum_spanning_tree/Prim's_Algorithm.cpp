#include <iostream>
using namespace std;

#define INF 9999

void prim(int** graph, int n)
{
    int* parent = new int[n];
    int* key = new int[n];
    bool* visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int min = INF;
        int u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
        }

        if (u == -1)
        {
            cout << "MST does not exist. The graph is disconnected.";
            delete[] parent;
            delete[] key;
            delete[] visited;
            return;
        }

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 && !visited[v] &&
                graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:\n";
    int total = 0;

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;

        total += graph[i][parent[i]];
    }

    cout << "Total weight: " << total;

    delete[] parent;
    delete[] key;
    delete[] visited;
}

int main()
{
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of vertices";
        return 0;
    }

    int** graph = new int*[n];

    for (int i = 0; i < n; i++)
        graph[i] = new int[n];

    cout << "Enter the adjacency matrix (0 for no edge):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    prim(graph, n);

    for (int i = 0; i < n; i++)
        delete[] graph[i];

    delete[] graph;

    return 0;
}