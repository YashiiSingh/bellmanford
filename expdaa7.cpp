#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int source) {
    vector<int> dist(V, INF);
    dist[source] = 0;

    // Step 1: Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        bool updated = false;

        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INF &&
                (long long)dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }

        // Stop early if no distance changes
        if (!updated)
            break;
    }

    // Step 2: Check for a negative-weight cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (dist[u] != INF &&
            (long long)dist[u] + w < dist[v]) {
            cout << "Negative-weight cycle detected!\n";
            return;
        }
    }

    // Step 3: Print shortest distances
    cout << "Vertex\tDistance from Source\n";

    for (int i = 0; i < V; i++) {
        cout << i << "\t";

        if (dist[i] == INF)
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }
}

int main() {
    int V = 5;
    int E = 8;

    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int source = 0;

    bellmanFord(V, E, edges, source);

    return 0;
}
