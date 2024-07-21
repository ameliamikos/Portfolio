#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

//what it do: print out one math fact at a time for the user to solve (choose from add, sub, mult, div?)
//Command line: mathf.c operation
//read file for the correct kind of fact
//print out a random line from file (need to figure out how to do this? can I do this?)
//how do I seperate solutions in file? How do I make it check answers?
//verify solution (do math itself or store solution in file?)
//print out correct or incorrect and end program

int main (int argc, string argv[])
{
    //verify command line arguments are correct

    if (argc != 3)
    {
        printf("Usage: mathf Operation Number 0-9\n");
        return 1;
    }
    //argv[1] is the operation of problems they want

    string operation = argv[1];

    string number = argv[2];

    #define SIZE 60

    //if user inputs addition, open and read addition file


    if (strcasecmp(operation, "Addition") == 0)
    {
        FILE *ptr = fopen("Addition.txt", "r");     // open file with facts

        // if the file doesn't exist, (the file pointer is NULL) print an error message and return

        if (ptr == NULL)
        {
            printf("Error opening file!\n");
            return 1;
        }

        if (ptr != NULL)
        {
            printf("File open as fuck\n");
        }

        // only one line read and printed --- how tf!!!

        // print the result

        char line[60];

        while (fgets(line, SIZE, ptr) != NULL)
        printf(" %s ", number);
        fclose(ptr);
        return 0;


    }



    if (strcmp(operation, "Subtraction") == 0)
    {
    printf("hi ther\n");
    }

    if (strcmp(number, "1") == 0)
    {
        printf("ayo\n");
    }



    if (strcmp(operation, "Multiplication") == 0)
    {

    }



    if (strcmp(operation, "Division") == 0)
    {

    }
}
