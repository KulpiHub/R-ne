#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    // argument check
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
    }

    // open file from the arg
    FILE *file = fopen(argv[1], "r");

    // check if file is provided
    if (!file)
    {
        return 1;
    }

    // variable initialization
    BYTE bytes[512];
    FILE *output = NULL;

    int count = 0;
    char *jpgName = malloc(1 / 64 * sizeof(BYTE));

    // loop to find jpegs in memory, name and create new files
    while (fread(bytes, sizeof(char), 512, file))
    {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
        {
            sprintf(jpgName, "%03i.jpg", count);

            output = fopen(jpgName, "w");

            count++;
        }
        if (output != NULL)
        {
            fwrite(bytes, sizeof(char), 512, output);
        }
    }

    // memory dump. closing files
    free(jpgName);
    fclose(file);
    fclose(output);

    return 0;
}