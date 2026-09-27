// Problem 1: Given the number of vertices and edges of a graph, the task is to represent the adjacency list of a 
// directed graph. 
// Input: V=3, edges[][]={{0,1},{1,2},{2,0}}  
// Output:  
// 0 -> 1 
// 1 -> 2 
// 2 -> 0 
// Input: V=4, edges[][]={{0,1},{1,2},{1,3},{2,3},{3,0}} 
// Output:  
// 0 -> 1 
// 1 -> 2 3 
// 2 -> 3 
// 3 -> 0 

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