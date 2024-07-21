#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Improper usage: ./recover image");
        return 1;
    }

    //open file
    FILE *infile = fopen(argv[1], "r");
    //if file dont open
    if (infile == NULL)
    {
        printf("error opening file. enter valid file name\n");
    }

    //counts
    int jpegcount = 0;
    int filecount = 0;

    //buffer w 512 bytes
    unsigned char buffer[512];

    //file for images
    FILE *outfile = NULL;

    // setting tha filename
    char filename[8];

    while (fread(buffer, 512, 1, infile) == 1) // data, size, qty, file
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpegcount == 1) // if u already opened a jpeg byte then close it
            {
                fclose(outfile);
            }
            else // if not then you found a jpeg so increment counter
            {
                jpegcount = 1;
            }

            sprintf(filename, "%03i.jpg", filecount);

            outfile = fopen(filename, "w");

            filecount++;
        }
        if (jpegcount == 1)
        {
            fwrite(buffer, 512, 1, outfile);
        }
    }
    fclose(infile);
    fclose(outfile);

    return 0;
}