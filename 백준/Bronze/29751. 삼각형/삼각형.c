#include <stdio.h>

int	main(void)
{
	int	W, H;

	scanf("%d %d", &W, &H);
	printf("%.1f\n", (float)(W * H) / 2);
}