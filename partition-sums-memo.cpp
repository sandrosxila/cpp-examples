#include <bits/stdc++.h>
using namespace std;

const int MAX_SUM = 20005; 

bool solve(vector<int>& nums, int i = 0, int s1 = 0, int s2 = 0, vector<vector<int>> &memo) {
    int n = nums.size();
    if(i == n) {
        return s1 == s2;
    }

    if(memo[i][s1] != -1) {
        return memo[i][s1];
    }

    return memo[i][s1] = solve(nums, i + 1, s1 + nums[i], s2, memo) || solve(nums, i + 1, s1, s2 + nums[i], memo);
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    vector memo = vector(n + 1, vector(20005, -1));
    return solve(nums);
}

int main() {
    vector<int> arr = { 1, 5, 11, 5};

    if (canPartition(arr)) {
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
}