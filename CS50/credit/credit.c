#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    int modulo1;
    int modulo2;
    int len = 0;
    int total = 0;
    int checkSum1 = 0;
    int checkSum2 = 0;
    int digit1;
    int digit2;

//input

    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    long num1 = number; // credit card number temp1
    long num2 = number; // credit card number temp2
    long num3 = number; // credit card number temp3

//length of cc number

    while (num3 > 0)
    {
        num3 /= 10;
        len++;
    }

//validity check

    if (len != 13 && len != 15 && len != 16)
    {
        printf("INVALID\n");
        return 0;
    }

// checksum
    do
    {
        modulo1 = num1 % 10;
        num1 /= 10;
        checkSum1 = checkSum1 + modulo1;

        modulo2 = num1 % 10;
        num1 /= 10;

        modulo2 *= 2;
        digit1 = modulo2 % 10;
        digit2 = modulo2 / 10;
        checkSum2 = checkSum2 + digit1 + digit2;
    }
    while (num1 > 0);

    printf("%d\n", checkSum1);
    printf("%d\n", checkSum2);
    printf("%d\n", modulo1);
    printf("%d\n", modulo2);
    printf("%d\n", digit1);
    printf("%d\n", digit2);
    total = checkSum1 + checkSum2;

// Luhn's algo

    if (total % 10 != 0)
    {
        return 0;
    }

// modulo check

    do
    {
        num2 = num2 / 10;
    }
    while (num2 > 100);

// card check

    if ((num2 / 10 == 5) && (0 < num2 % 10 && num2 % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((num2 / 10 == 3) && (num2 % 10 == 4 || num2 % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if ((num2 / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}