#include <stdio.h>
#include <stdlib.h>

char	**campus;
int	**visit;
int	N, M;
int	cnt = 0;

int	move_x[4] = {1, 0, -1, 0};
int	move_y[4] = {0, 1, 0, -1};

int	queue[360000][2];
int	front = 0, rear = 0;

void	bfs(int x, int y)
{
	int	dx, dy;

	visit[x][y] = 1;
	queue[rear][0] = x;
	queue[rear++][1] = y;
	while (front != rear)
	{
		x = queue[front][0];
		y = queue[front++][1];
		for (int i = 0; i < 4; i++)
		{
			dx = x + move_x[i];
			dy = y + move_y[i];
			if (dx < 0 || dy < 0 || dx >= N || dy >= M)
				continue ;
			if (!visit[dx][dy] && campus[dx][dy] != 'X')
			{
				visit[dx][dy] = 1;
				queue[rear][0] = dx;
				queue[rear++][1] = dy;
				if (campus[dx][dy] == 'P')
					cnt++;
			}
		}
	}
}

int	main(void)
{
	int	start_x, start_y;
	
	scanf("%d %d", &N, &M);
	campus = malloc(sizeof(char *) * N);
	visit = malloc(sizeof(int *) * N);
	for (int i = 0; i < N; i++)
	{
		campus[i] = malloc(sizeof(char) * M);
		visit[i] = malloc(sizeof(int) * M);
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 0;
			scanf(" %c", &campus[i][j]);
			if (campus[i][j] == 'I')
			{
				start_x = i;
				start_y = j;
			}
		}
	}
	bfs(start_x, start_y);
	if (cnt)
		printf("%d\n", cnt);
	else
		printf("TT\n");
}

