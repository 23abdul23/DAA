/*
Basic Question: Build the Minimum Spanning Tree of a weighted graph using Kruskal's algorithm.
Topic: Minimum Spanning Tree
Idea Used: Sort edges by weight and use Disjoint Set Union to add only edges that do not form a cycle.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//TC : O(E logE)

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

//helper func to find the parent 
int findParent(int v, vector<int>& parent) {
    if (parent[v] == v) return v;
    return parent[v] = findParent(parent[v], parent);
}

void unionSet(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

int main() {
    int n;
    cin >> n;

    //main adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    vector<Edge> edges;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] != 0)
                edges.push_back({i, j, graph[i][j]});

    //sorting edghes in increasing order
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    for (auto e : edges) {
        if (findParent(e.u, parent) != findParent(e.v, parent)) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            unionSet(e.u, e.v, parent, rank);
        }
    }

    return 0;
}
