#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> v(n), w(n);
	vector<unordered_map<int, int>> dp(n + 1);

	for(int i = 0; i < n; i++)
		cin>>v[i]; 

	for(int i = 0; i < n; i++)
		cin>>w[i]; 

	int ans = 0;
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j <= c; j++) {
			if(j < w[i]) {
				dp[i][j] = dp[i + 1][j];
			}
			else {
				dp[i][j] = max(
					dp[i + 1][j], 
					v[i] + dp[i + 1][j - w[i]]
				);
			}
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;

	return 0;
}