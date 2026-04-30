/*
Basic Question: Compute the maximum profit possible by buying once and selling once.
Topic: Array / Greedy
Idea Used: Track the minimum price seen so far and update the best profit for each day in one pass.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> price(n);
    for (int i = 0; i < n; i++) cin >> price[i];

    long long bestProfit = 0;
    long long minPrice = LLONG_MAX;
    for (long long p : price) {
        minPrice = min(minPrice, p);
        bestProfit = max(bestProfit, p - minPrice);
    }

    cout << bestProfit << "\n";
    return 0;
}
