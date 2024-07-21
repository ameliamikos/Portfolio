#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x;
    do
        //get height value
    {
        x = get_int("Height: "); //height value = x
    }
    while (x < 1 || x > 8); //prompts for new height if number not btwn 1 and 8

    //i counts up to x
    for (int i = 0; i < x; i++)
    {
        for (int n = 1; n < (x - i); n++)   //for loop for printing spaces is n variable
        {
            printf(" ");
        }

        for (int j = 0; j < (i + 1) ; j++)  //for loop for printing #s is j variable
        {
            printf("#");
        }

        printf("\n");
    }
}
