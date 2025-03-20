#include <stdio.h>

/* Copy input to output version 2 */

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    return 0;
}