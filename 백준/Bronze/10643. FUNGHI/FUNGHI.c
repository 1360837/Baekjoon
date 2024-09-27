#include <stdio.h>

int	main(void)
{
	int	pizza[8];
	int	max = 0;

	for (int i = 0; i < 8; i++)
		scanf("%d", &pizza[i]);
	for (int i = 0; i < 8; i++)
	{
		int	tmp;
		tmp = pizza[i] + pizza[(i + 1) % 8] + pizza[(i + 2) % 8] + pizza[(i + 3) % 8];
		if (tmp > max)
			max = tmp;
	}
	printf("%d\n", max);
}
