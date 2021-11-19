#include <stdio.h>
#include "../hello.c"

void assert(int, int);
void plus_happypath(void);

int main()
{
    plus_happypath();
}

/////// Tests

void plus_happypath(void)
{
    printf("Testing: plus_happypath\n");

    int result = plus(2, 1);

    assert(2, result);
}

/////// Testing Library

void assert(int expected, int actual)
{
    if (expected != actual)
    {
        printf("Fail: '%d' != '%d'\n", expected, actual);
        return;
    }
}
