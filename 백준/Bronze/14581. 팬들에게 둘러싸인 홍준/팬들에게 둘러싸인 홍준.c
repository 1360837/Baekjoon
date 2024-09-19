#include <stdio.h>

int    main(void)
{
    char    name[21];
    
    scanf("%s", name);
    for (int i = 0; i < 3; i++)
        printf(":fan:");
    printf("\n");
    printf(":fan:");
    printf(":%s:", name);
    printf(":fan:\n");
    for (int i = 0; i < 3; i++)
        printf(":fan:");
}