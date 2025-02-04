#include <bits/stdc++.h>
using namespace std;

#define INF 1000

vector<vector<int>> floydWarshall(vector<vector<pair<int, int>>> &adj, int n)
{
  vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INF));

  for (int v = 1; v <= n; v++)
    matrix[v][v] = 0;

  for (int v = 1; v <= n; v++)
  {
    for (auto node : adj[v])
    {
      int u = node.first;
      int w = node.second;
      matrix[v][u] = w;
    }
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      for (int k = 1; k <= n; k++)
      {
        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
      }
    }
  }

  return matrix;
}

void getOddPairs(vector<vector<pair<int, int>>> &oddPairs, vector<pair<int, int>> &pairs, vector<int> &oddNodes, int visited)
{
  int n = oddNodes.size();

  if (pairs.size() == n / 2)
  {
    oddPairs.push_back(pairs);

    return;
  }

  for (int i = 0; i < n; i++)
  {
    if (visited & (1 << i))
      continue;

    for (int j = i + 1; j < n; j++)
    {
      if (!(visited & (1 << j)))
      {
        pairs.push_back({oddNodes[i], oddNodes[j]});

        getOddPairs(oddPairs, pairs, oddNodes, visited | (1 << i) | (1 << j));

        pairs.pop_back();
      }
    }
  }
}

int chinesePostmanProblem(vector<vector<int>> &e, int n)
{
  vector<vector<pair<int, int>>> adj(n + 1);

  int s = 0;

  for (auto &edge : e)
  {
    int u = edge[0];
    int v = edge[1];
    int w = edge[2];

    s += w;

    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  vector<int> oddNodes;

  for (int i = 1; i <= n; i++)
  {
    int degree = adj[i].size();

    if (degree % 2 == 1)
    {
      oddNodes.push_back(i);
    }
  }

  if (oddNodes.empty())
  {
    return s;
  }

  vector<pair<int, int>> pairs;
  vector<vector<pair<int, int>>> oddPairs;

  getOddPairs(oddPairs, pairs, oddNodes, 0);

  vector<vector<int>> dist = floydWarshall(adj, n);

  int shortestPath = INT_MAX;
  for (auto path : oddPairs)
  {
    int distance = 0;
    for (auto p : path)
    {
      int u = p.first;
      int v = p.second;
      distance += dist[u][v];
    }
    shortestPath = min(shortestPath, distance);
  }

  if (shortestPath >= INF)
  {
    return -1;
  }

  return s + shortestPath;
}

int main() {
  int V = 8, E = 15;
  
  vector<vector<int>> edges{
    {2, 1, 11},
    {3, 1, 22},
    {3, 2, 6},
    {4, 1, 22},
    {4, 3, 25},
    {5, 1, 2},
    {5, 3, 5},
    {6, 1, 14},
    {6, 2, 15},
    {6, 3, 7},
    {7, 2, 18},
    {7, 4, 8},
    {7, 6, 8},
    {8, 1, 9},
    {8, 7, 23}
  };

  cout<<chinesePostmanProblem(edges, V)<<endl;
}