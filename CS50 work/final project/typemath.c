#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <math.h>

//what it do: user inputs a type of operation to start. simple + - * / and ALSO
//average, square root,

#define POINTS 10
float points[POINTS];

//function prototypes
float sum(int numbers);
float subtraction(float s1, float s2);
float multiplication(int factors);
float division(float f1, float f2);
float averaging(int numbs);
float root(int number);


int main(int argc, string argv[])
{
    //verify correct command line arguments
    if (argc < 2)
    {
        printf("Error! Usage: input an operation!\n");
        printf("Accepted types: sum, difference, product, quotient, average, square root \n");
    }
    string type = argv[1]; //command line argument becomes comparable string
    char  redo = 'n';
    do
    {
        if (redo == 'y')
        {
            string newop = get_string("What kind of problem next: ");
            type = newop;
        }
        if (strcasecmp(type, "sum") == 0)
        {
            int numbers = get_int("How many numbers are you adding (up to 10): ");
            //they want the sum, take the amount of integers, prompt that many times
            float total = sum(numbers);
        }
        if (strcasecmp(type, "difference") == 0)
        {
            float s1 = get_float("Subtracting from: ");
            float s2 = get_float("Taking away: ");
            float difference = subtraction(s1, s2);
        }
        if (strcasecmp(type, "product") == 0)
        {
            int factors = get_int("How many numbers are you multiplying (up to 10): ");
            float product = multiplication(factors);
        }
        if (strcasecmp(type, "quotient") == 0)
        {
            float f1 = get_float("Dividing: ");
            float f2 = get_float("Dividing by: ");
            float quotient = division(f1, f2);
        }
        if (strcasecmp(type, "average") == 0)
        {
            int numbs = get_int("How many numbers are you averaging (up to 10): ");
            float average = averaging(numbs);
        }
        if (strcasecmp(type, "square root") == 0)
        {
            int number = get_int("Find the square root of: ");
            float sqroot = root(number);
        }
        redo = get_char("Would you like to do another problem? (y or n): ");
    }
    while (redo == 'y');
}


float sum(int numbers)  //input is the amount of numbers they want
{
    float total = 0;
    //they want the sum, take the amount of integers, prompt that many times
    {
        for (int i = 0; i < numbers; i++)
        {
            points[i] = get_float("Integer: ");
        }
        for (int i = 0; i < numbers; i++)
        {
            total = total + points[i]; //add each to the sum
        }
        printf("Sum of the numbers: %f\n", total);
    }
    return total;
}

float subtraction(float s1, float s2)   //input is the user input numbers
{
    float diff = (s1 - s2);

    printf("Difference of the two integers: %f\n", diff);

    return diff;
}

float multiplication(int factors)   //input is amount of numbers they want
{
    float product = 1;

    for (int i = 0; i < factors; i++)
    {
        points[i] = get_float("Number: ");  //prompt however many times inputted
    }
    for (int i = 0; i < factors; i++)
    {
        product = points[i] * product;  //multiply each into the product; initiated at 1 not 0 to make this work
    }
    printf("Product of the integers: %f\n", product);

    return product;
}

float division(float f1, float f2)  //inputs are the two numbers they r dividing
{
    float quotient = f1 / f2;
    printf("Quotient of the two: %f\n", quotient);
    return quotient;
}

float averaging(int numbs)  //input is the number of numbers they are averaging
{
    float total2 = 0;
    float average = 0;

    for (int i = 0; i < numbs; i++)
    {
        points[i] = get_float("Number: ");  //prompt however many times they input
    }
    for (int i = 0; i < numbs; i++)
    {
        total2 = total2 + points[i];  //find total first with addition, then put total value into average equation
    }
    average = total2 / numbs;
    printf("Average of the numbers: %f\n", average);
    return average;
}

float root(int number)  //input is the number they want the square root of
{
    float sqroot = 0;
    sqroot = sqrt(number);
    printf("Square root of number: %f\n", sqroot);
    return sqroot;
}