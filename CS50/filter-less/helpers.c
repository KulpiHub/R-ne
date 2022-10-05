#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float rgbtAvg;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            rgbtAvg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.00);

            image[i][j].rgbtRed = rgbtAvg;
            image[i][j].rgbtGreen = rgbtAvg;
            image[i][j].rgbtBlue = rgbtAvg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int tmp[3];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            tmp[0] = image[i][j].rgbtRed;
            tmp[1] = image[i][j].rgbtGreen;
            tmp[2] = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = tmp[0];
            image[i][width - j - 1].rgbtGreen = tmp[1];
            image[i][width - j - 1].rgbtBlue = tmp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE ori[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            ori[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((ori[i][j].rgbtRed + ori[i + 1][j].rgbtRed + ori[i][j + 1].rgbtRed + ori[i + 1][j + 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((ori[i][j].rgbtGreen + ori[i + 1][j].rgbtGreen + ori[i][j + 1].rgbtGreen + ori[i + 1][j +
                                                   1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((ori[i][j].rgbtBlue + ori[i + 1][j].rgbtBlue + ori[i][j + 1].rgbtBlue + ori[i + 1][j + 1].rgbtBlue) /
                                                 4.0);
                }
                else if (j > 0 && j < width - 1)
                {
                    image[i][j].rgbtRed = round((ori[i][j].rgbtRed + ori[i][j - 1].rgbtRed + ori[i + 1][j - 1].rgbtRed + ori[i + 1][j].rgbtRed +
                                                    ori[i][j + 1].rgbtRed + ori[i + 1][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((ori[i][j].rgbtGreen + ori[i][j - 1].rgbtGreen + ori[i + 1][j - 1].rgbtGreen + ori[i + 1][j].rgbtGreen
                                                    + ori[i][j + 1].rgbtGreen + ori[i + 1][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((ori[i][j].rgbtBlue + ori[i][j - 1].rgbtBlue + ori[i + 1][j - 1].rgbtBlue + ori[i + 1][j].rgbtBlue
                                                    + ori[i][j + 1].rgbtBlue + ori[i + 1][j + 1].rgbtBlue) / 6.0);
                }
                else
                {
                    image[i][j].rgbtRed = round((ori[i][j].rgbtRed + ori[i][j - 1].rgbtRed + ori[i + 1][j - 1].rgbtRed + ori[i + 1][j].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((ori[i][j].rgbtGreen + ori[i][j - 1].rgbtGreen + ori[i + 1][j - 1].rgbtGreen + ori[i + 1][j].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((ori[i][j].rgbtBlue + ori[i][j - 1].rgbtBlue + ori[i + 1][j - 1].rgbtBlue + ori[i + 1][j].rgbtBlue) / 4.0);
                }
            }
            else if (i > 0 && i < height - 1)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((ori[i][j].rgbtRed + ori[i - 1][j].rgbtRed + ori[i - 1][j + 1].rgbtRed + ori[i][j + 1].rgbtRed + ori[i + 1][j + 1].rgbtRed + ori[i + 1][j].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((ori[i][j].rgbtGreen + ori[i - 1][j].rgbtGreen + ori[i - 1][j + 1].rgbtGreen + ori[i][j + 1].rgbtGreen + ori[i + 1][j + 1].rgbtGreen + ori[i + 1][j].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((ori[i][j].rgbtBlue + ori[i - 1][j].rgbtBlue + ori[i - 1][j + 1].rgbtBlue + ori[i][j + 1].rgbtBlue + ori[i + 1][j + 1].rgbtBlue + ori[i + 1][j].rgbtBlue) / 6.0);
                }
                else if (j > 0 && j < width - 1)
                {
                    image[i][j].rgbtRed = round((ori[i][j].rgbtRed + ori[i][j - 1].rgbtRed + ori[i][j + 1].rgbtRed + ori[i - 1][j].rgbtRed + ori[i + 1][j].rgbtRed + ori[i - 1][j - 1].rgbtRed + ori[i + 1][j - 1].rgbtRed + ori[i - 1][j + 1].rgbtRed + ori[i + 1][j + 1].rgbtRed) / 9.0);
                    image[i][j].rgbtGreen = round((ori[i][j].rgbtGreen + ori[i][j - 1].rgbtGreen + ori[i][j + 1].rgbtGreen + ori[i - 1][j].rgbtGreen + ori[i + 1][j].rgbtGreen + ori[i - 1][j - 1].rgbtGreen + ori[i + 1][j - 1].rgbtGreen + ori[i - 1][j + 1].rgbtGreen + ori[i + 1][j + 1].rgbtGreen) / 9.0);
                    image[i][j].rgbtBlue = round((ori[i][j].rgbtBlue + ori[i][j - 1].rgbtBlue + ori[i][j + 1].rgbtBlue + ori[i - 1][j].rgbtBlue + ori[i + 1][j].rgbtBlue + ori[i - 1][j - 1].rgbtBlue + ori[i + 1][j - 1].rgbtBlue + ori[i - 1][j + 1].rgbtBlue + ori[i + 1][j + 1].rgbtBlue) / 9.0);
                }
                else
                {
                    image[i][j].rgbtRed = round((ori[i][j].rgbtRed + ori[i - 1][j].rgbtRed + ori[i - 1][j - 1].rgbtRed + ori[i][j - 1].rgbtRed + ori[i + 1][j - 1].rgbtRed + ori[i + 1][j].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((ori[i][j].rgbtGreen + ori[i - 1][j].rgbtGreen + ori[i - 1][j - 1].rgbtGreen + ori[i][j - 1].rgbtGreen + ori[i + 1][j - 1].rgbtGreen + ori[i + 1][j].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((ori[i][j].rgbtBlue + ori[i - 1][j].rgbtBlue + ori[i - 1][j - 1].rgbtBlue + ori[i][j - 1].rgbtBlue + ori[i + 1][j - 1].rgbtBlue + ori[i + 1][j].rgbtBlue) / 6.0);
                }
            }
            else if (i == height - 1)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((ori[i][j].rgbtRed + ori[i - 1][j].rgbtRed + ori[i - 1][j + 1].rgbtRed + ori[i][j + 1].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((ori[i][j].rgbtGreen + ori[i - 1][j].rgbtGreen + ori[i - 1][j + 1].rgbtGreen + ori[i][j + 1].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((ori[i][j].rgbtBlue + ori[i - 1][j].rgbtBlue + ori[i - 1][j + 1].rgbtBlue + ori[i][j + 1].rgbtBlue) / 4.0);
                }
                else if (j > 0 && j < width - 1)
                {
                    image[i][j].rgbtRed = round((ori[i][j].rgbtRed + ori[i][j - 1].rgbtRed + ori[i - 1][j - 1].rgbtRed + ori[i - 1][j].rgbtRed + ori[i - 1][j + 1].rgbtRed + ori[i][j + 1].rgbtRed) / 6.0);
                    image[i][j].rgbtGreen = round((ori[i][j].rgbtGreen + ori[i][j - 1].rgbtGreen + ori[i - 1][j - 1].rgbtGreen + ori[i - 1][j].rgbtGreen + ori[i - 1][j + 1].rgbtGreen + ori[i][j + 1].rgbtGreen) / 6.0);
                    image[i][j].rgbtBlue = round((ori[i][j].rgbtBlue + ori[i][j - 1].rgbtBlue + ori[i - 1][j - 1].rgbtBlue + ori[i - 1][j].rgbtBlue + ori[i - 1][j + 1].rgbtBlue + ori[i][j + 1].rgbtBlue) / 6.0);
                }
                else
                {
                    image[i][j].rgbtRed = round((ori[i][j].rgbtRed + ori[i][j - 1].rgbtRed + ori[i - 1][j - 1].rgbtRed + ori[i - 1][j].rgbtRed) / 4.0);
                    image[i][j].rgbtGreen = round((ori[i][j].rgbtGreen + ori[i][j - 1].rgbtGreen + ori[i - 1][j - 1].rgbtGreen + ori[i - 1][j].rgbtGreen) / 4.0);
                    image[i][j].rgbtBlue = round((ori[i][j].rgbtBlue + ori[i][j - 1].rgbtBlue + ori[i - 1][j - 1].rgbtBlue + ori[i - 1][j].rgbtBlue) / 4.0);
                }
            }
        }
    }
    return;
}