#include <stdio.h>

int	main(void)
{
	int	T;

	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int	total_m, month_d, week_d;
		int	tmp_total_d;
		int	result;

		scanf("%d %d %d", &total_m, &month_d, &week_d);
		result = (total_m * month_d) / week_d;
		tmp_total_d = total_m * month_d;
		while (tmp_total_d > 0)
		{
			if (tmp_total_d % week_d)
				result += 1;
			tmp_total_d -= month_d;
		}
		printf("Case #%d: %d\n", i, result);
	}
}