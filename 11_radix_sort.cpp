/*
Basic Question: Sort a list of integers using Radix Sort.
Topic: Radix Sort
Idea Used: Repeatedly apply stable counting sort on each digit from least significant to most significant.
*/
// iit2024243
// Abdul Azeem Ansari
// TC: O(d * n)   where d = number of digits
// SC: O(n)

#include <bits/stdc++.h>
using namespace std;

// Stable counting sort based on digit (exp = 1, 10, 100...)
void countSortByDigit(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> ans(n, 0);
    vector<int> ct(10, 0);  // digits 0–9

    // Count frequency of digits
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        ct[digit]++;
    }

    // Prefix sum
    for (int i = 1; i < 10; i++) {
        ct[i] += ct[i - 1];
    }

    // Shift right by 1 (stable positioning)
    for (int i = 9; i > 0; i--) {
        ct[i] = ct[i - 1];
    }
    ct[0] = 0;

    // Build output (stable)
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        ans[ct[digit]++] = arr[i];
    }

    arr = ans;  // copy back
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int Mx = INT_MIN;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        Mx = max(Mx, arr[i]);
    }

    // Radix Sort
    for (int exp = 1; Mx / exp > 0; exp *= 10) {
        countSortByDigit(arr, exp);
    }

    for (auto x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
