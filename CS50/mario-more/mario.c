#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input; // user input
    int space; // gaps towards hashes
    int row; // rows (iterator)
    int col; // columns (iterator)
    do
    {
        input = get_int("Height: "); // user inputs height of the pyramid
    }
    while (!((input <= 8) && (input >= 1))); // input condition, input should be between 1-8, cannot input chars

    for (row = 0; row < input; row++) // iterator for numbers of row according to user input
    {
        for (space = 0; space < input - row - 1; space++) // iterator for number of columns, example: user input is 4 so loop will print spaces untill space < 3 (4 - 0 - 1); it prints 3 spaces
        {
            printf(" ");
        }
        for (col = 0; col <= row; col++) // loop printing first half of hashes
        {
            printf("#");
        }
        printf("  "); // gap between hashes is constant, it can be stored as a string of spaces, which will be printed in each row and each iteration of loop
        for (col = 0; col <= row; col++) // loop printing second half of hasesh
        {
            printf("#");
        }
        printf("\n"); // statement printing new line after whole iteration of loop
    }
}