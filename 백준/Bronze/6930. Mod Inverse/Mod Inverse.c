#include <stdio.h>

int	main(void)
{
	int	x, m;
	int	n = 0;

	scanf("%d %d", &x, &m);
	for (int i = 2; i < m; i++)
	{
		if ((x * i) % m == 1)
		       n = i;
	}
	if (n)
		printf("%d\n", n);
	else
		printf("No such integer exists.\n");	
}