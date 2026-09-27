// Objective: To compute eigenvalues and eigenvectors of graph matrices.
// Problem: Write a program to calculate eigenvalues and eigenvectors of adjacency and Laplacian matrix.
// Input: Adjacency or Laplacian matrix.
// Output:
// Eigenvalues and corresponding eigenvectors.
// 13 Objective: To compute eigenvalues and eigenvectors of graph matrices. 
// Problem: Write a program to calculate eigenvalues and eigenvectors of adjacency and Laplacian matrix. 
// Input: Adjacency or Laplacian matrix. 
// Output: 
// Eigenvalues and corresponding eigenvectors.

#include <stdio.h>
#include <math.h>

#define N 3

int main()
{
    int i, j, k;
    double A[N][N] = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };

    double V[N][N] = {0};

    for (i = 0; i < N; i++)
        V[i][i] = 1;

    for (k = 0; k < 100; k++)
    {
        int p = 0, q = 1;

        for (i = 0; i < N; i++)
            for (j = i + 1; j < N; j++)
                if (fabs(A[i][j]) > fabs(A[p][q]))
                    p = i, q = j;

        if (fabs(A[p][q]) < 0.000001)
            break;

        double theta = 0.5 * atan2(2 * A[p][q],
                                    A[p][p] - A[q][q]);

        double c = cos(theta);
        double s = sin(theta);

        for (i = 0; i < N; i++)
        {
            double x = A[i][p];
            double y = A[i][q];

            A[i][p] = c * x - s * y;
            A[i][q] = s * x + c * y;
        }

        for (i = 0; i < N; i++)
        {
            double x = A[p][i];
            double y = A[q][i];

            A[p][i] = c * x - s * y;
            A[q][i] = s * x + c * y;
        }

        for (i = 0; i < N; i++)
        {
            double x = V[i][p];
            double y = V[i][q];

            V[i][p] = c * x - s * y;
            V[i][q] = s * x + c * y;
        }
    }

    printf("Eigenvalues:\n");
    for (i = 0; i < N; i++)
        printf("%.2lf ", A[i][i]);

    printf("\n\nEigenvectors:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            printf("%.2lf ", V[i][j]);
        printf("\n");
    }

    return 0;
}