#include <stdlib.h>
#include <stdio.h>

int q[30], f = 0, r = -1, visited[30], n = 7,
           a[30][30] = {
               {0, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 0, 1, 0},
               {1, 0, 0, 0, 0, 0, 1},
               {1, 1, 0, 0, 0, 1, 0},
               {1, 0, 0, 0, 0, 0, 1},
               {0, 1, 0, 1, 0, 0, 0},
               {0, 0, 1, 0, 1, 0, 0}};

// void create_graph()
// {
//     printf("Enter the number of vertices: ");
//     scanf("%d", &n);
//     printf("Enter the adjacency matrix:\n");
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             scanf("%d", &a[i][j]);
//         }
//     }
// }

void bfs(int start)
{
    int cur;
    visited[start] = 1;
    q[++r] = start;
    printf("Nodes reachable from %d are: \n", start);
    while (f <= r)
    {
        cur = q[f++];
        printf("%d  ", cur);
        for (int i = 0; i < n; i++)
        {
            if (a[cur][i] == 1 && visited[i] == 0)
            {
                q[++r] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    // int start;
    // create_graph();
    // for (int i = 0; i < n; i++)
    // {
    //     visited[i] = 0;
    // }
    // printf("Enter the starting vertex: ");
    // scanf("%d", &start);
    // bfs(start);
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
        bfs(i);
    }

    return 0;
}