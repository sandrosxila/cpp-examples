#include <bits/stdc++.h>
using namespace std;

enum DIR { DOWN, RIGHT, DIAG };

string longestCommonSubsequence(string a, string b) {
    int n = a.size(), m = b.size();
    vector dp(n + 1, vector(m + 1, 0));
    vector dir(n + 1, vector(m + 1, 0));
    
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >=0; j--) {
            if(a[i] == b[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
                dir[i][j] = DIAG;
                continue;
            }

            if(dp[i + 1][j] > dp[i][j + 1]) {
              dp[i][j] = dp[i + 1][j];
              dir[i][j] = DOWN;
            }
            else {
              dp[i][j] = dp[i][j + 1];
              dir[i][j] = RIGHT;
            }
        }
    }

    string lcs = "";

    for(int i = 0, j = 0; i != n && j != m;) {
      if(dir[i][j] == DIAG){
        lcs += a[i];
        i++;
        j++;
      }
      if(dir[i][j] == DOWN) {
        i++;
      }
      else j++;
    }

    return lcs;
}

int main()
{

  cout << longestCommonSubsequence("AGGTAB", "GXTXAYB") << endl;

  return 0;
}