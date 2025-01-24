#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int c, int i, vector<int>& v, vector<int>& w) {
	int n = v.size();

	if(c == 0 || i == n) {
		return 0;
	}

	if(c < w[i]) {
		return knapsack(c, i + 1, v, w);
	}

	return max(
		knapsack(c, i + 1, v, w),
		v[i] + knapsack(c - w[i], i + 1, v, w)
	);
}

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> v(n), w(n);

	for(int i = 0; i < n; i++)
		cin>>v[i]; 

	for(int i = 0; i < n; i++)
		cin>>w[i]; 

	cout << knapsack(c, 0, v, w);

	return 0;
}