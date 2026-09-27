// Problem 2: Write a program to perform the following basic graph-related operations: 
// 1. Represent a graph using adjacency matrix. 
// 2. Represent a graph using adjacency list. 
// 3. Find the degree of each vertex in the graph. 
// 4. Determine whether the graph is simple, complete, or connected. 
// 5. Display total number of vertices and edges. 
// Input: V = 5, edges [][] = {(0, 1), (0,2), (1,2), (2,3), (3,4)} 
// Output: 
// 1. Adjacency Matrix 
// 2. Adjacency List 
// 3. Degree of each vertex 
// 4. Graph properties  
// 5. Total vertices and edges 
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
            add[i][j]=0;
        }
    }
    int n1,n2;

    for (int i = 0; i < e; i++)
    {
        printf("Enter Edges");
        scanf("%d %d",&n1,&n2);
        add[n1][n2]=1;
        add[n2][n1]=1;
    }

    for (int i = 0; i < v; i++){
        printf("%d -> ", i);
        for (int j = 0; j < v; j++)
        {
            if(add[i][j]==1){
                printf("%d ",j);
            }
        }
        printf("\n");
    }
    printf("Adjacency Matrix \n");
    for (int i = 0; i < v; i++){
        for (int j = 0; j < v; j++)
        {
            printf("%d ",add[i][j]);
        }
        printf("\n");
    }
}

//0 1 0 0
//1 0 1 1
//0 1 0 1
//0 1 1 0