#include <stdio.h>
#include <stdlib.h>

int     *tree;
int     N, M;

int     bin_search(int low, int high)
{
        int     mid, result;
        long    tree_m;

	result = 0;
	while (low <= high)
	{
		mid = (low + high) / 2;
		tree_m = 0;
		for (int i = 0; i < N; i++)
		{
			if (tree[i] - mid > 0)
				tree_m += (tree[i] - mid);
		}
		if (tree_m == M)
		{
			result = mid;
			break ;
		}
		if (tree_m > M)
		{
			result = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return (result);
}

int     main(void)
{
        int     max = 0;
        int     meter;

        scanf("%d %d",&N, &M);
        tree = malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++)
        {
                scanf("%d", &tree[i]);
                if (max < tree[i])
                        max = tree[i];
        }
        meter = bin_search(0, max);
        printf("%d\n", meter);
}