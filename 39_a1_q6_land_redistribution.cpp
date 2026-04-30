/*
Basic Question: Find the highest feasible value of f for land redistribution and the corresponding value of c.
Topic: Binary Search / Prefix Feasibility
Idea Used: The best f is floor(total land / n); for a chosen f, binary search the largest c whose collected surplus still covers the deficit.
*/
#include <bits/stdc++.h>
using namespace std;

static long long deficitForF(const vector<long long>& a, long long f) {
    long long deficit = 0;
    for (long long x : a) if (x < f) deficit += f - x;
    return deficit;
}

static bool feasibleC(const vector<long long>& a, long long f, long long c, long long deficit) {
    if (c < f) return false;
    long long surplus = 0;
    for (long long x : a) if (x > c) surplus += x - c;
    return surplus >= deficit;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long total = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
        mx = max(mx, a[i]);
    }

    long long bestF = total / n;
    long long deficit = deficitForF(a, bestF);

    long long low = bestF, high = mx, bestC = bestF;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (feasibleC(a, bestF, mid, deficit)) {
            bestC = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Highest feasible f: " << bestF << "\n";
    cout << "Largest feasible c for this f: " << bestC << "\n";
    return 0;
}
