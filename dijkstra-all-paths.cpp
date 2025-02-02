#include <bits/stdc++.h>
using namespace std;
int main() {
	int n = 5;
	int a[n][n] = {
    {0, 5, 10, 2, 0},
    {5, 0, 3, 7, 2},
    {10, 3, 0, 0, 0},
    {2, 7, 0, 0, 3},
    {0, 2, 0, 3, 0}
  };

	vector<vector<int>> adj(n + 1), dist(n + 1, vector<int>(n + 1, 1e9));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(a[i][j] != 0) {
				adj[i].push_back(j);
			}
		}
	}

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	for(int i = 0; i < n; i++) {
		pq.push({0, {i, i}});
		dist[i][i] = 0;
	}
	
	while(!pq.empty()) {
		auto [d, node] = pq.top();
		auto [v, src] = node;
		pq.pop();

		for(auto u : adj[v]) {
			if(d + a[u][v] < dist[src][u]) {
				dist[src][u] = d + a[u][v];
				pq.push({dist[src][u], {u, src}});
			}
		}
	}

  vector<pair<int,int>> queries = {{0, 4}, {2, 3}, {1, 3}};

	int q = queries.size();
  
	for(int i = 0; i < q; i++) {
		auto &[u, v] = queries[i];
		cout << dist[u][v] << endl;
	}
}