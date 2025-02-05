#include <bits/stdc++.h>
using namespace std;

int totalCost(vector<vector<int>>& cost, int p, int mask) {
    int n = cost.size();
    
    if(mask == (1 << n) - 1) {
        return cost[p][0];
    }
    
    int sum = INT_MAX;
    
    for(int i = 0; i < n; i++) {
        if(mask & (1 << i)){
            continue;
        }
        
        sum = min(sum, cost[p][i] + totalCost(cost, i, mask | (1 << i)));
    }
    
    return sum;
}

int tsp(vector<vector<int>>& cost) {
    int n = cost.size();
    
    return totalCost(cost, 0, 1);
}

int main(){
  vector<vector<int>> cost = {
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
  };

  int res = tsp(cost);
  cout << res << endl;
  return 0;
}