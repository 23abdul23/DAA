/*
Basic Question: Identify the celebrity in O(n) queries.
Topic: Two-Pointer Elimination
Idea Used: Eliminate one candidate at a time, then verify the final candidate against everyone.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> knows(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> knows[i][j];
    }

    int candidate = 0;
    for (int i = 1; i < n; i++) {
        if (knows[candidate][i]) candidate = i;
    }

    for (int i = 0; i < n; i++) {
        if (i == candidate) continue;
        if (knows[candidate][i] || !knows[i][candidate]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << candidate << "\n";
    return 0;
}
