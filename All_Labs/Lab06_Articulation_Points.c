// Objective: To identify articulation points in an undirected graph and determine connectivity and separability of a graph.
// Problem: Write a program to find all cut-vertices of a graph.
// Input: Connected graph with vertices and edges.
// Output:
// List of articulation points.
#include <stdio.h>
#include <stdbool.h>

#define MAX 100
int graph[MAX][MAX];
int visited[MAX], disc[MAX], low[MAX], parent[MAX];
bool ap[MAX];
int V, E;
int time = 0;

void DFS(int u)
{
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++time;

    for (int v = 0; v < V; v++)
    {
        if (graph[u][v])
        {
            if (!visited[v])
            {
                children++;
                parent[v] = u;
                DFS(v);

                if (low[v] < low[u])
                    low[u] = low[v];

                if (parent[u] == -1 && children > 1)
                    ap[u] = true;

                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = true;
                else if (v != parent[u])
                {
                    if (disc[v] < low[u])
                        low[u] = disc[v];
                }
            }
        }
    }
}
int main()
{
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        parent[i] = -1;
        ap[i] = false;

        for (int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    printf("Enter edges (u v):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            DFS(i);
    }

    printf("\nArticulation Vertices :\n");

    int found = 0;
    for (int i = 0; i < V; i++)
    {
        if (ap[i])
        {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("No Articulation Vertices");

    printf("\n");

    return 0;
}