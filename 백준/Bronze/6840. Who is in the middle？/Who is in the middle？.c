#include <stdio.h>

int    main(void)
{
    int    a, b, c;
    
    scanf("%d %d %d", &a, &b, &c);
    if ((a >= b && b >= c) || (b >= a && c >= b))
        printf("%d\n", b);
    else if ((a >= b && c >= a) || (b >= a && a >= c))
        printf("%d\n", a);
    else if ((a >= c && c >= b) || (b >= c) && (c >= a))
        printf("%d\n", c);
}