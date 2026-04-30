/*
Basic Question: Compute the set of 2D points that are not dominated by any other point.
Topic: Sorting / Skyline
Idea Used: Sort points by x descending and keep only points whose y-coordinate is larger than every point seen so far.
*/
#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) cin >> points[i].x >> points[i].y;

    sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
        if (a.x != b.x) return a.x > b.x;
        return a.y > b.y;
    });

    vector<Point> answer;
    long long bestY = LLONG_MIN;
    for (const auto& p : points) {
        if (p.y > bestY) {
            answer.push_back(p);
            bestY = p.y;
        }
    }

    sort(answer.begin(), answer.end(), [](const Point& a, const Point& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    cout << answer.size() << "\n";
    for (const auto& p : answer) cout << p.x << " " << p.y << "\n";
    return 0;
}
