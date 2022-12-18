#include <stdio.h>
#include <stdlib.h>

int add(int x)
{
    static int sum = 0;
    sum += x;
    return (sum);
}

int main ()
{
    printf("%d\n", add(5));
    printf("%d\n", add(4));
    printf("%d\n", add(3));
    return (0);
}

/* Variable Modifiers − Auto & Extern   https://www.youtube.com/watch?v=1Dkfmf4PmvQ */
/* Variable Modifiers − Register        https://www.youtube.com/watch?v=qHZ7qf6-rhc */
