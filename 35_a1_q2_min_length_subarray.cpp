/*
Basic Question: Find the minimum length subarray with sum at least S in O(n log n) time.
Topic: Prefix Sum / Binary Search
Idea Used: Build prefix sums and for each start position binary search the earliest end position whose sum reaches S.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long target;
    cin >> n >> target;

    vector<long long> a(n), prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }

    int answer = INT_MAX;
    for (int i = 0; i < n; i++) {
        long long need = prefix[i] + target;
        auto it = lower_bound(prefix.begin() + i + 1, prefix.end(), need);
        if (it != prefix.end()) {
            int x = (it - (prefix.begin() + i));
            answer = min(answer, x);
        }
    }

    cout << (answer == INT_MAX ? 0 : answer) << "\n";
    return 0;
}
