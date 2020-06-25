/*
 
CS50's Pset 4 - Recover
by Pedro Moura

*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

bool jpeg_check(unsigned char bytes[]);

int main(int argc, char *argv[])
{
    // Checks usage.
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Opens File.
    FILE *card = fopen(argv[1], "r");

    // Checks the user "card" input.
    if (card == NULL)
    {
        printf("File not found.");
    }

    // Creates a buffer.
    unsigned char bytes[BLOCK_SIZE];

    // Checks if found a jpeg file.
    bool found = false;

    // Counts files.
    int count = 0;

    // Creates a new file where will save the recovered stuff
    FILE *recover_file = NULL;

    // Reads the memory card’s bytes.
    while (fread(bytes, BLOCK_SIZE, 1, card) == 1)
    {
        // Checks for a jpeg file.
        if (jpeg_check(bytes))
        {
            if (found == true)
            {
                fclose(recover_file);
            }

            else
            {
                found = true;
            }

            // Creates filenames.
            char filename[8];

            // Names the file.
            sprintf(filename, "%03d.jpg", count);

            // Opens the new file.
            recover_file = fopen(filename, "a");
            count++;
        }

        if (found == 1)
        {
            fwrite(&bytes, BLOCK_SIZE, 1, recover_file);
        }
    }

    // Closes both files
    fclose(card);
    fclose(recover_file);

    return 0;
}

// Check first four bytes
bool jpeg_check(unsigned char bytes[])
{
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
    {
        return true;
    }

    else
    {
        return false;
    }
}
