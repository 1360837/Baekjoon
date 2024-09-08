#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int     main(void)
{
        int     M;
        int     S[21] = {0};
        char    buf[10];
        int     num;

        scanf("%d", &M);
        for (int i = 0; i < M; i++)
        {
                scanf("%s", buf);
                if (!strcmp(buf, "add"))
                {
                        scanf("%d", &num);
                        S[num] = 1;
                }
                else if (!strcmp(buf, "remove"))
                {
                        scanf("%d", &num);
                        S[num] = 0;
                }
                else if (!strcmp(buf, "check"))
                {
                        scanf("%d", &num);
                        printf("%d\n", S[num]);
                }
                else if (!strcmp(buf, "toggle"))
                {
                        scanf("%d", &num);
                        S[num] = S[num] ? 0 : 1;
                }
                else if (!strcmp(buf, "all"))
                        for (int i = 1; i <= 20; i++)
                                S[i] = 1;
                else if (!strcmp(buf, "empty"))
                        for (int i = 1; i <= 20; i++)
                                S[i] = 0;
        }
}
