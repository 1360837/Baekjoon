#include <stdio.h>

# define MAX_STACK_SIZE 1000000

int	stack[MAX_STACK_SIZE][2];
int	top = -1;

int	main(void)
{
	int	N;
	int	n, A, T;
	int	result = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			if (top >= 0)
			{
				stack[top][1]--;
				if (stack[top][1] == 0)
					result += stack[top--][0];
			}
			continue ;
		}
		else
		{
			scanf("%d %d", &A, &T);
			stack[++top][0] = A;
			stack[top][1] = T - 1;
			if (stack[top][1] == 0)
				result += stack[top--][0];
		}
	}
	printf("%d\n", result);
}
