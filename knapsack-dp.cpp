#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> v(n), w(n);
	unordered_map<int, int> dp, prev;

	for(int i = 0; i < n; i++)
		cin>>v[i]; 

	for(int i = 0; i < n; i++)
		cin>>w[i]; 

	int ans = 0;
	for(int i = n - 1; i >= 0; i--){
		swap(dp, prev);
		for(int j = 0; j <= c; j++) {
			if(j < w[i]) {
				dp[j] = prev[j];
			}
			else {
				dp[j] = max(
					prev[j], 
					v[i] + prev[j - w[i]]
				);
			}

			ans = max(ans, dp[j]);
		}
	}

	cout << ans;

	return 0;
}