#include <stdio.h>
#include <math.h>

double PI = acos(-1);

int	main(void)
{
	double	a, b, h;
	double	h0, big_circle, small_circle, result;

	scanf("%lf %lf %lf", &a, &b, &h);
	if (a == b)
	{
		printf("-1\n");
		return 0;
	}
	if (a > b)
	{
		double	tmp = a;
		a = b;
		b = tmp;
	}
	h0 = (double)a * h / (b - a);
	big_circle = pow(h0 + h, 2) + pow(b, 2);
	if (a)
		small_circle = pow(h0, 2) + pow(a, 2);
	else
		small_circle = 0;
	result = (big_circle - small_circle) * PI;

	printf("%.7lf\n", result);
}
