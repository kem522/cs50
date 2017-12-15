#include <stdio.h>
#include <cs50.h>

int shower(int n);
int bottles(int n);

int main(void)
{
   printf("Minutes: ");
   int mins = get_int();
   int ounces = shower(mins);
   int result = bottles(ounces);
   printf("Bottles: %i\n", result);

}

int shower(int n)
{
    return n * 192;
}

int bottles(int n)
{
    return n / 16;
}