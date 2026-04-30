/*
Basic Question: Find the median of the union of two sorted arrays of equal size in O(log n) time.
Topic: Binary Search
Idea Used: Use the partition-based median algorithm to split both arrays so the left half and right half are balanced.
*/
#include <bits/stdc++.h>
using namespace std;

double medianTwoSortedArrays(const vector<int>& a, const vector<int>& b) {
    const vector<int> *x = &a, *y = &b;
    if (a.size() > b.size()) swap(x, y);

    int n = static_cast<int>(x->size());
    int m = static_cast<int>(y->size());
    int leftSize = (n + m + 1) / 2;

    int low = 0, high = n;
    while (low <= high) {
        int cutX = low + (high - low) / 2;
        int cutY = leftSize - cutX;

        int leftX = (cutX == 0) ? INT_MIN : (*x)[cutX - 1];
        int leftY = (cutY == 0) ? INT_MIN : (*y)[cutY - 1];
        
        int rightX = (cutX == n) ? INT_MAX : (*x)[cutX];
        int rightY = (cutY == m) ? INT_MAX : (*y)[cutY];

        if (leftX <= rightY && leftY <= rightX) {
            if ((n + m) % 2 == 0) {
                return (max(leftX, leftY) + min(rightX, rightY)) / 2.0;
            }
            return static_cast<double>(max(leftX, leftY));
        }

        if (leftX > rightY) high = cutX - 1;
        else low = cutX + 1;
    }
    return 0.0;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    cout << fixed << setprecision(1) << medianTwoSortedArrays(a, b) << "\n";
    return 0;
}
