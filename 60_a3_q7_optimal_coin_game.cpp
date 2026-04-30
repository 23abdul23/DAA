/*
Basic Question: Determine the maximum amount the first player can guarantee in the optimal coin-row game.
Topic: Dynamic Programming
Idea Used: Use interval DP where choosing either end assumes the opponent then leaves the minimum future gain.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> coin(n);
    for (int i = 0; i < n; i++) cin >> coin[i];

    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = coin[i];

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            long long x = (i + 2 <= j) ? dp[i + 2][j] : 0;
            long long y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
            long long z = (i <= j - 2) ? dp[i][j - 2] : 0;
            dp[i][j] = max(coin[i] + min(x, y), coin[j] + min(y, z));
        }
    }

    cout << dp[0][n - 1] << "\n";
    return 0;
}
