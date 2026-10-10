#include <iostream>
using namespace std;

#define INF 9999

struct Edge
{
    int u, v, weight;
};

void bellmanFord(Edge edges[], int V, int E, int source)
{
    int* dist = new int[V];

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
            delete[] dist;
            return;
        }
    }

    cout << "Shortest distances from " << source << ":\n";

    for (int i = 0; i < V; i++)
    {
        cout << source << " -> " << i << " = ";

        if (dist[i] == INF)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    delete[] dist;
}

int main()
{
    int V, E, source;

    cout << "Enter number of vertices: ";
    cin >> V;

    if (V <= 0)
    {
        cout << "Invalid number of vertices";
        return 0;
    }

    cout << "Enter number of edges: ";
    cin >> E;

    if (E < 0)
    {
        cout << "Invalid number of edges";
        return 0;
    }

    Edge* edges = new Edge[E];

    cout << "Enter each edge as: source destination weight\n";

    for (int i = 0; i < E; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;

        if (edges[i].u < 0 || edges[i].u >= V ||
            edges[i].v < 0 || edges[i].v >= V)
        {
            cout << "Invalid vertex number";
            delete[] edges;
            return 0;
        }
    }

    cout << "Enter source vertex: ";
    cin >> source;

    if (source < 0 || source >= V)
    {
        cout << "Invalid source vertex";
        delete[] edges;
        return 0;
    }

    bellmanFord(edges, V, E, source);

    delete[] edges;

    return 0;
}