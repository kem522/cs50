#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define _XOPEN_SOURCE
#include <unistd.h>

char *crypt(const char *key, const char *salt);

int main(int argc, string argv [])
{
    if (argc != 2)
    {
        printf("Error in command line input.\n");
        return 1;
    }

    string hash = argv[1];
    char key[5];
    char salt[3] = "50";
    salt[2] = '\0';
    char letters[] = "\0ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    while (strcmp(hash, crypt(key, salt)) !=0)
    {
        for (int i = 0; i < 52; i++)
        {    key[0] = letters[i];
            for (int j = 0; j < 52; j++)
            {
                key[1] = letters[j];
                for (int k = 0; k < 52; k++)
                {
                    key[2] = letters[k];
                    for (int l = 0; l < 52; l++)
                    {
                        key[3] = letters[l];
                    }

                }
            }
        }
    } printf("%s\n", key);

    return 0;
}
