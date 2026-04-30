/*
Basic Question: Find the maximum height obtainable by stacking rotatable boxes when multiple copies are allowed.
Topic: Dynamic Programming
Idea Used: Generate all box rotations, sort them by base area, and run LIS-style DP on valid base-to-top transitions.
*/
#include <bits/stdc++.h>
using namespace std;

struct Box {
    int h, w, d;
};

bool cmp(Box a, Box b) {
    return a.w * a.d > b.w * b.d;
}

int main() {
    int n;
    cin >> n;

    vector<Box> boxes;

    for (int i = 0; i < n; i++) {
        int h, w, d;
        cin >> h >> w >> d;

        boxes.push_back({h, max(w,d), min(w,d)});
        boxes.push_back({w, max(h,d), min(h,d)});
        boxes.push_back({d, max(h,w), min(h,w)});
    }

    sort(boxes.begin(), boxes.end(), cmp);

    int m = boxes.size();
    vector<int> dp(m);

    for (int i = 0; i < m; i++)
        dp[i] = boxes[i].h;

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < i; j++) {
            if (boxes[i].w < boxes[j].w && boxes[i].d < boxes[j].d) {
                dp[i] = max(dp[i], dp[j] + boxes[i].h);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}