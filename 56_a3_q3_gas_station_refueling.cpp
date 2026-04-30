/*
Basic Question: Determine a refueling strategy that minimizes total refueling time on a route with gas stations.
Topic: Greedy Strategy
Idea Used: Since refueling time is proportional to fuel added, always drive to the farthest reachable next station or the destination and add only the fuel needed.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double C, F;
    cin >> n >> C >> F;

    vector<double> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    double fuel = C;
    int stops = 0;

    for (int i = 0; i < n - 1; i++) {
        double dist = x[i+1] - x[i];
        double needed = dist * F;

        if (fuel < needed) {
            stops++;
            fuel = C;
        }
        fuel -= needed;
    }

    cout << stops << endl;
}