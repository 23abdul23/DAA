/*
Basic Question: Find the largest subset S on which a function f is one-one and onto.
Topic: Graph / Functional Graph
Idea Used: Repeatedly remove nodes with indegree zero; the remaining nodes are exactly the nodes lying on directed cycles.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> f(n + 1), indegree(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        indegree[f[i]]++;
    }

    queue<int> q;
    vector<int> removed(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        removed[u] = 1;
        int v = f[u];
        if (--indegree[v] == 0) q.push(v);
    }

    vector<int> subset;
    for (int i = 1; i <= n; i++) if (!removed[i]) subset.push_back(i);

    cout << subset.size() << "\n";
    for (int x : subset) cout << x << " ";
    cout << "\n";
    return 0;
}
