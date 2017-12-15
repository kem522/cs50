#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height <= 0 || height > 23);

     for (int i = 0; i < height; i++ )
    {
        for (int space = 0; space < height - i - 1 ; space++)
        {
            printf(" ");
        }
        for (int hash = 0; hash < i + 1; hash++)
        {
            printf("#");
        }
        printf("  ");

        for (int hash = 0; hash < i + 1; hash++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}

