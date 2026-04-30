/*
Basic Question: Check whether an integer a can be written as b^k for integers b and k > 1.
Topic: Number Theory / Binary Search
Idea Used: Try every exponent from 2 to log2(a) and binary search the integer base using fast exponentiation with overflow guards.
*/
#include <bits/stdc++.h>
using namespace std;

// Compute base^exp with limit check
long long power(long long base, int exp, long long limit) {
    long long result = 1;

    for (int i = 0; i < exp; i++) {
        if (result > limit / base)
            return limit + 1;
        result *= base;
    }
    return result;
}

int main() {
    long long a;
    cin >> a;

    if (a <= 1) {
        cout << "Yes\n" << a << " 2\n";
        return 0;
    }

    int maxK = log2(a);

    for (int k = 2; k <= maxK; k++) {
        long long low = 2, high = a;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long val = power(mid, k, a);

            if (val == a) {
                cout << "Yes\n" << mid << " " << k << "\n";
                return 0;
            }
            else if (val < a)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    cout << "No\n";
}