/*
Basic Question: Partition an ordered sequence of cities between two people so the total traveled distance is minimized.
Topic: Dynamic Programming
Idea Used: Process cities in order and keep DP states for the last city visited by each person, assigning each new city to one of them.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int next = max(i, j) + 1;
            if (next >= n) continue;

            dp[next][j] = min(dp[next][j], dp[i][j] + dist[i][next]);
            dp[i][next] = min(dp[i][next], dp[i][j] + dist[j][next]);
        }
    }

    cout << dp[n-1][n-1];
}