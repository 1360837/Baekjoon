#include <stdio.h>
#include <stdlib.h>

int	**Board;
int	blue = 0, white = 0;

void	rec(int x, int y, int n)
{
	int	color = Board[x][y];

	if (n == 1)
	{
		if (Board[x][y] == 1)
			blue++;
		else
			white++;
		return ;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (color != Board[x + i][y + j])
			{
				rec(x, y, n / 2);
				rec(x, y + (n / 2), n / 2);
				rec(x + (n / 2), y, n / 2);
				rec(x + (n / 2), y + (n / 2), n / 2);
				return ;
			}
		}
	}
	if (color == 1)
		blue++;
	else
		white++;
	return ;
}

int	main(void)
{
	int	N;

	scanf("%d", &N);
	Board = malloc(sizeof(int *) * N);
	for (int i = 0; i < N; i ++)
	{
		Board[i] = malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
			scanf("%d", &Board[i][j]);
	}
	rec(0, 0, N);
	printf("%d\n%d\n", white, blue);
}
