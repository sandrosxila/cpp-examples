#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from; 
    int to;
    int weight;
};

// Function to find sum of weights of edges of the Minimum Spanning Tree.
vector<Edge> spanningTree(int V, vector<vector<int>> adj[]) {
    vector<bool> visited(V, false);
    vector<Edge> mst;
    
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    
    pq.push({0, {-1, 0}});
    while(!pq.empty()) {
        int weight = pq.top().first;
        int prev = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();
        
        if(visited[v] == true)
            continue;
        
        visited[v] = true;
        
        if(prev != -1)
            mst.push_back({.from = prev, .to = v, .weight = weight});
        
        for(auto &edge : adj[v]) {
            int u = edge[0];
            int w = edge[1];
            pq.push({w, {v, u}});
        }
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