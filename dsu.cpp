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