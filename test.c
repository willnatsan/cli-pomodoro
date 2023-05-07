#include <stdio.h>
#include <conio.h>

int main()
{
    while(!kbhit())
    {
        printf("Hit a key!\n");
    }

    return 0;
}