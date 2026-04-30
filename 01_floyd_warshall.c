/*
Basic Question: Compute shortest paths between all pairs of vertices using the Floyd-Warshall algorithm.
Topic: All-Pairs Shortest Path
Idea Used: Treat each vertex as an intermediate node in turn and relax every pairwise distance through it.
*/
#include <stdio.h>
#define INF 99999

int main() {
    int n, i, j, k;
    scanf("%d", &n);
    int dist[n][n];

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &dist[i][j]);

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }

    return 0;
}
