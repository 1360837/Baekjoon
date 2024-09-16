#include <stdio.h>

int    main(void)
{
    long long    A, B;
    long long    result;
    
    scanf("%lld %lld", &A, &B);
    result = (A + B) * (A - B);
    printf("%lld\n", result);
}