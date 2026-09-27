// Objective: To implement Depth First Search traversal for a graph.
// Problem: Write a program to perform DFS traversal starting from a given source vertex.
// Input: adj[][] = [[1,2], [0,2], [0,1,3,4], [2], [2]]
// Output:
// [0, 1, 2, 3, 4]
#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0,1,1,0,0},
    {1,0,1,0,0},
    {1,1,0,1,1},
    {0,0,1,0,0},
    {0,0,1,0,0}
};

int visited[V];

void DFS(int v){
    visited[v] = 1;
    printf("%d ", v);

    for(int i=0; i<V; i++){
        if(graph[v][i] && !visited[i]){
            DFS(i);
        }
    }
}

int main(){
    int source = 0;

    printf("DFS Traversal: ");
    DFS(source);

    return 0;
}