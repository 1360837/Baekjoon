#include <stdio.h>
#include <stdlib.h>

int	N, M;
int	*seq;

void	print_seq()
{
	for (int i = 0; i < M; i++)
		printf("%d ", seq[i]);
	printf("\n");
}

void	solving(int c, int n)
{
	int	num = n + 1;
	if (c >= M || num > N)
		return ;
	while (num <= N)
	{
		seq[c] = num;
		if (c == M - 1)
			print_seq();
		else
			solving(c + 1, num);
		num++;
	}
}

int	main(void)
{
	scanf("%d %d", &N, &M);
	seq = malloc(sizeof(int) * M);
	solving(0, 0);
}
