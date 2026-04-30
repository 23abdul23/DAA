/*
Basic Question: Compute the nth Fibonacci number in O(log n) additions and multiplications.
Topic: Fast Doubling
Idea Used: Use divide and conquer identities that compute F(n) and F(n+1) together from half-size subproblems.
*/
#include <bits/stdc++.h>
using namespace std;

static pair<long long, long long> fib(long long n) {
    if (n == 0) return {0, 1};
    auto half = fib(n >> 1);
    long long a = half.first;
    long long b = half.second;
    long long c = a * (2 * b - a);
    long long d = a * a + b * b;
    if (n & 1) return {d, c + d};
    return {c, d};
}

int main() {
    long long n;
    cin >> n;
    cout << fib(n).first << "\n";
    return 0;
}
