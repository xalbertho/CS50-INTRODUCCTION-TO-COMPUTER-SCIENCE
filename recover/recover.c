#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open the forensic image
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];
    int jpeg_count = 0;
    FILE *output = NULL;
    char filename[8];

    // Read the blocks
    while (fread(buffer, 1, BLOCK_SIZE, input) == BLOCK_SIZE)
    {
        // Check if it's the start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous file if open
            if (output != NULL)
            {
                fclose(output);
            }

            // Create a new JPEG file
            sprintf(filename, "%03d.jpg", jpeg_count);
            output = fopen(filename, "w");
            if (output == NULL)
            {
                fclose(input);
                fprintf(stderr, "Could not create %s.\n", filename);
                return 1;
            }
            jpeg_count++;
        }

        // Write to output file if we've found a JPEG
        if (output != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, output);
        }
    }

    // Close any remaining files
    if (output != NULL)
    {
        fclose(output);
    }
    fclose(input);

    return 0;
}
