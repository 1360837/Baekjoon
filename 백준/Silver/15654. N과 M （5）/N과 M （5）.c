#include <stdio.h>
#include <stdlib.h>

int	N, M;
int	*num;
int	*seq;

void	print_seq()
{
	for (int i = 0; i < M; i++)
		printf("%d ", seq[i]);
	printf("\n");
}

int	is_valid(int col)
{
	for (int c = 0; c < col; c++)
	{
		if (seq[c] == seq[col])
			return 0;
	}
	return 1;
}

void	solving(int c)
{
	int	i = 0;

	if (c >= M)
		return ;
	while (i < N)
	{
		seq[c] = num[i];
		if (is_valid(c))
		{
			if (c == M - 1)
				print_seq();
			else
				solving(c + 1);
		}
		i++;
	}
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int	main(void)
{
	scanf("%d %d", &N, &M);
	num = malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	qsort(num, N, sizeof(int), compare);
	seq = malloc(sizeof(int) * M);
	solving(0);
}
