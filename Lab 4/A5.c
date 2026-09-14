#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];
int queue[MAX];

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
            if (adj[u][v] == 1 && visited[v] == 0)
            {
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }
        }
    }
}

void main()
{
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    printf("\nCenter :\n");

    for (int i = 0; i < V; i++)
    {
        bfs(V, i);

        int minDist = 0;

        for (int j = 0; j < V; j++)
        {
            if (dist[j] < minDist)
                minDist = dist[j];
        }

        printf("Vertex %d = %d\n", i, minDist);
    }
}