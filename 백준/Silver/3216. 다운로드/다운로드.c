#include <stdio.h>
#include <stdlib.h>

int     main(void)
{
        int     N;  
        int     *D, *V; 
        int     temp, ans;

        scanf("%d", &N);
        D = malloc(sizeof(int) * N); 
        V = malloc(sizeof(int) * N); 
        for (int i = 0; i < N; i++)
                scanf("%d %d", &D[i], &V[i]);
        temp = D[0];
        ans = V[0];
        for (int i = 1; i < N; i++)
        {
                temp -= V[i];
                if (temp < 0)
                {
                        ans -= temp;
                        temp = 0;
                }
                temp += D[i];
        }
        printf("%d\n", ans);
}