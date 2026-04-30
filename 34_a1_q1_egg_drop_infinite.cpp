/*
Basic Question: Find the highest safe floor h in an infinite building using O(log h) egg droppings.
Topic: Binary Search / Exponential Search
Idea Used: First double the floor number until the egg breaks to get a bounded range, then binary search inside that range.
*/
#include <bits/stdc++.h>
using namespace std;

static bool breaksAt(long long floorNumber, long long highestSafeFloor) {
    return floorNumber > highestSafeFloor;
}

int main() {
    long long h;
    cin >> h;

    if (h < 0) {
        cout << "Highest safe floor must be non-negative.\n";
        return 0;
    }

    long long drops = 0;
    long long low = 0, high = 1;

    while (!breaksAt(high, h)) {
        drops++;
        low = high;
        high *= 2;
    }
    drops++;

    while (low + 1 < high) {
        long long mid = low + (high - low) / 2;
        drops++;
        if (breaksAt(mid, h)) high = mid;
        else low = mid;
    }

    cout << "Highest safe floor: " << low << "\n";
    cout << "Egg droppings used: " << drops << "\n";
    return 0;
}
