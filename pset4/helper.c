/*
 
CS50's Pset 4 - Filter(Less)
by Pedro Moura

*/

#include "helpers.h"
#include <math.h>
#include <stdio.h>

#define PIXEL_RED image[y][x].rgbtRed
#define PIXEL_GREEN image[y][x].rgbtGreen
#define PIXEL_BLUE image[y][x].rgbtBlue

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avarage;
    
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            avarage = round((PIXEL_RED + PIXEL_GREEN + PIXEL_BLUE) / 3.0);
            
            PIXEL_RED = avarage;
            PIXEL_GREEN = avarage;
            PIXEL_BLUE = avarage;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int sepiaRed = round(.393 * PIXEL_RED + .769 * PIXEL_GREEN + .189 * PIXEL_BLUE);
            int sepiaGreen = round(.349 * PIXEL_RED + .686 * PIXEL_GREEN + .168 * PIXEL_BLUE);
            int sepiaBlue = round(.272 * PIXEL_RED + .534 * PIXEL_GREEN + .131 * PIXEL_BLUE);
            
            sepiaRed = check(sepiaRed);
            sepiaGreen = check(sepiaGreen);
            sepiaBlue = check(sepiaBlue);
            
            PIXEL_RED = sepiaRed;
            PIXEL_GREEN = sepiaGreen;
            PIXEL_BLUE = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width / 2; x++)
        {
            // save old pixel values.
            int old_red = PIXEL_RED;
            int old_green = PIXEL_GREEN;
            int old_blue = PIXEL_BLUE;
           
            PIXEL_RED = image[y][(width - x) - 1].rgbtRed;
            PIXEL_GREEN = image[y][(width - x) - 1].rgbtGreen;
            PIXEL_BLUE = image[y][(width - x) - 1].rgbtBlue;
            
            image[y][(width - x) - 1].rgbtRed = old_red;
            image[y][(width - x) - 1].rgbtGreen = old_green;
            image[y][(width - x) - 1].rgbtBlue = old_blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE cp_image[height][width];

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < height; x++)
        {
            cp_image[y][x] = image[y][x];
        }
    }

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < height; x++)
        {
            if (y == 0 && x == 0)
            {
                PIXEL_RED = round((cp_image[y][x].rgbtRed + cp_image[y + 1][x].rgbtRed
                                             + cp_image[y][x + 1].rgbtRed + cp_image[y + 1][x + 1].rgbtRed) / 4.0);

                PIXEL_GREEN = round((cp_image[y][x].rgbtGreen + cp_image[y + 1][x].rgbtGreen
                                               + cp_image[y][x + 1].rgbtGreen + cp_image[y + 1][x + 1].rgbtGreen) / 4.0);

                PIXEL_BLUE = round((cp_image[y][x].rgbtBlue + cp_image[y + 1][x].rgbtBlue
                                              + cp_image[y][x + 1].rgbtBlue + cp_image[y + 1][x + 1].rgbtBlue) / 4.0);
            }
            
            else if (y == 0 && x == (width - 1))
            {
                PIXEL_RED = round((cp_image[y][x].rgbtRed + cp_image[y + 1][x].rgbtRed
                                             + cp_image[y][x - 1].rgbtRed + cp_image[y + 1][x - 1].rgbtRed) / 4.0);

                PIXEL_GREEN = round((cp_image[y][x].rgbtGreen + cp_image[y + 1][x].rgbtGreen
                                               + cp_image[y][x - 1].rgbtGreen + cp_image[y + 1][x - 1].rgbtGreen) / 4.0);

                PIXEL_BLUE = round((cp_image[y][x].rgbtBlue + cp_image[y + 1][x].rgbtBlue
                                              + cp_image[y][x - 1].rgbtBlue + cp_image[y + 1][x - 1].rgbtBlue) / 4.0);
            }
            
            else if (y == 0)
            {
                PIXEL_RED = round((cp_image[y][x].rgbtRed + cp_image[y][x - 1].rgbtRed + cp_image[y][x + 1].rgbtRed
                                             + cp_image[y + 1][x].rgbtRed + cp_image[y + 1][x - 1].rgbtRed + cp_image[y + 1][x + 1].rgbtRed) / 6.0);

                PIXEL_GREEN = round((cp_image[y][x].rgbtGreen + cp_image[y][x - 1].rgbtGreen + cp_image[y][x + 1].rgbtGreen
                                               + cp_image[y + 1][x].rgbtGreen + cp_image[y + 1][x - 1].rgbtGreen + cp_image[y + 1][x + 1].rgbtGreen) / 6.0);

                PIXEL_BLUE = round((cp_image[y][x].rgbtBlue + cp_image[y][x - 1].rgbtBlue + cp_image[y][x + 1].rgbtBlue
                                              + cp_image[y + 1][x].rgbtBlue + cp_image[y + 1][x - 1].rgbtBlue + cp_image[y + 1][x + 1].rgbtBlue) / 6.0);
            }
            
            else if (y == (height - 1) && x == 0)
            {
                PIXEL_RED = round((cp_image[y][x].rgbtRed + cp_image[y - 1][x].rgbtRed
                                             + cp_image[y][x + 1].rgbtRed + cp_image[y - 1][x + 1].rgbtRed) / 4.0);

                PIXEL_GREEN = round((cp_image[y][x].rgbtGreen + cp_image[y - 1][x].rgbtGreen
                                               + cp_image[y][x + 1].rgbtGreen + cp_image[y - 1][x + 1].rgbtGreen) / 4.0);

                PIXEL_BLUE = round((cp_image[y][x].rgbtBlue + cp_image[y - 1][x].rgbtBlue
                                              + cp_image[y][x + 1].rgbtBlue + cp_image[y - 1][x + 1].rgbtBlue) / 4.0);
            }
            
            else if (x == 0)
            {
                PIXEL_RED = round((cp_image[y][x].rgbtRed + cp_image[y - 1][x].rgbtRed + cp_image[y + 1][x].rgbtRed
                                             + cp_image[y][x + 1].rgbtRed + cp_image[y - 1][x + 1].rgbtRed + cp_image[y + 1][x + 1].rgbtRed) / 6.0);

                PIXEL_GREEN = round((cp_image[y][x].rgbtGreen + cp_image[y - 1][x].rgbtGreen + cp_image[y + 1][x].rgbtGreen
                                               + cp_image[y][x + 1].rgbtGreen + cp_image[y - 1][x + 1].rgbtGreen + cp_image[y + 1][x + 1].rgbtGreen) / 6.0);

                PIXEL_BLUE = round((cp_image[y][x].rgbtBlue + cp_image[y - 1][x].rgbtBlue + cp_image[y + 1][x].rgbtBlue
                                              + cp_image[y][x + 1].rgbtBlue + cp_image[y - 1][x + 1].rgbtBlue + cp_image[y + 1][x + 1].rgbtBlue) / 6.0);
            }
            
            else if (y == (height - 1) && x == (width - 1))
            {
                PIXEL_RED = round((cp_image[y][x].rgbtRed + cp_image[y - 1][x].rgbtRed
                                             + cp_image[y][x - 1].rgbtRed + cp_image[y - 1][x - 1].rgbtRed) / 4.0);

                PIXEL_GREEN = round((cp_image[y][x].rgbtGreen + cp_image[y - 1][x].rgbtGreen
                                               + cp_image[y][x - 1].rgbtGreen + cp_image[y - 1][x - 1].rgbtGreen) / 4.0);

                PIXEL_BLUE = round((cp_image[y][x].rgbtBlue + cp_image[y - 1][x].rgbtBlue
                                              + cp_image[y][x - 1].rgbtBlue + cp_image[y - 1][x - 1].rgbtBlue) / 4.0);
            }
            
            else if (y == (height - 1))
            {
                PIXEL_RED = round((cp_image[y][x].rgbtRed + cp_image[y][x - 1].rgbtRed + cp_image[y][x + 1].rgbtRed
                                             + cp_image[y - 1][x].rgbtRed + cp_image[y - 1][x - 1].rgbtRed + cp_image[y - 1][x + 1].rgbtRed) / 6.0);

                PIXEL_GREEN = round((cp_image[y][x].rgbtGreen + cp_image[y][x - 1].rgbtGreen + cp_image[y][x + 1].rgbtGreen
                                               + cp_image[y - 1][x].rgbtGreen + cp_image[y - 1][x - 1].rgbtGreen + cp_image[y - 1][x + 1].rgbtGreen) / 6.0);

                PIXEL_BLUE = round((cp_image[y][x].rgbtBlue + cp_image[y][x - 1].rgbtBlue + cp_image[y][x + 1].rgbtBlue
                                              + cp_image[y - 1][x].rgbtBlue + cp_image[y - 1][x - 1].rgbtBlue + cp_image[y - 1][x + 1].rgbtBlue) / 6.0);
            }
            
            else if (x == (width - 1))
            {
                PIXEL_RED = round((cp_image[y][x].rgbtRed + cp_image[y - 1][x].rgbtRed + cp_image[y + 1][x].rgbtRed
                                             + cp_image[y][x - 1].rgbtRed + cp_image[y - 1][x - 1].rgbtRed + cp_image[y + 1][x - 1].rgbtRed) / 6.0);

                PIXEL_GREEN = round((cp_image[y][x].rgbtGreen + cp_image[y - 1][x].rgbtGreen + cp_image[y + 1][x].rgbtGreen
                                               + cp_image[y][x - 1].rgbtGreen + cp_image[y - 1][x - 1].rgbtGreen + cp_image[y + 1][x - 1].rgbtGreen) / 6.0);

                PIXEL_BLUE = round((cp_image[y][x].rgbtBlue + cp_image[y - 1][x].rgbtBlue + cp_image[y + 1][x].rgbtBlue
                                              + cp_image[y][x - 1].rgbtBlue + cp_image[y - 1][x - 1].rgbtBlue + cp_image[y + 1][x - 1].rgbtBlue) / 6.0);
            }
            
            else
            {
                PIXEL_RED = round((cp_image[y][x].rgbtRed + cp_image[y][x - 1].rgbtRed + cp_image[y][x + 1].rgbtRed
                                             + cp_image[y - 1][x].rgbtRed + cp_image[y - 1][x - 1].rgbtRed + cp_image[y - 1][x + 1].rgbtRed
                                             + cp_image[y + 1][x].rgbtRed + cp_image[y + 1][x - 1].rgbtRed + cp_image[y + 1][x + 1].rgbtRed) / 9.0);

                PIXEL_GREEN = round((cp_image[y][x].rgbtGreen + cp_image[y][x - 1].rgbtGreen + cp_image[y][x + 1].rgbtGreen
                                               + cp_image[y - 1][x].rgbtGreen + cp_image[y - 1][x - 1].rgbtGreen + cp_image[y - 1][x + 1].rgbtGreen
                                               + cp_image[y + 1][x].rgbtGreen + cp_image[y + 1][x - 1].rgbtGreen + cp_image[y + 1][x + 1].rgbtGreen) / 9.0);

                PIXEL_BLUE = round((cp_image[y][x].rgbtBlue + cp_image[y][x - 1].rgbtBlue + cp_image[y][x + 1].rgbtBlue
                                              + cp_image[y - 1][x].rgbtBlue + cp_image[y - 1][x - 1].rgbtBlue + cp_image[y - 1][x + 1].rgbtBlue
                                              + cp_image[y + 1][x].rgbtBlue + cp_image[y + 1][x - 1].rgbtBlue + cp_image[y + 1][x + 1].rgbtBlue) / 9.0);
            }
        }
    }
    return 0;
}

int check(int pixel)
{
    if (pixel > 255)
    {
        pixel = 255;
    }
    return pixel;
}
