#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: /caesar key\n");
        return 1;
    }
    //else if(isalpha(argv[1]))   //reject
    //{
    //    printf("Usage: ./Caesar Key\n");
    //    return 2;
    //}


    int k = atoi(argv[1]);  //convert CLI to an int k (k for key)


    string text = get_string("Plain text: ");   //get plain text input from the user

    int n = strlen(text);

    printf("ciphertext: ");
    for (int i = 0; i < n; i++)  //need to check every character is it alphabetical. Use for loop?
    {
        if ((text[i]) >= 65 && text[i] <= 90)  //if its upper case, this keeps it uppercase
        {
            printf("%c", ((text[i] + k - 65) % 26) + 65);
        }
        else if ((text[i]) >= 97 && text[i] <= 122) //if lowercase this keeps it lowercase
        {
            printf("%c", ((text[i] + k - 97) % 26) + 97);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
    return 0;
}
