/*
Basic Question: Find a local minimum in a complete binary tree by probing node values.
Topic: Tree Search
Idea Used: Probe the current node and move to the smaller child if one exists; otherwise the current node is a local minimum.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> value(n + 1);
    for (int i = 1; i <= n; i++) cin >> value[i];

    int node = 1;
    while (true) {
        int left = 2 * node;
        int right = 2 * node + 1;
        int best = node;

        if (left <= n && value[left] < value[best]) best = left;
        if (right <= n && value[right] < value[best]) best = right;

        if (best == node) break;
        node = best;
    }

    cout << "Local minimum node index: " << node << "\n";
    cout << "Value: " << value[node] << "\n";
    return 0;
}
