#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char caesar(char c, int key);

int main(int argc, string argv[])
{

    //check there are enough command line arguments
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }

    //check key string to make sure they are all letters
    int keylength = strlen(argv[1]);
   for (int i = 0; i < keylength; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("missing command-line argument\n");
            return 1;

        }
    }

    //Ask user for text input to be encrypted
    printf("plaintext: ");
    string s = get_string();
    int string_length = strlen(s);


    int j = 0;
    int length_key = strlen(argv[1]);


    //Loop through the letters in the input
    printf("ciphertext: ");
    for (int i = 0; i < string_length; i++)
    {
        if (isalpha(s[i]) == 0)
        {
            printf("%c", s[i]);
        }

        printf("%c", caesar(s[i], argv[1][j]));

        if (j < length_key - 1)
        {
            j++;
        } else
        {
            j = 0;
        }
    }
    printf("\n");
    return 0;
}


char caesar(char c, int key)
{
    if (isupper(c) && isupper (key))
    {
        return ((((int) c - 'A') + (key - 'A')) % 26) + 'A';

    }
    if (islower(c) && islower(key))
    {
         return ((((int) c - 'a') + (key - 'a')) % 26) + 'a';

    }
    if (islower(c) && isupper(key))
    {
        return ((((int)c - 'a') + (key - 'A')) % 26) + 'a';

    }
    if (isupper(c) && islower(key))
    {
        return ((((int)c - 'A') + (key - 'a')) % 26) +'A';
    } else
    {
        return 1;
    }
}