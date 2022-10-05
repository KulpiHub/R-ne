#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string str);

char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2) // argument number check
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    if (!only_digits(argv[1])) // checking if input contains only digits using function
    {
        printf("Usage ./caesar key\n");
        return 1;
    }

    int keyInput = atoi(argv[1]) % 26; // string to int conversion

    string mainText = get_string("plaintext: "); // text input

    printf("ciphertext: ");

    for (int i = 0; i < strlen(mainText); i++) // rotating each charachter of input using rotate funcion
    {
        char c = rotate(mainText[i], keyInput);
        printf("%c", c);
    }
    printf("\n");
}

bool only_digits(string str) //function checking if string contains only digits
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n) // rotating each character using key passed in argument
{
    if (isupper(c))
    {
        c = ((c - 65 + n) % 26) + 65;
        return c;
    }
    else if (islower(c))
    {
        c = ((c - 97 + n) % 26) + 97;
        return c;
    }
    else
    {
        return c;
    }
}