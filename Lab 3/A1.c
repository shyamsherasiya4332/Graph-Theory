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