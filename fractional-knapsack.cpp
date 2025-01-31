#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

static bool compare(const Item &a, const Item &b) {
    double x = (double) a.value / a.weight; 
    double y = (double) b.value / b.weight; 
    
    return x > y;
}

// Function to get the maximum total value in the knapsack.
double fractionalKnapsack(vector<int> val, vector<int> wt, int capacity) {
    // Your code here
    int n = val.size();
    
    vector<Item> items(n);
    
    for(int i = 0; i < n; i++) {
        items[i].value = val[i];
        items[i].weight = wt[i];
    }
    
    sort(items.begin(), items.end(), compare);
    
    double maxValue{};
    
    for(int i = 0; i < n && capacity > 0; i++) {
        int load = min(capacity, items[i].weight);
        maxValue += load * ((double) items[i].value / items[i].weight);
        capacity-=load;
    }
    
    return maxValue;
}

int main() {
    cout << fractionalKnapsack((vector<int>){60, 100, 120}, (vector<int>){10, 20, 30}, 50);
    return 0;
}