/*
Basic Question: Find a hidden treasure on the number line while keeping total distance traveled O(|N|).
Topic: Exponential Search
Idea Used: Visit positions 1, -2, 4, -8, ... so the search range doubles each time and stops as soon as the path crosses the treasure.
*/
#include <bits/stdc++.h>
using namespace std;

static bool crosses(long long left, long long right, long long target) {
    return min(left, right) <= target && target <= max(left, right);
}

int main() {
    long long target;
    cin >> target;

    if (target == 0) {
        cout << "Treasure found at 0\n";
        cout << "Total distance travelled: 0\n";
        return 0;
    }

    long long current = 0;
    long long step = 1;
    long long distance = 0;
    vector<long long> path = {0};

    while (true) {
        long long next = (step & 1LL) ? step : -step;
        distance += llabs(next - current);
        path.push_back(next);
        if (crosses(current, next, target)) {
            distance -= llabs(next - target);
            path.back() = target;
            break;
        }
        current = next;
        step *= 2;
    }

    cout << "Path taken:";
    for (long long x : path) cout << " " << x;
    cout << "\n";
    cout << "Total distance travelled: " << distance << "\n";
    return 0;
}
