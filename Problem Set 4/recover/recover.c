#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc < 1)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    char *infile = argv[1];

    FILE *raw_file = fopen(infile, "rb");
    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    char z = '0';
    int img = 0;
    char *name = malloc(8);

    int stflag = 0;
    BYTE buffer[BLOCK_SIZE];
    FILE *outptr;
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255 && buffer[3] >= 224 && buffer[3] <= 239)
        {

            if (stflag == 1)
            {
                fclose(outptr);
                img++;
            }

            if (img < 10)
            {
                sprintf(name, "%c%c%i.jpg", z, z, img);
            }
            else if (img < 100)
            {
                sprintf(name, "%c%i.jpg", z, img);
            }
            else if (img < 1000)
            {
                sprintf(name, "%i.jpg", img);
            }

            outptr = fopen(name, "wb");
            if (outptr == NULL)
            {
                printf("Could not open %s.\n", name);
                fclose(raw_file);
                return 1;
            }
            stflag = 1;
        }

        if (stflag == 1)
        {
            fwrite(buffer, 1, BLOCK_SIZE, outptr);
        }
    }

    fclose(raw_file);
    fclose(outptr);
    free(name);

    return 0;
}
