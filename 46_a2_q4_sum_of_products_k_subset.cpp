/*
Basic Question: Compute the sum of products of all subsets of size k.
Topic: Dynamic Programming
Idea Used: Build the kth elementary symmetric sum using a one-dimensional DP updated from right to left.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n), dp(k + 1, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    dp[0] = 1;
    for (long long x : a) {
        for (int j = k; j >= 1; j--) {
            dp[j] += x * dp[j - 1];
        }
    }

    cout << dp[k] << "\n";
    return 0;
}
