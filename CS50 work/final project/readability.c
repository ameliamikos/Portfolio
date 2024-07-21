#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");


    int letters = 0;    //counter variable for letters
    for (int i = 0; i < strlen(text); i++)  //this loop counts the letters. String = array of characters
    {
        if (isalpha(text[i]))   //if alphabetical character, add to letters variable
        {
            letters++;
        }
    }

    int words = 1;  //counter for words
    for (int i = 0; i < strlen(text); i++)  //one more word than space in a sentence. start at 1 or add later?
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }

    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }

    float L = (100 * letters) / words;

    float S = (100 * sentences) / words;

    float index = (0.0588 * L - 0.296 * S - 15.85);

    int x = round(index);


    if (x >= 1 && x <= 16)
    {
        printf("Grade %d\n", x);    //need to finish, if less than one print special if over 16 print 16+
    }
    else if (x < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (x > 16)
    {
        printf("Grade 16+\n");
    }

}
