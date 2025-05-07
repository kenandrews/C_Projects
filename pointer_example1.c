#include <stdio.h>
#include <stdlib.h>

void print_address(void *ptr){
    printf("Memory Address: %p\n", ptr);
}

int main(){
    int number = 42;
    print_address(&number);
    return 0;
}
