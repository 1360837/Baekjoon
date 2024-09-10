#include <stdio.h>
#include <stdlib.h>

int     main(void)
{
        int     N, K, A;
        int     *t, *s; 
        int     *drink;
        int     time, min;

        scanf("%d %d %d", &N, &K, &A);
        time = K / A;
        t = malloc(sizeof(int) * N); 
        s = malloc(sizeof(int) * N); 
        drink = malloc(sizeof(int) * N); 
        for (int i = 0; i < N; i++)
                scanf("%d %d", &t[i], &s[i]);
        for (int i = 0; i < N; i++)
        {
                drink[i] = time + ((time % t[i]) == 0 ? (time / t[i] - 1) : (time / t[i])) * s[i];
                if (i == 0)
                        min = drink[i];
                else
                        if (min > drink[i])
                                min = drink[i];
        }
        printf("%d\n", min);
}
