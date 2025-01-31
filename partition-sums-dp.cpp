#include <bits/stdc++.h>
using namespace std;

const int MAX_SUM = 20005; 

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum % 2)
        return false;

    int target = sum / 2;
    unordered_set<int> dp;
    dp.insert(0);

    for(int num : nums) {
        for(auto s : vector(dp.begin(), dp.end())){
            if(s + num == target) {
                return true;
            }

            dp.insert(s + num);
        }
    }
    
    return false;
}

int main() {
    vector<int> arr = { 1, 5, 11, 5};

    if (canPartition(arr)) {
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
}