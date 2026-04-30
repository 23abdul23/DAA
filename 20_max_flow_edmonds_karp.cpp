/*
Basic Question: Find the maximum flow from a source station to a sink station in a capacity network.
Topic: Maximum Flow
Idea Used: Use the Edmonds-Karp variant of Ford-Fulkerson with BFS to find shortest augmenting paths in the residual graph.
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<int>> capacity;
vector<vector<int>> adj;

// BFS to find augmenting path
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;

    queue<pair<int,int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next] > 0) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);

                if (next == t)
                    return new_flow;

                q.push({next, new_flow});
            }
        }
    }
    return 0;
}

// Edmonds-Karp max flow
int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);

    int new_flow;
    while ((new_flow = bfs(s, t, parent))) {
        flow += new_flow;

        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow; // residual edge
            cur = prev;
        }
    }
    return flow;
}

int main() {
    cin >> n >> m;

    int s, t;
    cin >> s >> t;

    capacity.assign(n, vector<int>(n, 0));
    adj.assign(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        adj[u].push_back(v);
        adj[v].push_back(u); // reverse edge for residual graph
        capacity[u][v] += c;
    }

    cout << maxflow(s, t) << endl;
}
