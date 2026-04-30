/*
Basic Question: Find the fingerprint that appears more than n/2 times using only equality-style comparisons.
Topic: Divide and Conquer
Idea Used: Recursively compute a majority candidate for each half, then verify which candidate dominates the combined range.
*/
#include <bits/stdc++.h>
using namespace std;

static int majorityCandidate(const vector<int>& a, int left, int right) {
    if (left == right) return a[left];
    int mid = left + (right - left) / 2;
    int x = majorityCandidate(a, left, mid);
    int y = majorityCandidate(a, mid + 1, right);
    if (x == y) return x;

    int countX = 0, countY = 0;
    for (int i = left; i <= right; i++) {
        if (a[i] == x) countX++;
        if (a[i] == y) countY++;
    }
    return (countX > countY) ? x : y;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int candidate = majorityCandidate(a, 0, n - 1);
    int count = 0;
    for (int x : a) if (x == candidate) count++;

    if (count > n / 2) cout << candidate << "\n";
    else cout << "No majority element\n";
    return 0;
}
