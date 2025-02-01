#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 5;

  int a[n][n] = {
    { 0, 3, 2, 0, 0 },
    { 3, 0, 5, 3, 0 },
    { 2, 5, 0, 0, 20 },
    { 0, 3, 0, 0, 4 },
    { 0, 0, 20, 4, 0 }
  };

  vector<vector<int>> adj(n + 1);
  vector<int> dist(n + 1, 1e9), prev(n + 1, -1);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(a[i][j] != 0) {
        adj[i].push_back(j);
      }
    }
  }

  int src = 0, dest = 4;

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  
  pq.push({0, src});
  dist[0] = 0;
  while(!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();

    for(auto u : adj[v]) {
      if(d + a[u][v] < dist[u]) {
        dist[u] = d + a[u][v];
        prev[u] = v;
        pq.push({dist[u], u});
      }
    }
  }

  vector<int> path {dest};

  for(int p = prev[dest]; p != -1; p = prev[p]) {
    path.push_back(p);
  }

  cout << dist[dest] << endl;
  for(int i = path.size() - 1; i >= 0; i--){
    cout << path[i] << ' ';
  }
  cout << endl;
}