#include <iostream>
using namespace std;

#define INF 9999

void dijkstra(int graph[5][5], int source)
{
    int dist[5];
    bool visited[5] = {false};

    for (int i = 0; i < 5; i++)
        dist[i] = INF;

    dist[source] = 0;

    for (int count = 0; count < 4; count++)
    {
        int min = INF;
        int u;

        for (int i = 0; i < 5; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for (int v = 0; v < 5; v++)
        {
            if (graph[u][v] != 0 && !visited[v])
            {
                if (dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest distances from " << source << ":\n";

    for (int i = 0; i < 5; i++)
        cout << source << " -> " << i << " = " << dist[i] << endl;
}

int main()
{
    int graph[5][5] =
    {
        {0, 2, 4, 0, 0},
        {2, 0, 1, 7, 0},
        {4, 1, 0, 3, 5},
        {0, 7, 3, 0, 2},
        {0, 0, 5, 2, 0}
    };

    dijkstra(graph, 0);

    return 0;
}