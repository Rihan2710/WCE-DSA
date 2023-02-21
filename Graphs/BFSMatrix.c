#include <stdio.h>
int n, i, j, visited[10] = {0}, queue[10] = {0}, front = -1, rear = -1;
int adj[4][4] = {{0, 1, 1, 0},
                 {1, 0, 0, 0},
                 {1, 0, 0, 1},
                 {0, 1, 0, 0}};
void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (adj[v][i] && !visited[i])
            queue[++rear] = i;
    if (front <= rear)
    {
        visited[queue[front]] = 1;
        bfs(queue[front++]);
    }
}
int main()
{
    n = 4;
    for (i = 1; i <= n; i++)
    {
        queue[i] = 0;
        visited[i] = 0;
    }
    bfs(2);
    printf("The node which are reachable are:    \n");
    for (i = 1; i <= n; i++)
        if (visited[i])
            printf("%d\t", i);
        else
            printf("BFS is not possible. Not all nodes are reachable");
    return 0;
}