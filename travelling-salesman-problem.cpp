#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>>& cost) {
    int n = cost.size();

    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));

    for(int p = 0; p < n; p++)
        dp[(1 << n) - 1][p] = cost[p][0];

    for(int mask = (1 << n) - 2; mask > 0; mask--) {
        for(int p = 0; p < n; p++) {
            if(mask & (1 << p)){
                for(int i = 0; i < n; i++){
                    if(mask & (1 << i)){
                        continue;
                    }

                    dp[mask][p] = min(dp[mask][p], cost[p][i] + dp[mask | (1 << i)][i]);
                }
            }
        }
    }

    return dp[1][0];
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