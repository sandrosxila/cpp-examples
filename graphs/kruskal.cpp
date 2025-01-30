#include <bits/stdc++.h>
using namespace std;

class DSU {
    private:
    vector<int> parent, rank;
    public:
    DSU(int n) {
        parent = vector(n, 0);
        rank = vector(n, 0);
        
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find(parent[v]);
    }
    
    void merge(int x, int y) {
        int a = find(x);
        int b = find(y);
        
        if(a != b){  
            if(rank[a] < rank[b])
                swap(a, b);
            
            parent[b] = a;
            
            if(rank[a] == rank[b])
                rank[a]++;
        }
    }
};

struct Edge {
    int from; 
    int to;
    int weight;
};

vector<Edge> kruskals(int m, vector<int> u, vector<int> v, vector<int> w) {
    int n = u.size();
    vector<Edge> edges(n);
    vector<bool> visited(m);
    
    DSU dsu(m);
    
    for(int i = 0; i < n; i++) {
        edges[i].from = u[i];
        edges[i].to = v[i];
        edges[i].weight = w[i];
    }
    
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a.weight < b.weight;
    });
    
    vector<Edge> mst;
    for(int i = 0; i < n; i++) {
        if(dsu.find(edges[i].from) == dsu.find(edges[i].to)) {
            continue;
        }
        
        dsu.merge(edges[i].from, edges[i].to);
        mst.push_back(edges[i]);
    }
    
    return mst;
}

int main() {
  int E = 5;
  int V = 7;

  vector<int> from   {1,  1,  1,  1,  2,  3,  4};
  vector<int> to     {2,  3,  4,  5,  3,  4,  5};
  vector<int> weight {20, 50, 70, 90, 30, 40, 60};

  vector<Edge> mst = kruskals(V, from, to, weight);

  for(auto edge : mst) {
    cout << edge.from << ' ' << edge.to << ' ' << edge.weight << endl;
  }
  cout << endl;

  return 0;
}