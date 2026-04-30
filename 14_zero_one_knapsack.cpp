/*
Basic Question: Solve the 0/1 Knapsack problem for given weights, values, and capacity.
Topic: Dynamic Programming
Idea Used: Use recursion with memoization to decide for each item whether to take it or leave it.
*/
//iit2024243
//Abdul Azeem Ansari
//
//TC: O(n*k)
//SC: O(n*k)
#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &dp, int i, int k, const vector<int> &wt, const vector<int> &val) {
    int n = wt.size();

    if (i >= n || k <= 0) {
        return 0;
    }

    if (dp[i][k] != -1) {
        return dp[i][k];
    }

    int ntake = solve(dp, i + 1, k, wt, val);

    int take = 0;
    if (k >= wt[i]) {
        take = val[i] + solve(dp, i + 1, k - wt[i], wt, val);
    }

    return dp[i][k] = max(take, ntake);
}

int main() {
    int n;
    cin >> n;
    vector<int> wt(n), val(n);

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    int cap;
    cin >> cap;

    vector<vector<int>> dp(n, vector<int>(cap + 1, -1));

    cout << solve(dp, 0, cap, wt, val) << endl;

    return 0;
}
