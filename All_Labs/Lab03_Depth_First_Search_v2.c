// Objective: To implement Depth First Search traversal for a graph.
// Problem: Write a program to perform DFS traversal starting from a given source vertex.
// Input: adj[][] = [[1,2], [0,2], [0,1,3,4], [2], [2]]
// Output:
// [0, 1, 2, 3, 4]
#include <stdio.h>

int adj[5][5] = {
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,1},
    {0,1,0,0,1},
    {0,0,1,1,0}
};

int visited[5] = {0};

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for(int i = 0; i < 5; i++) {
        if(adj[v][i] && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    DFS(0);
    return 0;
}