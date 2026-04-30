/*
Basic Question: Find the set of lines visible from y = +infinity.
Topic: Convex Hull Trick
Idea Used: Sort by slope, remove duplicate slopes, and build the upper envelope using intersection points.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Line {
    long long m, c;
};

double intersectX(Line a, Line b) {
    return (double)(b.c - a.c) / (a.m - b.m);
}

vector<Line> visibleLines(vector<Line>& lines) {
    sort(lines.begin(), lines.end(), [](Line a, Line b) {
        return a.m < b.m;
    });

    vector<Line> hull;

    for (auto &line : lines) {
        while (hull.size() >= 2) {
            Line l1 = hull[hull.size() - 2];
            Line l2 = hull[hull.size() - 1];

            if (intersectX(l1, l2) >= intersectX(l2, line))
                hull.pop_back();
            else break;
        }
        hull.push_back(line);
    }

    return hull;
}

int main() {
    vector<Line> lines = {{1,1}, {2,3}, {3,2}};
    auto res = visibleLines(lines);

    for (auto &l : res)
        cout << "y = " << l.m << "x + " << l.c << endl;
}