/*
Basic Question: Count how many intervals are not contained inside any other interval.
Topic: Sorting / Greedy Scan
Idea Used: Sort by left endpoint ascending and right endpoint descending, then keep only intervals that extend the farthest seen so far.
*/
#include <bits/stdc++.h>
using namespace std;

struct Interval {
    long long l, r;
};

int main() {
    int n;
    cin >> n;
    vector<Interval> intervals(n);
    for (int i = 0; i < n; i++) cin >> intervals[i].l >> intervals[i].r;

    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        if (a.l != b.l) return a.l < b.l;
        return a.r > b.r;
    });

    long long maxRight = LLONG_MIN;
    int count = 0;
    for (const auto& in : intervals) {
        if (in.r > maxRight) {
            count++;
            maxRight = in.r;
        }
    }

    cout << count << "\n";
    return 0;
}
