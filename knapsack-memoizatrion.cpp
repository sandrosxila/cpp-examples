#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int knapsack(int c, int i, vector<int>& v, vector<int>& w, vector<unordered_map<int, int>>& memo) {
	int n = v.size();

	if(c == 0 || i == n) {
		return 0;
	}

	if(memo[i].find(c) != memo[i].end()) {
		return memo[i][c];
	}

	if(c < w[i]) {
		return memo[i][c] = knapsack(c, i + 1, v, w, memo);
	}

	return memo[i][c] = max(
		knapsack(c, i + 1, v, w, memo),
		v[i] + knapsack(c - w[i], i + 1, v, w, memo)
	);
}

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> v(n), w(n);
	vector<unordered_map<int, int>> memo(n);

	for(int i = 0; i < n; i++)
		cin>>v[i]; 

	for(int i = 0; i < n; i++)
		cin>>w[i]; 

	cout << knapsack(c, 0, v, w, memo);

	return 0;
}