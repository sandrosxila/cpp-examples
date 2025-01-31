#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start;
    int end;
};

bool compare(const Activity &a, const Activity &b) {
    if(a.end == b.end){
        return a.start < b.start;
    }
    
    return a.end < b.end;
}

int activitySelection(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<Activity> activities(n);
    for(int i = 0; i < n; i++) {
        activities[i].start = start[i];
        activities[i].end = end[i];
    }
    
    sort(activities.begin(), activities.end(), compare);
    
    int ans{}, last{-1};
    
    for(auto activity : activities) {
        if(last < activity.start) {
            last = activity.end;
            ans++;
        }
    }
    
    return ans;
}

int main() {
  int maxActivities = activitySelection((vector<int>){1, 3, 2, 5}, (vector<int>){2, 4, 3, 6});

  cout << maxActivities << endl;
}