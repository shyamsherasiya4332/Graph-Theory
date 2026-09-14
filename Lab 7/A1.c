#include<stdio.h>
#define V 6
#define chord 3

void DFS(int graph[V][V], int visited[],int v){

    visited[v]=1;
    int i=0;
    for(int i=0;i<V;i++){
        if(graph[v][i] && !visited[i]){
            DFS(graph, visited, i);
        }
    }
}

int isConnected(int graph[V][V]){
    int visited[V] = {0};
    int i=0;

    DFS(graph, visited,0);

    for(int i=0;i<V;i++){
        if(!visited[i])
            return 0;
    }
    return 1;
}

int vertexConnectivity(int graph[V][V])
{
    int temp[V][V];

    for(int remove = 0; remove < V; remove++)
    {
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                temp[i][j]=graph[i][j];

        for(int i=0;i<V;i++)
        {
            temp[remove][i]=0;
            temp[i][remove]=0;
        }

        int visited[V]={0};

        int start=0;
        while(start<V && start==remove)
            start++;

        DFS(temp,visited,start);

        for(int i=0;i<V;i++)
        {
            if(i!=remove && !visited[i])
                return 1;
        }
    }

    return 2;
}

int edgeConnectivity(int graph[V][V])
{
    int temp[V][V];

    for(int i=0;i<V;i++)
    {
        for(int j=i+1;j<V;j++)
        {
            if(graph[i][j])
            {
                for(int x=0;x<V;x++)
                    for(int y=0;y<V;y++)
                        temp[x][y]=graph[x][y];

                temp[i][j]=0;
                temp[j][i]=0;

                if(!isConnected(temp))
                    return 1;
            }
        }
    }

    return 2;
}

int main()
{
    int graph[V][V]={
        {0,1,1,0,0,0},
        {1,0,1,1,0,0},
        {1,1,0,1,1,0},
        {0,1,1,0,1,1},
        {0,0,1,1,0,1},
        {0,0,0,1,1,0}
    };

    if(isConnected(graph))
        printf("Graph is Connected\n");
    else
        printf("Graph is Not Connected\n");

    printf("Vertex Connectivity = %d\n",vertexConnectivity(graph));
    printf("Edge Connectivity = %d\n",edgeConnectivity(graph));

    if(vertexConnectivity(graph)==1)
        printf("Graph is Separable\n");
    else
        printf("Graph is Non-Separable\n");

    return 0;
}