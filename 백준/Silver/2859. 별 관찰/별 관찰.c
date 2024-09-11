#include <stdio.h>
#include <stdlib.h>

int     main(void)
{
        int     star[4];
        int     cnt = 0;
        char    input[6];
        char    *days[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
        int     hour, min;

        for (int i = 0; i < 4; i++)
        {
                scanf("%s",input);
                star[i] = atoi(&input[0]) * 60 + atoi(&input[3]);
        }
        while (cnt < 100000)
        {
                if (star[0] == star[1])
                        break ;
                else if (star[0] < star[1])
                        star[0] += star[2];
                else
                        star[1] += star[3];
                cnt++;
        }
        if (cnt == 100000)
                printf("Never\n");
        else
        {       hour = (star[0] % 1440) / 60; 
                min = (star[0] % 1440) % 60; 
                printf("%s\n", days[(star[0] / 1440) % 7]);
                printf("%s%d:%s%d\n", (hour < 10) ? "0" : "", hour, (min < 10) ? "0" : "", min);
        }
}