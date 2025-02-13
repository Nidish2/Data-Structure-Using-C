#include <stdlib.h>
#include <stdio.h>

int s[30], top = -1, visited[30], n = 7,
           a[30][30] = {
               {0, 1, 1, 1, 1, 0, 0},
               {1, 0, 0, 1, 0, 1, 0},
               {1, 0, 0, 0, 0, 0, 1},
               {1, 1, 0, 0, 0, 1, 0},
               {1, 0, 0, 0, 0, 0, 1},
               {0, 1, 0, 1, 0, 0, 0},
               {0, 0, 1, 0, 1, 0, 0}},
           count = 0;

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

void dfs(int start)
{
    visited[start] = 1;
    s[++top] = start;
    for (int i = 0; i < n; i++)
    {
        if (a[start][i] == 1 && visited[i] == 0)
        {
            dfs(i);
            count++;
        }
    }
}

int main()
{
    int start;
    // create_graph();
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    printf("Enter the starting vertex: ");
    scanf("%d", &start);
    dfs(start);
    printf("Nodes reachable from %d are: \n", start);
    for (int i = 0; i <= count; i++)
    {
        printf("%d ", s[i]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int i = 0; i < n; i++)
    //     {
    //         visited[i] = 0;
    //     }
    //     count=0;
    //     dfs(i);
    //     printf("Nodes reachable from %d are: \n", i);
    //     for (int i = 0; i <= count; i++)
    //     {
    //         printf("%d ", s[i]);
    //     }
    //     printf("\n");
    // }
    return 0;
}