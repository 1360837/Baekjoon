#include <stdio.h>
#include <stdlib.h>

int     compare(const void *a, const void *b)
{
        int     x = *(const int *)a;
        int     y = *(const int *)b;
        return (x - y);
}

int     unique(int *arr, int N)
{
        if (N == 0)
                return 0;

        int     cnt = 0;
        for (int i = 1; i < N; i++)
        {
                if (arr[i] != arr[cnt])
                        arr[++cnt] = arr[i];
        }
        return (cnt + 1);
}

int     BinarySearch(int *arr, int n, int find)
{
        int     left = 0, right = n - 1;
        int     mid;

        while (left <= right)
        {
                mid = (left + right) / 2;
                if (arr[mid] == find)
                        return mid;
                if (arr[mid] < find)
                        left = mid + 1;
                else
                        right = mid - 1;
        }
        return (-1);
}

int     main(void)
{
        int     N;
        int     num;
        int     *X;
        int     *arr;

        scanf("%d", &N);
        X = malloc(sizeof(int) * N);
        arr = malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++)
        {
                scanf("%d", &X[i]);
                arr[i] = X[i];
        }
        qsort(arr, N, sizeof(int), compare);
        num = unique(arr, N);
        for (int i = 0; i < N; i++)
                printf("%d%s", BinarySearch(arr, num, X[i]), (i == N -1) ? "\n" : " ");
}