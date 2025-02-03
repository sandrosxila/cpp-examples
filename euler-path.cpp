#include <bits/stdc++.h>
using namespace std;

void traverseGraph(vector<int> adj[], int v, vector<bool> &visited)
{
  if (visited[v])
    return;

  visited[v] = true;

  for (auto u : adj[v])
    traverseGraph(adj, u, visited);
}

int isEulerCircuit(int V, vector<int> adj[])
{
  int degree[2];
  vector<bool> visited(V);

  traverseGraph(adj, 0, visited);

  int sumVisited = accumulate(visited.begin(), visited.end(), 0); // get sum of visited nodes

  for (int i = 0; i < V; i++)
  {
    int d = adj[i].size();
    if (d != 0) // ignore 0 nodes
      degree[d % 2]++;
  }

  if (sumVisited != degree[0] + degree[1])
    return 0; // neither euler path, nor euler cycle

  if (degree[1] == 2)
    return 1; // euler path

  else if (degree[1] == 0)
    return 2; // euler cycle

  return 0;
}

int main()
{
  int V = 7, E = 3;

  vector<int> adj[V];

  vector<pair<int, int>> edges = {{3, 2}, {3, 0}, {0, 1}};

  for (int i = 0; i < E; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int ans = isEulerCircuit(V, adj);
  
  if(ans == 1) {
    cout << "Graph has euler path\n";
  }
  else if(ans == 2) {
    cout << "Graph has euler cycle\n";
  }
  else {
    cout << "Graph does not have euler path, nor euler cycle\n";
  }

  return 0;
}