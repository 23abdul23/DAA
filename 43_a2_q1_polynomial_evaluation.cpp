/*
Basic Question: Evaluate a polynomial at x = x using O(n) additions and multiplications.
Topic: Horner's Rule
Idea Used: Fold the coefficients from highest degree to lowest so each step uses one multiplication and one addition.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long value = 0;
    for (int i = n - 1; i >= 0; i--) value = value * x + a[i];
    cout << value << "\n";
    return 0;
}
