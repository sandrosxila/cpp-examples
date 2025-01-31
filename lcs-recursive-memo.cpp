#include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b, int i, int j, vector<vector<int>> &memo)
{
  int n = a.size();
  int m = b.size();

  if (i == n || j == m)
  {
    return 0;
  }

  if (memo[i][j] != -1)
  {
    return memo[i][j];
  }

  if (a[i] == b[j])
  {
    return memo[i][j] = 1 + lcs(a, b, i + 1, j + 1, memo);
  }

  return memo[i][j] = max(lcs(a, b, i + 1, j, memo), lcs(a, b, i, j + 1, memo));
}

int longestCommonSubsequence(string text1, string text2)
{
  int n = text1.size(), m = text2.size();
  vector memo(n, vector(m, -1));
  return lcs(text1, text2, 0, 0, memo);
}


int main()
{
  int lcsSize = longestCommonSubsequence("AGGTAB", "GXTXAYB");

  cout << lcsSize << endl;

  return 0;
}