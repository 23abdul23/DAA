/*
Basic Question: Compute single-source shortest paths in a non-negative weighted graph using Dijkstra's algorithm.
Topic: Single Source Shortest Path
Idea Used: Use an adjacency list and a min-priority queue to repeatedly relax the closest unprocessed vertex.
*/
#include <bits/stdc++.h>
#include <stdio.h>

//TC : O(V + E logV)
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

		if (wt < 0) {
		    cout << "  Negative weights not allowed for Dijkstra." << endl;
		    continue;
		}
		adj[i].push_back({v, wt});
	    }
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	
	vector<int> dist(n, INT_MAX);

	cout << endl << "Source Vertex: ";
	int s;
	cin >> s;

	if (s < 0 || s >= n){
		cout << "Source Vertex should be between 0 and n\n";
		return 0;
	}

	dist[s] = 0;
	pq.push({0,s});

	while (!pq.empty()){
		pair<int,int> x = pq.top();

		pq.pop();

		int d = x.first, u = x.second;

		if (d > dist[u])continue;

		for (auto y: adj[u]){
		
			int v = y.first;
			int wt = y.second;

			if (d + wt < dist[v]){
				pq.push({d+wt, v});
				dist[v] = d+wt;
			}
		
		}
	
	}

	for (int i = 0; i < n; i++){
		cout << i << " : " << dist[i]<< endl;
	}

	return 0;

}
