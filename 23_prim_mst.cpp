/*
Basic Question: Build the Minimum Spanning Tree of a weighted graph using Prim's algorithm.
Topic: Minimum Spanning Tree
Idea Used: Start from one vertex and grow the MST by always taking the lightest edge to an unvisited vertex using a min-heap.
*/
#include <bits/stdc++.h>

// TC : O(E logV)
// SC : O(V+E)

using namespace std;

typedef pair<int,int> pii;


int main(){
        //mkaing adjacency list
        int v, e;
        cout << "Num of edges: ";
        cin >> e;

        cout << "\nNum of Vertices: ";
        cin >> v;

        vector<vector<pii>> adj(v);

        cout << "\nEnter edges as : u , v, wt";
        for (int i =0; i < e; i++){

                int u ,v, wt;
                cin >> u >> v >> wt;

                adj[u].push_back({wt,v});
                adj[v].push_back({wt,u});

        }

        vector<int> dist(v, INT_MAX);
        vector<bool> inMST(v, false);
        vector<int> par(v, -1);

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        //starting frm 0 vertex
        dist[0] = 0;
        pq.push({0,0});

        while (!pq.empty()){

                int u = pq.top().second;
                pq.pop();

                if (inMST[u])
                        continue;

                inMST[u] = true;

                for (auto x: adj[u]){
                        int v = x.second, wt = x.first;
                        if (!inMST[v] && wt < dist[v]){

                                par[v] = u;
                                dist[v] = wt;
                                pq.push({wt,v});
                        }
                }
        }


        int t = 0;

        for (int i = 1; i < v; i++){

                if (par[i] != -1){
                        cout << par[i] << "--"<< i << " :" << dist[i] <<endl;
                        t += dist[i];
                }

        }

        cout << t ;



        return 0;
}

