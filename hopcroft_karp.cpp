#include <bits/stdc++.h>
using namespace std;

class HopcroftKarp {
  int m{}, n{};

  const int NIL{0}, INF{INT_MAX};

  vector<vector<int>> adj;

  vector<int> pair_u, pair_v, dist;

  HopcroftKarp(int m, int n) {
    this->m = m;
    this->n = n;
    adj = vector<vector<int>>(m + 1);
  }

  void addEdge(int u, int v) {
    adj[u].push_back(v);
  }

  bool bfs(){
    queue<int> q;

    for(int u = 1; u <= m; u++){
      if(pair_u[u] == NIL) {
        dist[u] = 0;
        q.push(u);
      }
      else {
        dist[u] = INF;
      }
    }

    dist[NIL] = INF;

    while(!q.empty()){
      int u = q.front();
      q.pop();

      if(dist[u] < dist[NIL]) {
        for(auto v : adj[u]) {
          if(dist[pair_v[v]] == INF) {
            dist[pair_v[v]] = dist[u] + 1;
            q.push(pair_v[v]);
          }
        }
      }
    }

    return dist[NIL] != INF;
  }

  // is there an augmenting path from vertex u 
  bool dfs(int u) {
    if(u == NIL)
      return true;

    for(auto v : adj[u]){
      if((dist[pair_v[v]] == dist[u] + 1) && dfs(pair_v[v]) == true) {
        pair_v[v] = u;
        pair_u[u] = v;

        return true;
      }
    }

    dist[u] = INF;
    return false;
  }

  int hopcroftKarpAlgorithm() {
    pair_u = vector<int>(m + 1, NIL);
    pair_v = vector<int>(n + 1, NIL);
    
    dist = vector<int>(m + 1);

    int result = 0;

    while(bfs()) {
      for(int u = 1; u <= m; u++){
        if(pair_u[u] != INF && dfs(u)){
          result++;
        }
      }
    }

    return result;
  }
};