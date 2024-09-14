#include <stdio.h>
#include <stdlib.h>

int	N, cnt = 0;
int	*buf;

int	is_valid(int c)
{
	for (int i = 0; i < c; i++)
	{
		if (buf[i] == buf[c])
			return 0;
		if (buf[i] + i == buf[c] + c)
			return 0;
		if (buf[i] - i == buf[c] - c)
			return 0;
	}
	return 1;
}

void	solve(int col)
{
	if (col == N)
		return ;
	for (int num = 0; num < N; num++)
	{
		buf[col] = num;
		if (is_valid(col))
		{
			if (col == N - 1)
				cnt++;
			else
				solve(col + 1);
		}
	}
}


int	main(void)
{
	scanf("%d", &N);
	buf = malloc(sizeof(int) * N);
	solve(0);
	printf("%d\n", cnt);
}
