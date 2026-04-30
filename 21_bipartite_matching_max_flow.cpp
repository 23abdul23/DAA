/*
Basic Question: Find the maximum number of worker-job assignments possible in a bipartite graph.
Topic: Maximum Bipartite Matching
Idea Used: Model workers and jobs as a flow network and run Edmonds-Karp to compute the maximum matching.
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n; // total nodes
vector<vector<int>> capacity;
vector<vector<int>> adj;

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
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main() {
    int workers, jobs;
    cin >> workers >> jobs;

    int E;
    cin >> E;

    // Node mapping:
    // 0 = source
    // 1..workers = workers
    // workers+1 .. workers+jobs = jobs
    // last node = sink
    int s = 0;
    int t = workers + jobs + 1;

    n = t + 1;

    capacity.assign(n, vector<int>(n, 0));
    adj.assign(n, vector<int>());

    // source -> workers
    for (int i = 1; i <= workers; i++) {
        adj[s].push_back(i);
        adj[i].push_back(s);
        capacity[s][i] = 1;
    }

    // worker -> job edges
    for (int i = 0; i < E; i++) {
        int w, j;
        cin >> w >> j;

        int jobNode = workers + j;

        adj[w].push_back(jobNode);
        adj[jobNode].push_back(w);
        capacity[w][jobNode] = 1;
    }

    // jobs -> sink
    for (int j = 1; j <= jobs; j++) {
        int jobNode = workers + j;

        adj[jobNode].push_back(t);
        adj[t].push_back(jobNode);
        capacity[jobNode][t] = 1;
    }

    cout << maxflow(s, t) << endl;
}
