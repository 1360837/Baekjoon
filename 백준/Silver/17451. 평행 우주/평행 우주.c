#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	n, *v;
	long long	need_v;

	scanf("%d", &n);
	v = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	need_v = v[n - 1];
	for (int i = n -2; i >= 0; i--)
	{
		if (need_v % v[i] == 0)
			continue ;
		need_v = (long long)(need_v / v[i] + 1) * v[i];
	}
	printf("%lld\n", need_v);
	free(v);
	return 0;
}
