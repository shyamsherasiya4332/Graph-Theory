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

