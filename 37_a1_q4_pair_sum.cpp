/*
Basic Question: Find a pair of integers in an array whose sum is S in O(n log n) time.
Topic: Sorting / Two Pointers
Idea Used: Sort the array, then move two pointers from both ends until the required sum is found.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long target;
    cin >> n >> target;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int left = 0, right = n - 1;
    while (left < right) {
        long long sum = a[left] + a[right];
        if (sum == target) {
            cout << a[left] << " " << a[right] << "\n";
            return 0;
        }
        if (sum < target) left++;
        else right--;
    }

    cout << "No pair found\n";
    return 0;
}
