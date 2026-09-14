#include <stdio.h>

#define N 5

int main() {
    int adj[N][N] = {0};
    int degree[N][N] = {0};
    int laplacian[N][N];

    int edges[4][2] = {
        {1,2}, {2,3}, {4,5}, {1,5}
    };

    for(int i=0; i<N-1; i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=0; i<N; i++) {
        int deg = 0;
        for(int j=0; j<N; j++)
            deg += adj[i][j];
        degree[i][i] = deg;
    }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            laplacian[i][j] = degree[i][j] - adj[i][j];

    printf("Adjacency Matrix:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    printf("\nDegree Matrix:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            printf("%d ", degree[i][j]);
        printf("\n");
    }

    printf("\nLaplacian Matrix:\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++)
            printf("%d ", laplacian[i][j]);
        printf("\n");
    }

    return 0;
}