/*
Basic Question: Schedule unit-time jobs with release times and deadlines, and minimize the number of length-L machine-on intervals.
Topic: Greedy Scheduling
Idea Used: Use earliest-deadline-first for the warm-up feasibility check, and a latest-slot greedy activation strategy for the minimum-interval problem.
*/
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int r, d;
};

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);
    int maxT = 0;

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].r >> jobs[i].d;
        maxT = max(maxT, jobs[i].d);
    }

    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b) {
        return a.d < b.d;
    });

    set<int> slots;
    for (int i = 0; i <= maxT; i++) slots.insert(i);

    for (auto &job : jobs) {
        auto it = slots.lower_bound(job.r);
        if (it == slots.end() || *it > job.d) {
            cout << "Not feasible\n";
            return 0;
        }
        slots.erase(it);
    }

    cout << "Feasible\n";
}