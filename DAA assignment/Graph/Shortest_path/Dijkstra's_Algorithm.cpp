#include <iostream>
using namespace std;

#define INF 9999

void dijkstra(int** graph, int n, int source)
{
    int* dist = new int[n];
    bool* visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int min = INF;
        int u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != 0 && !visited[v])
            {
                if (dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from " << source << ":\n";

    for (int i = 0; i < n; i++)
    {
        cout << source << " -> " << i << " = ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    delete[] dist;
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

    int source;

    cout << "Enter source vertex (0 to " << n - 1 << "): ";
    cin >> source;

    if (source < 0 || source >= n)
    {
        cout << "Invalid source vertex";

        for (int i = 0; i < n; i++)
            delete[] graph[i];

        delete[] graph;
        return 0;
    }

    dijkstra(graph, n, source);

    for (int i = 0; i < n; i++)
        delete[] graph[i];

    delete[] graph;

    return 0;
}