
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[100];

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int main() {
    int V = 6, E = 9;

    Edge edges[] = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 7},
        {2, 4, 6},
        {3, 4, 8},
        {3, 5, 9},
        {4, 5, 1}
    };

    for (int i = 0; i < V; i++)
        parent[i] = i;

    sort(edges, edges + E, compare);

    int total = 0;
    cout << "Edge \tWeight\n";

    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            cout << u << " - " << v
                 << "\t" << edges[i].w << endl;

            total += edges[i].w;
            unite(u, v);
        }
    }

    cout << "Total weight: " << total << endl;

    return 0;
}
