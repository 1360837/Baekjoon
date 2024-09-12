#include <stdio.h>
#include <stdlib.h>

int     M, N;
int     **tomato;
int     move_x[4] = {1, 0, -1, 0};
int     move_y[4] = {0, 1, 0, -1};

int     queue[1000000][2];
int     front = 0, rear = 0;

void    bfs()
{
        int     x, y;
        int     x_, y_;

        while (front != rear)
        {
                x = queue[front][0];
                y = queue[front++][1];
                for (int i = 0; i < 4; i++)
                {
                        x_ = x + move_x[i];
                        y_ = y + move_y[i];
                        if (x_ < 0 || x_ >= N || y_ < 0 || y_ >= M)
                                continue ;
                        if (tomato[x_][y_] == 0)
                        {
                                tomato[x_][y_] = tomato[x][y] + 1;
                                queue[rear][0] = x_;
                                queue[rear++][1] = y_;
                        }
                }
        }
}

int     main(void)
{
        int     max = 0;
        int     cnt = 0;

        scanf("%d %d", &M, &N);
        tomato = malloc(sizeof(int *) * N);
        for (int i = 0; i < N; i++)
        {
                tomato[i] = malloc(sizeof(int) * M);
                for (int j = 0; j < M; j++)
                {
                        scanf("%d", &tomato[i][j]);
                        if (tomato[i][j] == 1)
                        {
                                queue[rear][0] = i;
                                queue[rear++][1] = j;
                        }
                        else if (tomato[i][j] == 0 || tomato[i][j] == -1)
                                cnt++;
                }
        }
        if (cnt == 0)
        {
                printf("0\n");
                return 0;
        }
        if (cnt == (N * M))
        {
                printf("-1\n");
                return 0;
        }
        bfs();
        for (int i = 0; i < N; i++)
        {
                for (int j = 0; j < M; j++)
                {
                        if (tomato[i][j] == 0)
                        {
                                printf("-1\n");
                                return 0;
                        }
                        if (max < tomato[i][j])
                                max = tomato[i][j];
                }
        }
        printf("%d\n", max - 1);
}
