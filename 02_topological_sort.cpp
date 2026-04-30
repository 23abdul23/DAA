#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(m, 0));
    
    vector<int> indegree;
    queue<int> q;

    for (int i = 0; i < m; i++){
        int u , v;
        cin >> u >> v;
        adj[u][v] = 1;
        indegree[v]++;
    }

    for (int i = 0 ; i < n; i++){
        if (!indegree[i])
            q.push(i);
    }

    while (!q.empty()){
        int node = q.front();
        q.pop();

        cout << node << " ";
        for (int i = 0; i < n; i++){
            if (adj[node][i]){
                indegree[i]--;


                if (indegree[i] == 0)
                    q.push(i);
            }
        }

    }
    

    return 0;
}