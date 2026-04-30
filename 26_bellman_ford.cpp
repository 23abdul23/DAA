/*
Basic Question: Compute single-source shortest paths in a weighted graph and detect negative cycles using Bellman-Ford.
Topic: Single Source Shortest Path
Idea Used: Relax all edges repeatedly for V-1 rounds, then do one extra pass to check for further relaxation.
*/
#include <bits/stdc++.h>
#include <stdio.h>

//TC : O(VE)
//SC : O(VE)

using namespace std;


int main(){
	int n;
	cin >> n;

	vector<vector<pair<int, int>>> adj(n);	

	for (int i = 0; i < n; i++) {
	    cout << "Node " << i << " (Enter destination -1 to move to next node):" << endl;
	    while (true) {
		int v, wt;
		cout << "  v: ";
		cin >> v;

		if (v == -1) break; 

		if (v < 0 || v >= n) {
		    cout << "  Invalid node! Must be between 0 and " << n - 1 << endl;
		    continue;
		}

		if (v == i)continue;

		cout << "  wt: ";
		cin >> wt;

		adj[i].push_back({v, wt});
	    }
	}
	
	vector<int> dist(n, INT_MAX);

	int s;
	cout << "Source Vertex: ";
	cin >> s;
	cout << endl;
	dist[s] = 0;

	for (int i = 1; i <= n - 1; i++) {
		for (int u = 0; u < n; u++) {
		    for (auto edge : adj[u]) {
				int v = edge.first;
				int wt = edge.second;
				if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
						dist[v] = dist[u] + wt;
					}
				}
		}
	}

	// One more pass: if any distance still decreases, there's a negative cycle
	for (int u = 0; u < n; u++) {
		for (auto edge : adj[u]) {
		    	int v = edge.first;
		    	int wt = edge.second;
		   	if (dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
				cout << "Graph contains a negative weight cycle!" << endl;
				return 0;
			}
		}
	}

	cout << "\nVertex : Distance from Source" << endl;
	for (int i = 0; i < n; i++) {
		if (dist[i] == INT_MAX) cout << i << " : INF" << endl;
		else cout << i << " : " << dist[i] << endl;
	}
	return 0;

}
