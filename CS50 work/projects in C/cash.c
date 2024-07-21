#include <stdio.h>
#include <cs50.h>
#include <math.h>

int make_change(int x);

int main(void)
{
    float c;
    do
    {
        c = get_float("Change owed: "); //gets change owed
    }
    while (c <= 0);

    int a = round(c * 100);  //changes float to an integer

    a = make_change(a);

    printf("%d\n", a);  //prints value of n (number of coins)
}

int make_change(int x)
{
    int n = 0;  //int n is the counter for number of coins

    while (x >= 25) //this will subtract 25 until amount owed is <25
    {
        x = (x - 25);
        (n++);   //everytime loop runs (a new coin added), n will increase by 1
    }

    while (x >= 10) //this will subtract 10 until amount is <10
    {
        x = (x - 10);
        (n++);
    }

    while (x >= 5)
    {
        x = (x - 5);    //same process but for nickels
        (n++);
    }

    while (x > 0)
    {
        x = (x - 1);    //same process for pennies
        (n++);
    }

    return n;

}