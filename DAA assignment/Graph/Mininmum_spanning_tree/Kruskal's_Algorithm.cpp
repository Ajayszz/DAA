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

int parent[10];

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

    cout << "Total weight: " << total;
}

int main()
{
    Edge edges[] =
    {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    int V = 5;
    int E = 7;

    kruskal(edges, V, E);

    return 0;
}