/*
Basic Question: Select the maximum number of non-overlapping activities from given start and finish times.
Topic: Greedy Algorithm
Idea Used: Sort activities by finish time and repeatedly choose the next activity that starts after the last selected one.
*/
//TC : O(n)
//SC : O(n)
//
//iit2024243
//Abdul Azeem
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> st, fi;
    vector<pair<int, int>> activities;  // (finish, start)
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        st.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        activities.push_back({x, st[i]});
    }

    sort(activities.begin(), activities.end());
    //check previous finish , and use that for the next comparision 
    int lastFinish = -1; 

    for (int i = 0; i < n; i++) {
        int start = activities[i].second;
        int finish = activities[i].first;

        if (start >= lastFinish) {
            ans++; 
            lastFinish = finish; 
        }
    }

    cout << ans << endl;
    return 0;
}
