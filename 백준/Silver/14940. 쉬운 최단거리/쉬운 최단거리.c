#include <stdio.h>
#include <stdlib.h>

int     n, m;
int     **map;
int     **distance;
int     **visit;

typedef struct point
{
        int     x;
        int     y;
}point;
point   queue[1000001];
int     front = 0, rear = 0;

int     direX[4] = {1, 0, -1, 0};
int     direY[4] = {0, 1, 0, -1};

void    bfs(point P)
{
        point curr;
        point next;

        visit[P.x][P.y] = 1;
        distance[P.x][P.y] = 0;
        queue[rear++] = P;
        while (front != rear)
        {
                curr = queue[front++];
                for (int i = 0; i < 4; i++)
                {
                        next.x = curr.x + direX[i];
                        next.y = curr.y + direY[i];
                        if (next.x >= n || next.x < 0 || next.y >= m || next.y < 0)
                                continue;
                        if (visit[next.x][next.y] == 0 && map[next.x][next.y] != 0)
                        {
                                queue[rear++] = next;
                                visit[next.x][next.y] = 1;
                                distance[next.x][next.y] = distance[curr.x][curr.y] + 1;
                        }
                }
        }
}

int     main(void)
{
        point   dest;

        scanf("%d %d", &n, &m);
        map = malloc(sizeof(int *) * n);
        distance = malloc(sizeof(int *) * n);
        visit = malloc(sizeof(int *) * n);
        for (int i = 0; i < n; i++)
        {
                map[i] = malloc(sizeof(int) * m);
                distance[i] = malloc(sizeof(int) * m);
                visit[i] = malloc(sizeof(int) * m);
                for (int j = 0; j < m; j++)
                {
                        visit[i][j] = 0;
                        scanf("%d", &map[i][j]);
                        if (map[i][j] == 2)
                        {
                                dest.x = i;
                                dest.y = j;
                        }
                }
        }
        bfs(dest);
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < m; j++)
                {
                        if (!visit[i][j] && map[i][j])
                                printf("-1 ");
                        else
                                printf("%d ", distance[i][j]);
                }
                printf("\n");
        }
}

