#include <stdio.h>

// Function to convert Fahrenheit to Celsius

float fahrenheit_to_celsius(int fahr){
    return (5.0/9.0) * (fahr -32);
}

int main(){
    int lower = 0;
    int upper = 300;
    int step = 20;
    int fahr;
    float celsius;

    printf("Fahrenheit to Celsius Conversion Table\n");
    printf("--------------------------------------\n");
    for (fahr = lower; fahr <= upper; fahr += step){
        celsius = fahrenheit_to_celsius(fahr);
        printf("%3d \t %6.1f\n", fahr, celsius);
    }

    return 0;
}