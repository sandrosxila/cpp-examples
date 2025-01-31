#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& v, map<int, bool> &visited, int vertex) {
    if(visited[vertex])
        return;
    
    visited[vertex] = true;
    v.push_back(vertex);
    
    for(auto nextVertex : adj[vertex]) {
        dfs(adj, v, visited, nextVertex);
    }
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    vector<int> v;
    map<int, bool> visited;
    dfs(adj, v, visited, 0);
    
    return v;
}

int main() {
    int V = 5, E = 4;
    vector<vector<int>> adj(V);

    vector<pair<int,int>> edges = { {0, 2}, {0, 3}, {0, 1}, {2, 4} };

    for (int i = 0; i < E; i++) {
        auto &[u, v] = edges[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vertices = dfsOfGraph(adj);
    for (auto vertex : vertices) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}