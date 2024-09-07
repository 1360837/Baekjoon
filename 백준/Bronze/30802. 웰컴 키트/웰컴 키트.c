#include <stdio.h>

int     main(void)
{
        unsigned int    N, T, P;
        unsigned int    size[6] = {0};
        unsigned int    cnt = 0;

        scanf("%d", &N);
        for (int i = 0; i < 6; i++)
                scanf("%d", &size[i]);
        scanf("%d %d", &T, &P);

        for (int i = 0; i < 6; i++)
        {
                if (size[i] % T)
                        cnt++;
                cnt += (size[i] / T);
        }
        printf("%d\n", cnt);
        printf("%d %d\n", N / P, N % P);
}