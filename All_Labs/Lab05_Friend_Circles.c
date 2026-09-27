// Objective: To analyze the structural properties of a connected graph using spanning trees, branches, chords, rank, and nullity.
// Problem 1: In a social network of N people, some of them are directly connected as friends. If person A is a friend of person B, and person B is a friend of person C, then A, B, and C are all part of the same friend circle (a connected component in graph terms). You are given an undirected graph represented by an adjacency matrix of size N x N, where matrix[i][j] = 1 indicates a direct friendship between person i and person j.
// Your task is to determine the total number of friend circles.
// Input:
// 4 // total N people
// 1 1 0 0 // adj. Matrix
// 1 1 0 0
// 0 0 1 1
// 0 0 1 1
// Output:
// 2
#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int queue[MAX];
int visited[MAX];


void bfs(int V, int start)
{
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int u = queue[front++];

        for (int v = 0; v < V; v++)
        {
            if (adj[u][v] == 1 && !visited[v])
            {
                visited[v] = 1;
                queue[rear++] = v;
            }
        }
    }
}

void main()
{
    int V;

    printf("Enter number of peoples: ");
    scanf("%d", &V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }

    for(int i=0;i<V;i++){
        visited[i]=0;
    }

    int cnt=0;

    for(int i=0;i<V;i++){
        if(visited[i]==0){
            bfs(V,i);
            cnt++;
        }
    }
    printf("Total number of Circles : %d",cnt);
}

