#include <bits/stdc++.h>
using namespace std;

int lcs(string &a, string &b, int i, int j)
{
  int n = a.size();
  int m = b.size();

  if (i == n || j == m)
  {
    return 0;
  }

  if (a[i] == b[j])
  {
    return 1 + lcs(a, b, i + 1, j + 1);
  }

  return max(lcs(a, b, i + 1, j), lcs(a, b, i, j + 1));
}

int longestCommonSubsequence(string text1, string text2)
{
  return lcs(text1, text2, 0, 0);
}

int main() {
  int lcsSize = longestCommonSubsequence("AGGTAB", "GXTXAYB");

  cout<< lcsSize << endl;

  return 0;
}