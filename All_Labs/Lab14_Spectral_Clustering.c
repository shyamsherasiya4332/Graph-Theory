// Objective: To perform spectral clustering on a graph using the Laplacian matrix and eigenvectors.
// Problem: Write a program to perform spectral clustering on an undirected graph by using the graph Laplacian matrix.
// The program should:
// 1. Construct the adjacency matrix of the graph.
// 2. Compute the degree matrix.
// 3. Construct the Laplacian matrix.
// 4. Compute eigenvalues and eigenvectors of the Laplacian matrix.
// 5. Partition the graph into clusters using spectral properties.
// Input:
// N = 6
// Edges = {(0,1),(0,2),(1,2),(3,4),(4,5),(3,5)}
// Output:
// Cluster 1: {0,1,2}
// Cluster 2: {3,4,5}
#include <stdio.h>
#include <math.h>

#define N 6

void multiply(double A[N][N], double x[N], double y[N])
{
    for (int i = 0; i < N; i++)
    {
        y[i] = 0;
        for (int j = 0; j < N; j++)
            y[i] += A[i][j] * x[j];
    }
}

void normalize(double x[N])
{
    double norm = 0;

    for (int i = 0; i < N; i++)
        norm += x[i] * x[i];

    norm = sqrt(norm);

    for (int i = 0; i < N; i++)
        x[i] /= norm;
}

int main()
{
    int adjacency[N][N] = {0};
    int degree[N][N] = {0};
    double L[N][N] = {0};

    int edges[6][2] = {
        {0,1}, {0,2}, {1,2},
        {3,4}, {4,5}, {3,5}
    };

    for (int i = 0; i < 6; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjacency[u][v] = 1;
        adjacency[v][u] = 1;
    }

    for (int i = 0; i < N; i++)
    {
        int d = 0;

        for (int j = 0; j < N; j++)
            d += adjacency[i][j];

        degree[i][i] = d;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            L[i][j] = degree[i][j] - adjacency[i][j];
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", adjacency[i][j]);
        printf("\n");
    }

    printf("\nDegree Matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", degree[i][j]);
        printf("\n");
    }

    printf("\nLaplacian Matrix:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%.0f ", L[i][j]);
        printf("\n");
    }

    double x[N] = {1, -1, 1, -1, 1, -1};
    double y[N];

    for (int iter = 0; iter < 20; iter++)
    {
        multiply(L, x, y);

        double mean = 0;

        for (int i = 0; i < N; i++)
            mean += y[i];

        mean /= N;

        for (int i = 0; i < N; i++)
            x[i] = y[i] - mean;

        normalize(x);
    }

    printf("\nFiedler Vector:\n");
    for (int i = 0; i < N; i++)
        printf("Vertex %d : %.3f\n", i, x[i]);

    printf("\nCluster 1: { ");
    for (int i = 0; i < N; i++)
        if (x[i] >= 0)
            printf("%d ", i);

    printf("}\nCluster 2: { ");

    for (int i = 0; i < N; i++)
        if (x[i] < 0)
            printf("%d ", i);

    printf("}\n");

    return 0;
}