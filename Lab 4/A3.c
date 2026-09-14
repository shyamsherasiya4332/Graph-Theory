#include <stdio.h>

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

    printf("\nDistance Matrix:\n   ");

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
}