#include <stdio.h>
#include <cs50.h>

int main(void)
{

    printf("Number: ");
    long long cc_number = get_long_long();



    int count=0;
    long long digits = cc_number;
    while (digits > 0)
    {
        digits = digits/10;
        count++;
    }

    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
    }

    //separate the digits
    int number[count];

    for (int i = 0; i < count; i++)
    {
        number[i] = cc_number % 10;
        cc_number = cc_number / 10;
    }

    //SUM 1: add every other number together starting with the last
    int first_sum = 0;

    for (int i = 0; i < count; i += 2)
    {
        first_sum += number[i];
    }

    //double every other number starting with the second to last
    int doublenum[count];

    for (int i = 1; i < count; i += 2)
    {
        doublenum[i] = number[i]*2;
    }

    //SUM 2: split the double numbers and add all the digits together
    int second_sum = 0;
    int split;

    for (int i = 1; i < count; i+= 2)
      {
        split = (doublenum[i] % 10) + (doublenum[i]/10 % 10);
        second_sum += split;
      }

      //add the two sums together
      int final_sum = first_sum + second_sum;


     if (count == 13 && number[12] == 4 && final_sum % 10 == 0)
     {
         printf("VISA\n");
     }

     else if (count == 16 && number[15] == 4 && final_sum % 10 == 0)
     {
         printf("VISA\n");
     }

     else if (count == 16 && number[15] == 5 && final_sum % 10 == 0)
     {
         printf("MASTERCARD\n");
     }

     else if (count == 15 && number[14] == 3 && final_sum % 10 == 0)
     {
         printf("AMEX\n");
     }

     else
     {
         printf("INVALID\n");
     }

     return 0;

}