#include <stdio.h>

int main() {
    int c;

    printf("Type a character and press Enter (Ctrl+D to send EOF in Linux/macOS, Ctrl+Z for Windows):\n");
    
    c = (getchar() != EOF); // Evaluates to 1 (if character) or 0 (if EOF)
    
    printf("The expression 'getchar() !=' evaluates to: %d\n", c);

    return 0;
}