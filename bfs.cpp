#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    queue<int> q;
    map<int, bool> visited;
    vector<int> v;
    
    q.push(0);
    while(!q.empty()) {
        int vertex = q.front();
        q.pop();
        visited[vertex] = true;
        v.push_back(vertex);
        
        for(auto nextVertex : adj[vertex]) {
            if(visited[nextVertex] == false)
                q.push(nextVertex);
        }
    }
    
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

    vector<int> vertices = bfsOfGraph(adj);
    for (auto vertex : vertices) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}