#include <stdio.h>

// Maximum input line size
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

// print longest input line
main()
{
    // current line length
    int len;
    // maximu length seen so far
    int max;
    //current input line
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    // there was a line
    if (max > 0)
        printf("%s", longest);
    return 0;
}

// getline: read a line into s, return length
int getline(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!=']n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\n';
    return i;
}
