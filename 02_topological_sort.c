/*
Basic Question: Produce a topological ordering of a directed acyclic graph.
Topic: Topological Sort
Idea Used: Use Kahn's algorithm with indegree counts and a queue of currently zero-indegree vertices.
*/
#include <stdio.h>

int main() {
    int n, m, i, u, v;
    scanf("%d %d", &n, &m);

    int adj[n][n], indegree[n], queue[n], front = 0, rear = 0;

    for(i = 0; i < n; i++) {
        indegree[i] = 0;
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for(i = 0; i < n; i++)
        if(indegree[i] == 0)
            queue[rear++] = i;

    while(front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for(i = 0; i < n; i++) {
            if(adj[node][i]) {
                indegree[i]--;
                if(indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    return 0;
}
