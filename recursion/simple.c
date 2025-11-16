#include <stdio.h>

// Prototypes
int counter(int);
int generalRecursionOfCounter(int);

int main()
{

    int b = generalRecursionOfCounter(10);

    printf("Final number is: %i \n", b);

    return 0;
}

// Simple recursion function
int counter(int i)
{
    if (i != 0 && i > 0)
    {
        printf("i => %i \n", i);
        return counter(i - 1);
    }
    else if (i != 0 && i < 0)
    {
        printf("i => %i \n", i);
        return counter(i + 1);
    }

    return i;
}

int generalRecursionOfCounter(int i)
{
    if (i != 0 && i > 0)
    {
        printf("i => %i \n", i);
        counter(i - 1);
        printf("i => %i \n", i);

    }
    else if (i != 0 && i < 0)
    {
        printf("i => %i \n", i);
        counter(i + 1);
        printf("i => %i \n", i);
    }
    return i;
}
