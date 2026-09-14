#include<stdio.h>
void main(){

    int adj[5][5]={
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    int visited[5]={0};
    int queue[5];
    int f=0,r=0;

    visited[0]=1;
    queue[r++]=0;

    while(f<r){
        int v=queue[f++];

        printf("%d ",v);

        for(int i=0;i<5;i++){
            if(adj[v][i] && !visited[i]){
                visited[i]=1;
                queue[r++]=i;
            }
        }
    }
}