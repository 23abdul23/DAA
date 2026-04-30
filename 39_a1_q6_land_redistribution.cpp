/*
Basic Question: Find the highest feasible value of f for land redistribution and the corresponding value of c.
Topic: Binary Search / Prefix Feasibility
Idea Used: The best f is floor(total land / n); for a chosen f, binary search the largest c whose collected surplus still covers the deficit.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long total = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
        maxVal = max(maxVal, a[i]);
    }

    // Best possible f
    long long f = total / n;

    // Compute deficit
    long long deficit = 0;
    for (auto x : a)
        if (x < f)
            deficit += (f - x);

    // Binary search for c
    long long low = f, high = maxVal, ansC = f;

    while (low <= high) {
        long long mid = (low + high) / 2;

        long long surplus = 0;
        for (auto x : a)
            if (x > mid)
                surplus += (x - mid);

        if (surplus >= deficit) {
            ansC = mid;        // feasible
            low = mid + 1;     // try larger c
        } else {
            high = mid - 1;
        }
    }

    cout << "Highest f: " << f << "\n";
    cout << "Best c: " << ansC << "\n";
}