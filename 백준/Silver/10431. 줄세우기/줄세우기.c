#include <stdio.h>

# define STUDENT 20

int	arr[STUDENT];
int	cnt;

void	init_arr(void);
void	sort_arr(void);

int	main(void)
{
	int	P, T;

	scanf("%d", &P);
	for (int p = 1; p <= P; p++)
	{
		scanf("%d", &T);
		init_arr();
		cnt = 0;
		sort_arr();
		printf("%d %d\n", T, cnt);
	}
}

void	init_arr(void)
{
	for (int i = 0; i < 20; i++)
		scanf("%d", &arr[i]);
}

void sort_arr(void)
{
	for (int i = 1; i < STUDENT; i++)
	{
		int tmp = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > tmp)
		{
			arr[j + 1] = arr[j];
			cnt++;
			j--;
		}
		arr[j + 1] = tmp;
	}
}
/*
void	sort_arr(void)
{
	int	tmp, idx, flag;

	idx = STUDENT - 1;
	for (int i = 0; i < 20; i++)
	{
		tmp = arr[idx];
		for (int j = 0; j < idx; j++)
		{
			flag = 1;
			if (arr[j] > tmp)
			{
				for (int k = idx; k > j; k--)
				{
					arr[k] = arr[k - 1];
					cnt++;
				}
				arr[j] = tmp;
				flag = 0;
				break ;
			}
		}
		if (flag)
			idx--;
	}
}
*/
