#include <iostream>
using namespace std;

#define INF 9999

void floydWarshall(int** graph, int n)
{
    int** dist = new int*[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = new int[n];

        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest Distance Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] dist[i];

    delete[] dist;
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

    cout << "Enter the adjacency matrix (use " << INF
         << " for no edge):\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    }

    floydWarshall(graph, n);

    for (int i = 0; i < n; i++)
        delete[] graph[i];

    delete[] graph;

    return 0;
}