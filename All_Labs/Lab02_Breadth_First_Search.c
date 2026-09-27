// Objective: To implement Breadth First Search traversal for a graph.
// Problem: Perform a Breadth First Search (BFS) traversal starting from vertex 0.
// Input: adj[][] = [[1,2], [0,2,3], [0,1,4], [1,4], [2,3]]
// Output:
// [0, 1, 2, 3, 4]
#include<stdio.h>
void main(){

    int adj[5][5]={
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    int visited[5]={0};
    int queue[5];
    int f=0,r=0;

    visited[0]=1;
    queue[r++]=0;

    while(f<r){
        int v=queue[f++];

        printf("%d ",v);

        for(int i=0;i<5;i++){
            if(adj[v][i] && !visited[i]){
                visited[i]=1;
                queue[r++]=i;
            }
        }
    }
}