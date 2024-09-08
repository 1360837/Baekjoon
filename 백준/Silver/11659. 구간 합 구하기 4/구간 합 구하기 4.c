#include <stdio.h>
#include <stdlib.h>

int     main(void)
{
        int     N, M;
        int     *num;
        int     *sum;

        scanf("%d %d", &N, &M);
        num = malloc(sizeof(int) * (N + 1));
        sum = malloc(sizeof(int) * (N + 1));
        num[0] = sum[0] = 0;
        for (int i = 1; i <= N; i++)
        {
                scanf("%d", &num[i]);
                sum[i] = sum[i - 1] + num[i];
        }
        for (int i = 0; i < M; i++)
        {
                int     start, end;
                scanf("%d %d", &start, &end);
                printf("%d\n", sum[end] - sum[start - 1]);
        }
}
