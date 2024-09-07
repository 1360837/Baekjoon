#include <stdio.h>

int     main(void)
{
        int     A, B, C;
        int     cnt = 1, temp;

        scanf("%d %d %d", &A, &B, &C);
        temp = B;
        while (temp > 0)
        {
                temp /= 10;
                cnt *= 10;
        }
        printf("%d\n", A + B - C);
        printf("%d\n", (A * cnt) + B - C);
}