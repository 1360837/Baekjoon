#include <stdio.h>
#include <stdlib.h>

int	N, M;
int	cnt;
int	**table;

int	check[101] = {0};

int	move_x[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int	move_y[8] = {1, 0, -1, 1, -1, 1, 0, -1};

void	input_data(int N, int M);
void	init_data(void);
void	del_data(int N, int M);
void	table_check(int x, int y);

int	main(void)
{
	int	T;

	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%d %d", &N, &M);
		init_data();
		input_data(N, M);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				table_check(i, j);
			}
		}
		del_data(N, M);
		printf("%d\n", cnt);
	}
}

void    input_data(int N, int M)
{
        table = malloc(sizeof(int *) * N);
        for (int i = 0; i < N; i++)
        {
                table[i] = malloc(sizeof(int) * M);
                for (int j = 0; j < M; j++)
                        scanf("%d", &table[i][j]);
        }
}

void    init_data(void)
{
        cnt = 0;
        for (int i = 0; i < 101; i++)
                check[i] = 0;
}

void    del_data(int N, int M)
{
        for (int i = 0; i < N; i++)
                free(table[i]);
        free(table);
}

void	table_check(int x, int y)
{
	int	dx, dy;
	int	val = table[x][y];

	if (check[val] == 1 || val == -1)
		return ;
	for (int i = 0; i < 8; i++)
	{
		dx = x + move_x[i];
		dy = y + move_y[i];
		if (dx < 0 || dy < 0 || dx >= N || dy >= M)
			continue ;
		if (table[x][y] == table[dx][dy])
		{
			cnt ++;
			check[val] = 1;
			return ;
		}
	}
}