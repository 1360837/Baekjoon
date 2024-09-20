#include <stdio.h>

int	main(void)
{
	int	N;
	double	qaly = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		double	q, y;

		scanf("%lf %lf", &q, &y);
		qaly += (q * y);
	}
	printf("%.3lf\n", qaly);
}