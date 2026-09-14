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

int isDominating(int mask){
    for(int v=0; v<N; v++){
        if(mask & (1<<v)) continue;

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
    int minDom=N+1, minTotal=N+1;

    printf("Possible Dominating Sets:\n");
    for(int mask=1; mask<(1<<N); mask++){
        if(isDominating(mask)){
            printSet(mask);
            printf("\n");
            int sz=countBits(mask);
            if(sz<minDom) minDom=sz;
        }
    }

    printf("\nDomination Number = %d\n\n",minDom);

    printf("Total Dominating Sets:\n");
    for(int mask=1; mask<(1<<N); mask++){
        if(isTotalDominating(mask)){
            printSet(mask);
            printf("\n");
            int sz=countBits(mask);
            if(sz<minTotal) minTotal=sz;
        }
    }

    printf("\nTotal Domination Number = %d\n",minTotal);

    return 0;
}