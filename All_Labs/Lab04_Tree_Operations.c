// Objective: To understand the basic properties and structure of trees using graph operations.
// Problem 1: Write a program to perform the following operations on a tree:
// 1. Identify all pendent (leaf) vertices.
// 2. Find the degree of each vertex.
// 3. Find distance between vertices.
// 4. Find eccentricity of each vertex
// 5. Find the center of the tree.
// 6. Verify whether the given graph is a tree or not.
// Input: V = 6, edges [][] = {(0,1), (1,2), (1,3), (3,4), (3,5)}
// Output: 
// 1. List of pendent vertices
// 2. Degree of each vertex 
// 3. Distance matrix
// 4. Eccentricity of each vertex
// 5. Center of the tree 
// 6. Confirmation whether the graph is a tree

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX];
int dist[MAX];
int queue[MAX];
int visited[MAX];

void bfs(int V, int start)
{
    int front = 0, rear = 0;

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        dist[i] = -1;
    }

    visited[start] = 1;
    dist[start] = 0;
    queue[rear++] = start;

    while (front < rear)
    {
        int u = queue[front++];

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] == 1 && !visited[v])
            {
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }
        }
    }
}

void dfs(int v, int V) {
    visited[v] = 1;
    for(int i = 0; i < V; i++) {
        if(adj[v][i] == 1 && !visited[i]) {
            dfs(i, V);
        }
    }
}

void main()
{
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // --- 1. Identify all pendent (leaf) vertices ---
    printf("\n--- 1. Pendent Vertices ---\n");
    for (int i = 0; i < V; i++){
        int cnt = 0;
        for (int j = 0; j < V; j++){
            if(adj[i][j] == 1) cnt++;
        }
        if(cnt == 1){
            printf("%d is Pendent Vertex\n", i);
        }
    }

    // --- 2. Find the degree of each vertex ---
    printf("\n--- 2. Degree of Each Vertex ---\n");
    for (int i = 0; i < V; i++){
        int cnt = 0;
        for (int j = 0; j < V; j++){
            if(adj[i][j] == 1) cnt++;
        }
        printf("Vertex %d has %d degree\n", i, cnt);
    }

    // --- 3. Find distance between vertices ---
    printf("\n--- 3. Distance Matrix ---\n   ");
    for (int i = 0; i < V; i++)
        printf("%d ", i);
    printf("\n");
    for (int i = 0; i < V; i++)
    {
        bfs(V, i);
        printf("%d: ", i);
        for (int j = 0; j < V; j++)
            printf("%d ", dist[j]);
        printf("\n");
    }

    // --- 4. Find eccentricity of each vertex ---
    printf("\n--- 4. Eccentricity of Each Vertex ---\n");
    int ecc[MAX];
    for (int i = 0; i < V; i++)
    {
        bfs(V, i);
        int maxDist = 0;
        for (int j = 0; j < V; j++)
        {
            if (dist[j] > maxDist)
                maxDist = dist[j];
        }
        ecc[i] = maxDist;
        printf("Vertex %d = %d\n", i, maxDist);
    }

    // --- 5. Find the center of the tree ---
    printf("\n--- 5. Center of the Tree ---\n");
    int minEcc = 9999;
    for (int i = 0; i < V; i++) {
        if(ecc[i] < minEcc) minEcc = ecc[i];
    }
    for (int i = 0; i < V; i++) {
        if(ecc[i] == minEcc) {
            printf("Vertex %d is center\n", i);
        }
    }

    // --- 6. Verify whether the given graph is a tree or not ---
    printf("\n--- 6. Verify Graph is a Tree ---\n");
    for(int i = 0; i < V; i++) visited[i] = 0;
    
    int connected = 1;
    if(V > 0) {
        dfs(0, V);
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                connected = 0;
                break;
            }
        }
    }
    
    if(connected && E == V - 1) {
        printf("The graph is a tree.\n");
    } else {
        printf("The graph is NOT a tree.\n");
    }
}
