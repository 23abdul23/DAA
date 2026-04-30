/*
Basic Question: Find the median of two databases using kth-smallest queries.
Topic: Binary Search
Idea Used: Simulate kth queries on two sorted databases and use partition binary search to find the nth smallest of the combined 2n values.
*/
#include <bits/stdc++.h>
using namespace std;

static int kthQuery(const vector<int>& db, int k) {
    return db[k - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int low = 0, high = n;
    while (low <= high) {
        int cutA = low + (high - low) / 2;
        int cutB = n - cutA;

        int leftA = (cutA == 0) ? INT_MIN : kthQuery(a, cutA);
        int leftB = (cutB == 0) ? INT_MIN : kthQuery(b, cutB);
        
        int rightA = (cutA == n) ? INT_MAX : kthQuery(a, cutA + 1);
        int rightB = (cutB == n) ? INT_MAX : kthQuery(b, cutB + 1);

        if (leftA <= rightB && leftB <= rightA) {
            cout << max(leftA, leftB) << "\n";
            return 0;
        }
        if (leftA > rightB) high = cutA - 1;
        else low = cutA + 1;
    }

    return 0;
}
