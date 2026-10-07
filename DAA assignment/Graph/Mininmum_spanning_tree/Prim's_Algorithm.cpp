#include <iostream>
using namespace std;

#define INF 9999

void prim(int graph[5][5], int n)
{
    int parent[5];
    int key[5];
    bool visited[5] = {false};

    for (int i = 0; i < n; i++)
        key[i] = INF;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++)
    {
        int min = INF;
        int u;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && key[i] < min)
            {
                min = key[i];
                u = i;
            }
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

    for (int i = 1; i < n; i++)
        cout << parent[i] << " - " << i
             << " : " << graph[i][parent[i]] << endl;
}

int main()
{
    int graph[5][5] =
    {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(graph, 5);

    return 0;
}