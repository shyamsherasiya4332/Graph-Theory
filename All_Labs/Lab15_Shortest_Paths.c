// Objective: To find shortest paths between all pairs of vertices.
// Problem: Write a program to implement Floyd-Warshall Algorithm.
// Input:
// Weighted graph represented using adjacency matrix.
// Output:
// Shortest path matrix between all pairs of vertices.
#include <stdio.h>

#define N 4
#define INF 99999

int main()
{
    int graph[N][N] = {
        {0, 5, INF, 10},
        {INF, 0, 3, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    int dist[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    printf("Shortest Path Matrix:\n\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}