#include <stdio.h>

int	mul(int a, int b, int c)
{
	unsigned long long tmp;

	if (b == 0)
		return (1);
	else if (b == 1)
		return (a);
	else
	{
		tmp = mul(a, b / 2, c) % c;
		tmp = (tmp * tmp) % c;
		if (b % 2 == 1)
			return ((a * tmp) % c);
		else
			return (tmp);
	}
}

int	main(void)
{
	int	A, B, C;

	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", mul(A, B, C) % C);
}
