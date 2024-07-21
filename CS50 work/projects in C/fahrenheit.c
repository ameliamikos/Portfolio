#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //get celsius value
    float c = get_float("celsius: ");

    //F = ((C x 9)/5)+32
    float f = (float)(((c * 9) / 5) + 32);

    //prints the answer with "fahrenheit:" before it
    printf("Fahrenheit: %.1f\n", f);
}