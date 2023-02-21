#include <stdio.h>
#include <stdlib.h>
int source, V, E, time, visited[20], G[20][20];
void DFS(int i)
{
    int j;
    visited[i] = 1;
    printf(" %d->", i + 1);
    for (j = 0; j < V; j++)
    {
        if (G[i][j] == 1 && visited[j] == 0)
            DFS(j);
    }
}
int main()
{
    int i, j, v1, v2;
    printf("\t\t\tGraphs\n");
    E = 11;
    V = 10;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            G[i][j] = 0;
    }
    G[0][1] = 1;
    G[0][2] = 1;
    G[3][5] = 1;
    G[1][7] = 1;
    G[4][5] = 1;
    G[2][6] = 1;
    G[2][7] = 1;
    G[4][8] = 1;
    G[4][9] = 1;
    G[7][8] = 1;
    G[6][9] = 1;

    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
            printf(" %d ", G[i][j]);
        printf("\n");
    }
    source = 1;
    DFS(source - 1);
    return 0;
}