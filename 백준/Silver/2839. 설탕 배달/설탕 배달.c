#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	N;
	int	cnt3, cnt5;

	scanf("%d", &N);
	cnt5 = N / 5;
	N = N % 5;
	while (N % 3 != 0)
	{
		if (cnt5 == 0)
		{
			printf("-1\n");
			return 0;
		}
		cnt5--;
		N+=5;
	}
	cnt3 = N / 3;
	printf("%d\n", cnt3 + cnt5);
}
