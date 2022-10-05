#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double string_length(string str);

double string_end(string str);

double string_space(string str);

int main(void)
{

    string userInput = get_string("Input: ");

    int stringLength = string_length(userInput); // function call

    int sentenceCounter = string_end(userInput); // function call

    int wordsNumber = string_space(userInput); // function call

    double lettersPer100 = string_length(userInput) / string_space(userInput) * 100; // calculating letters per 100 words

    double sentencesPer100 = string_end(userInput) / string_space(userInput) * 100; // calculating sentences per 100 words

    double index = 0.0588 * lettersPer100 - 0.296 * sentencesPer100 - 15.8;

    double roundedNumber = round(index);

    int roundedIndex = (int)roundedNumber;

    if (roundedIndex > 1 && roundedIndex < 16) // grade conditional
    {
        printf("Grade %i\n", roundedIndex);
    }
    else if (roundedIndex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (roundedIndex >= 16)
    {
        printf("Grade 16+\n");
    }
}

double string_length(string str) // letter counter
{
    int letterCounter = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ' && str[i] != ',' && str[i] != ';' && str[i] != '\'' && str[i] != '-' && str[i] != '"' && str[i] != ':'
            && str[i] != '?' && str[i] != '!' && str[i] != '.')
        {
            letterCounter++;
        }
        i++;
    }
    return letterCounter;
}


double string_end(string str) // sentence counter
{
    int sentenceCounter = 0;
    int j = 0;
    while (str[j] != '\0')
    {
        if (str[j] == '.' || str[j] == '?' || str[j] == '!')
        {
            sentenceCounter++;
        }
        j++;
    }
    return sentenceCounter;
}

double string_space(string str) // word counter
{
    int wordCounter = 0;
    int k = 0;
    while (str[k] != '\0')
    {
        if (str[k] == ' ' && str[k + 1] != ' ')
        {
            wordCounter++;
        }
        k++;
    }
    return wordCounter + 1;
}