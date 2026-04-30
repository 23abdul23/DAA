/*
Basic Question: Solve the integer knapsack problem when duplicate items are allowed.
Topic: Dynamic Programming
Idea Used: Use one-dimensional DP where each capacity keeps the best value achievable by repeatedly reusing item types.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, capacity;
    cin >> n >> capacity;
    vector<int> size(n), value(n);
    for (int i = 0; i < n; i++) cin >> size[i] >> value[i];

    vector<long long> dp(capacity + 1, 0);
    for (int c = 0; c <= capacity; c++) {
        for (int i = 0; i < n; i++) {
            if (size[i] <= c) {
                dp[c] = max(dp[c], dp[c - size[i]] + value[i]);
            }
        }
    }

    cout << dp[capacity] << "\n";
    return 0;
}
