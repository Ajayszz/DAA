#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int* parent;

int find(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);

    parent[b] = a;
}

void kruskal(Edge edges[], int V, int E)
{
    sort(edges, edges + E, compare);

    parent = new int[V];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    int count = 0;
    int total = 0;

    cout << "Edges in MST:\n";

    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v))
        {
            cout << u << " - " << v
                 << " : " << edges[i].weight << endl;

            total += edges[i].weight;
            unite(u, v);
            count++;
        }
    }

    if (count == V - 1)
        cout << "Total weight: " << total;
    else
        cout << "MST does not exist. The graph is disconnected.";

    delete[] parent;
}

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

    kruskal(edges, V, E);

    delete[] edges;

    return 0;
}