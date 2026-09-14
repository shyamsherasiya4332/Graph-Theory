#include <stdio.h>

#define E 5
#define V 6

int edges[][2] = {
    {0, 3},
    {0, 4},
    {1, 4},
    {1, 5},
    {2, 5}
};

int combinations[32][5] = {
    {-1,-1,-1,-1,-1},

    {0,-1,-1,-1,-1},
    {1,-1,-1,-1,-1},
    {2,-1,-1,-1,-1},
    {3,-1,-1,-1,-1},
    {4,-1,-1,-1,-1},

    {0,1,-1,-1,-1},
    {0,2,-1,-1,-1},
    {0,3,-1,-1,-1},
    {0,4,-1,-1,-1},
    {1,2,-1,-1,-1},
    {1,3,-1,-1,-1},
    {1,4,-1,-1,-1},
    {2,3,-1,-1,-1},
    {2,4,-1,-1,-1},
    {3,4,-1,-1,-1},

    {0,1,2,-1,-1},
    {0,1,3,-1,-1},
    {0,1,4,-1,-1},
    {0,2,3,-1,-1},
    {0,2,4,-1,-1},
    {0,3,4,-1,-1},
    {1,2,3,-1,-1},
    {1,2,4,-1,-1},
    {1,3,4,-1,-1},
    {2,3,4,-1,-1},

    {0,1,2,3,-1},
    {0,1,2,4,-1},
    {0,1,3,4,-1},
    {0,2,3,4,-1},
    {1,2,3,4,-1},

    {0,1,2,3,4}
};

int arr[32];
int p = 0;


void printMatching(int index)
{
    int j;

    printf("{ ");

    for(j = 0; j < E; j++)
    {
        if(combinations[index][j] != -1)
        {
            printf("%d ", combinations[index][j]);
        }
    }

    printf("}");
}


void findMatching()
{
    int i, j, k;
    int x, start, end;
    int flag;
    int freq[V];

    printf("\n================ ALL MATCHINGS ================\n");

    p = 0;

    for(i = 0; i < 32; i++)
    {
        for(k = 0; k < V; k++)
        {
            freq[k] = 0;
        }

        flag = 1;

        for(j = 0; j < E; j++)
        {
            x = combinations[i][j];

            if(x == -1)
                continue;

            start = edges[x][0];
            end = edges[x][1];

            if(freq[start] == 1 || freq[end] == 1)
            {
                flag = 0;
                break;
            }

            freq[start] = 1;
            freq[end] = 1;
        }

        if(flag == 1)
        {
            arr[p] = i;
            p++;

            printMatching(i);
            printf("\n");
        }
    }

    printf("\nTotal Matchings = %d\n", p);
}


void findMaximalMatching()
{
    int i, j, e;
    int index;
    int edgeIndex;
    int start, end;
    int freq[V];
    int maximal;

    printf("\n================ MAXIMAL MATCHINGS ================\n");

    for(i = 0; i < p; i++)
    {
        index = arr[i];

        for(j = 0; j < V; j++)
        {
            freq[j] = 0;
        }

        for(j = 0; j < E; j++)
        {
            edgeIndex = combinations[index][j];

            if(edgeIndex == -1)
                continue;

            start = edges[edgeIndex][0];
            end = edges[edgeIndex][1];

            freq[start] = 1;
            freq[end] = 1;
        }

        maximal = 1;

        for(e = 0; e < E; e++)
        {
            int alreadyPresent = 0;

            for(j = 0; j < E; j++)
            {
                if(combinations[index][j] == e)
                {
                    alreadyPresent = 1;
                    break;
                }
            }

            if(alreadyPresent)
                continue;

            start = edges[e][0];
            end = edges[e][1];

            if(freq[start] == 0 && freq[end] == 0)
            {
                maximal = 0;
                break;
            }
        }

        if(maximal == 1)
        {
            printMatching(index);
            printf("\n");
        }
    }
}

void findMaximumMatching()
{
    int i, j;
    int index;
    int size;
    int maxSize = 0;

    printf("\n================ MAXIMUM MATCHING ================\n");

    for(i = 0; i < p; i++)
    {
        index = arr[i];

        size = 0;

        for(j = 0; j < E; j++)
        {
            if(combinations[index][j] != -1)
            {
                size++;
            }
        }

        if(size > maxSize)
        {
            maxSize = size;
        }
    }

    for(i = 0; i < p; i++)
    {
        index = arr[i];

        size = 0;

        for(j = 0; j < E; j++)
        {
            if(combinations[index][j] != -1)
            {
                size++;
            }
        }

        if(size == maxSize)
        {
            printMatching(index);
            printf("\n");
        }
    }

    printf("\nMaximum Matching Size = %d\n", maxSize);
}


int main()
{
    findMatching();

    findMaximalMatching();

    findMaximumMatching();

    return 0;
}