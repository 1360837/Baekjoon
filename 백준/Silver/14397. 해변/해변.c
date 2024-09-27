#include <stdio.h>
#include <stdlib.h>

char	**map;
int	N, M;

int	move_j_odd[3] = {0, 1, 1};
int	move_i_odd[3] = {1, 1, 0};
int	move_j_even[3] = {-1, 0, 1};
int	move_i_even[3] = {1, 1, 0};

int	main(void)
{
	int	beach = 0;

	scanf("%d %d", &N, &M);
	map = malloc(sizeof(char *) * N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		map[i] = malloc(sizeof(char) * M);
		for (int j = 0; j < M; j++)
			scanf("%c", &map[i][j]);
		getchar();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int	di = i + ((i % 2) ? move_i_odd[k] : move_i_even[k]);
				int	dj = j + ((i % 2) ? move_j_odd[k] : move_j_even[k]);
				if (di < 0 || dj < 0 || di >= N || dj >= M)
					continue ;
				if (map[i][j] != map[di][dj])
					beach++;
			}
		}
	}
	printf("%d\n", beach);
}
