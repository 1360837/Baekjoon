#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	name[11];
	int	age, weight;

	while (1)
	{
		scanf("%s %d %d", name, &age, &weight);

		if (!strcmp(name, "#") && age == 0 && weight == 0)
			break ;
		printf("%s ", name);
		if (age > 17 || weight >= 80)
			printf("Senior\n");
		else
			printf("Junior\n");
	}
}
