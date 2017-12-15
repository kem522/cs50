#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2 )
    {
        printf("missing command-line argument\n");
        return 1;
    }
    //Convert command line input to an int
    int k = atoi(argv[1]);

    //Ask user for text input to be encrypted
    printf("plaintext: ");
    string s = get_string();
    int n = strlen(s);

    //Loop through the letters in the input
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        //check for lowercase and add key
        if (isalpha(s[i]) && islower(s[i]))
        {
            s[i] = (((int) s[i] - 'a') + k) % 26;
            s[i] = s[i] + 'a';
            printf("%c", (char) s[i]);

       //check for uppercase and add key
        } else if (isalpha(s[i]) && isupper(s[i]))
        {
            s[i] = (((int) s[i] - 'A') + k) % 26;
            s[i] = s[i] + 'A';
            printf("%c", (char) s[i]);
        }
    }
    printf("\n");
    return 0;
}


