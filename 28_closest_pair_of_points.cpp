/*
Basic Question: Find the closest pair of points in the plane using divide and conquer.
Topic: Divide and Conquer
Idea Used: Split points by x-coordinate, solve both halves recursively, and check a narrow strip around the midpoint.
*/
#include <bits/stdc++.h>
using namespace std;

double dist(pair<int,int> a, pair<int,int> b) {
    return hypot(a.first - b.first, a.second - b.second);
}

double brute(vector<pair<int,int>> &pts, int l, int r) {
    double ans = DBL_MAX;
    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            ans = min(ans, dist(pts[i], pts[j]));
        }
    }
    return ans;
}

double closestUtil(vector<pair<int,int>> &pts, int l, int r) {
    if (r - l <= 3)
        return brute(pts, l, r);

    int m = (l + r) / 2;
    double dl = closestUtil(pts, l, m);
    double dr = closestUtil(pts, m + 1, r);
    double d = min(dl, dr);

    vector<pair<int,int>> strip;
    int midX = pts[m].first;

    for (int i = l; i <= r; i++) {
        if (abs(pts[i].first - midX) < d)
            strip.push_back(pts[i]);
    }

    sort(strip.begin(), strip.end(),
         [](auto &a, auto &b) { return a.second < b.second; });

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && 
             (strip[j].second - strip[i].second) < d; j++) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }

    return d;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end()); // sort by x

    cout << fixed << setprecision(6)
         << closestUtil(arr, 0, n - 1) << endl;

    return 0;
}
