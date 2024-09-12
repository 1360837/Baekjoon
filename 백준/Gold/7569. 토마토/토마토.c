#include <stdio.h>
#include <stdlib.h>

# define MAX_QUEUE_SIZE 1000000

int     M, N, H;
int     ***tomato;
int     move_x[6] = {1, 0, -1, 0, 0, 0};
int     move_y[6] = {0, 1, 0, -1, 0, 0};
int	move_z[6] = {0, 0, 0, 0, 1, -1};

int	queue[MAX_QUEUE_SIZE][3];
int     front = 0, rear = 0;

void	push(int x, int y, int z)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	queue[rear][0] = x;
	queue[rear][1] = y;
	queue[rear][2] = z;
}

void	pop(int *x, int *y, int *z)
{
	front = (front + 1) % MAX_QUEUE_SIZE;
	*x = queue[front][0];
	*y = queue[front][1];
	*z = queue[front][2];
}

void    bfs()
{
        int     x, y, z;
        int     x_, y_, z_;

        while (front != rear)
        {
		pop(&x, &y, &z);
                for (int i = 0; i < 6; i++)
                {
                        x_ = x + move_x[i];
                        y_ = y + move_y[i];
			z_ = z + move_z[i];
                        if (x_ < 0 || x_ >= H || y_ < 0 || y_ >= N || z_ < 0 || z_ >= M)
                                continue ;
                        if (tomato[x_][y_][z_] == 0)
                        {
                                tomato[x_][y_][z_] = tomato[x][y][z] + 1;
                        	push(x_, y_, z_);
			}
                }
        }
}

int     main(void)
{
        int     max = 0;
        int     cnt = 0;
	int	cnt_empty = 0;

        scanf("%d %d %d", &M, &N, &H);
        tomato = malloc(sizeof(int **) * H);
        for (int i = 0; i < H; i++)
        {
                tomato[i] = malloc(sizeof(int *) * N);
                for (int j = 0; j < N; j++)
                {
			tomato[i][j] = malloc(sizeof(int) * M);
			for (int k = 0; k < M; k++)
			{
                        	scanf("%d", &tomato[i][j][k]);
                        	if (tomato[i][j][k] == 1)
					push(i, j, k);
                        	else if (tomato[i][j][k] == 0)
                                	cnt++;
				else if (tomato[i][j][k] == -1)
					cnt_empty++;
			}
                }
        }
        if (cnt == 0)
        {
                printf("0\n");
                return 0;
        }
        if (cnt + cnt_empty == (N * M * H))
        {
                printf("-1\n");
                return 0;
        }
        bfs();
        for (int i = 0; i < H; i++)
        {
                for (int j = 0; j < N; j++)
                {
			for (int k = 0; k < M; k++)
			{
				if (tomato[i][j][k] == 0)
                        	{
                                	printf("-1\n");
                                	return 0;
                        	}
                        	if (max < tomato[i][j][k])
                                	max = tomato[i][j][k];
			}
                }
        }
        printf("%d\n", max - 1);
}

