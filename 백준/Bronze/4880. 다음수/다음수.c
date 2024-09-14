#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	a1, a2, a3;
	int	next;
	char	c[3];
	
	while (1)
	{
		scanf("%d %d %d", &a1, &a2, &a3);
		if (a1 == 0 && a2 == 0 && a3 == 0)
			break ;
		if (2 * a2 == a1 + a3)
		{
			strcpy(c, "AP");
			next = a3 + (a3 - a2);
		}
		else if (a2 * a2 == a1 * a3)
		{
			strcpy(c, "GP");
			next = a3 * (a3 / a2);
		}
		printf("%s %d\n", c, next);
	}
}
