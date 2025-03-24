#include <stdio.h>

int main()
{
    int c;
    int blanks = 0;
    int tabs = 0;
    int newlines = 0;

    printf("Enter character stream and press Ctrl-D or Ctrl-Z:\n");

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            blanks++;
        if (c == '\t')
            tabs++;
        if (c == '\n')
            newlines++;
    }

    printf("\nBlanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}
