/*
Basic Question: Cover all points on the real line using the minimum number of intervals of length 1.
Topic: Greedy Algorithm
Idea Used: Sort the points and whenever an uncovered point is found, start a unit interval at that point to cover as many following points as possible.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int count = 0;

    for (int i = 0; i < n; ) {
        double start = a[i];
        count++;

        while (i < n && a[i] <= start + 1)
            i++;
    }

    cout << count << endl;
}