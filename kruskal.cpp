#include <bits/stdc++.h>
#include "dsu.cpp"
using namespace std;

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
    int E = 14;
    int V = 9;

    vector<int> from   {0,  0,  1,  1,  7,  7,  2,  8,  2,  2,  6,  3,  3,  5};
    vector<int> to     {1,  7,  7,  2,  8,  6,  8,  6,  3,  5,  5,  5,  4,  4};
    vector<int> weight {4,  8, 11,  8,  7,  1,  2,  6,  7,  4,  2, 14,  9,  10};

    vector<Edge> mst = kruskals(V, from, to, weight);

    for(auto edge : mst) {
    cout << edge.from << ' ' << edge.to << ' ' << edge.weight << endl;
    }

    return 0;
}

/*
* run in powershell:
* g++ ./kruskal.cpp -o ./output/kruskal; ./output/kruskal
*/