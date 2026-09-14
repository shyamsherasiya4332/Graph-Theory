#include <stdio.h>
#include <stdlib.h>

void main()
{
    int v, e;

    printf("Enter no. of vertices");
    scanf("%d", &v);

    printf("Enter no. of edges");
    scanf("%d", &e);
    int arr[e][2];

    for (int i = 0; i < e; i++)
    {
        printf("Enter endpoint of edges");
        for (int j = 0; j < 2; j++)
        {
            printf("enter edge[%d][%d]");
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < v; i++)
    {
        printf("%d -> ", i);
        for (int j = 0; j < e; j++)
        {
            if (arr[j][0] == i)
            {
                printf("%d", arr[j][1]);
            }
        }
        printf("\n");
    }
}