#include <stdio.h>
#include <stdlib.h>

void main()
{
    int v, e;

    printf("Enter no. of vertices");
    scanf("%d", &v);

    printf("Enter no. of edges");
    scanf("%d", &e);

    int add[v][v];

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            add[i][j] = 0;
        }
    }
    int n1, n2;

    for (int i = 0; i < e; i++)
    {
        printf("Enter Edges");
        scanf("%d %d", &n1, &n2);
        add[n1][n2] = 1;
        add[n2][n1] = 1;
    }

    for (int i = 0; i < v; i++)
    {
        int cnt = 0;
        for (int j = 0; j < v; j++)
        {
            if (add[i][j] == 1)
            {
                cnt++;
            }
        }
        printf("%d has %d degree",i,cnt);
        printf("\n");
    }
}