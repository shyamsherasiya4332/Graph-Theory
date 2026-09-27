// Objective: To determine the total dominating set and total domination number of a graph.
// Problem: Write a program to:
// 1. Find total dominating sets
// 2. Find total domination number
// Input: N = 4, M = 4, Edges = {(1,2), (1,3), (3,4), (2,4)}
// Output:
// Total Dominating Sets: {1,3} {2,4}
// Total Domination Number = 2
#include <stdio.h>

#define N 4

int graph[N][N] = {
    {0,1,1,0},
    {1,0,0,1},
    {1,0,0,1},
    {0,1,1,0}
};

int countBits(int mask){
    int c=0;
    while(mask){
        c += mask & 1;
        mask >>=1;
    }
    return c;
}

int isTotalDominating(int mask){
    for(int v=0; v<N; v++){
        int covered=0;
        for(int u=0; u<N; u++){
            if((mask&(1<<u)) && graph[u][v]){
                covered=1;
                break;
            }
        }
        if(!covered) return 0;
    }
    return 1;
}

void printSet(int mask){
    printf("{");
    int first=1;
    for(int i=0;i<N;i++){
        if(mask&(1<<i)){
            if(!first) printf(",");
            printf("%d",i+1);
            first=0;
        }
    }
    printf("}");
}

int main(){
    int min=N+1;

    printf("Total Dominating Sets:\n");

    for(int mask=1; mask<(1<<N); mask++){
        if(isTotalDominating(mask)){
            printSet(mask);
            printf("\n");

            int size=countBits(mask);
            if(size<min)
                min=size;
        }
    }

    printf("\nTotal Domination Number = %d\n",min);

    return 0;
}