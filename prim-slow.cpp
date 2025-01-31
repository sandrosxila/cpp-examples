#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from; 
    int to;
    int weight;
};

// Function to find sum of weights of edges of the Minimum Spanning Tree.
vector<Edge> spanningTree(int V, vector<vector<int>> adj[]) {
    vector<bool> inMST(V, false);    // Tracks if a vertex is included in MST
    vector<int> min_weight_to(V, INT_MAX);    // Minimum weight edge to a vertex
    vector<int> min_from(V, INT_MAX);
    

    // Start with the first vertex
    min_weight_to[0] = 0;

    for (int count = 0; count < V; count++) {
        // Find the vertex with the smallest key value not in MST
        int u = -1;
        int min_w = INT_MAX;

        for (int i = 0; i < V; i++) {
            if (!inMST[i] && min_weight_to[i] < min_w) {
                min_w = min_weight_to[i];
                u = i;
            }
        }

        // Include the vertex in MST
        inMST[u] = true;
        
        // Update key values for adjacent vertices
        for (auto &edge : adj[u]) {
            int v = edge[0];
            int weight = edge[1];
            if (!inMST[v] && weight < min_weight_to[v]) {
                min_weight_to[v] = weight;
                min_from[v] = u;
            }
        }
    }

    vector<Edge> mst;
    for(int v = 1; v < V; v++){
        mst.push_back({.from = min_from[v], .to = v, .weight = min_weight_to[v]});
    }

    return mst;
}

int main() {
    int E = 14;
    int V = 9;

    vector<int> from   {0,  0,  1,  1,  7,  7,  2,  8,  2,  2,  6,  3,  3,  5};
    vector<int> to     {1,  7,  7,  2,  8,  6,  8,  6,  3,  5,  5,  5,  4,  4};
    vector<int> weight {4,  8, 11,  8,  7,  1,  2,  6,  7,  4,  2, 14,  9,  10};

    vector<vector<int>> adj[V];

    for (int i = 0; i < E; i++) {
        int u = from[i], v = to[i], w = weight[i];
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }

    vector<Edge> mst = spanningTree(V, adj);

    for(auto edge : mst) {
        cout << edge.from << ' ' << edge.to << ' ' << edge.weight << endl;
    }

    return 0;
}