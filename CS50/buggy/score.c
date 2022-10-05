#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = get_int("How many scores? ");

    int score[n];

    for (int i = 0; i < n; i++)
    {
        score[i] = get_int("Score: ");
    }

    printf("Average: %d\n", (score[0] + score[1] + score[2]) / n);
}