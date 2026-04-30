/*
Basic Question: Find the median of the union of two sorted arrays of equal size in O(log n) time.
Topic: Binary Search
Idea Used: Use the partition-based median algorithm to split both arrays so the left half and right half are balanced.
*/
#include <bits/stdc++.h>
using namespace std;

double findMedian(vector<int>& A, vector<int>& B) {
    if (A.size() > B.size()) return findMedian(B, A); // ensure A is smaller

    int n = A.size(), m = B.size();
    int low = 0, high = n;

    while (low <= high) {
        int cutA = (low + high) / 2;
        int cutB = (n + m + 1) / 2 - cutA;

        int l1 = (cutA == 0) ? INT_MIN : A[cutA - 1];
        int l2 = (cutB == 0) ? INT_MIN : B[cutB - 1];

        int r1 = (cutA == n) ? INT_MAX : A[cutA];
        int r2 = (cutB == m) ? INT_MAX : B[cutB];

        // correct partition
        if (l1 <= r2 && l2 <= r1) {
            if ((n + m) % 2 == 0)
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            else
                return max(l1, l2);
        }

        else if (l1 > r2)
            high = cutA - 1;
        else
            low = cutA + 1;
    }

    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    cout << fixed << setprecision(2) << findMedian(A, B);
}