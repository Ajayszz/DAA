#include <iostream>
using namespace std;

#define INF 9999

struct Edge
{
    int u, v, weight;
};

void bellmanFord(Edge edges[], int V, int E, int source)
{
    int dist[10];

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].weight;

        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            cout << "Negative weight cycle exists";
            return;
        }
    }

    cout << "Shortest distances from " << source << ":\n";

    for (int i = 0; i < V; i++)
        cout << source << " -> " << i << " = " << dist[i] << endl;
}

int main()
{
    Edge edges[] =
    {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -3},
        {2, 3, 4},
        {1, 3, 5}
    };

    int V = 4;
    int E = 5;

    bellmanFord(edges, V, E, 0);

    return 0;
}