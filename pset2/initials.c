#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string();
    int n = strlen(s);
    if (s[0] != ' ')
    {
        printf("%c", toupper(s[0]));
        for (int i = 0; i < n; i++)
        if (s[i] != ' ' && s[i-1] == ' ')
        {
            printf("%c",toupper(s[i]));
        }
     } else
     {
        for (int i = 0; i < n; i++)
        if (s[i] != ' ' && s[i-1] == ' ')
        {
            printf("%c",toupper(s[i]));
        }
   }
        printf("\n");
}
