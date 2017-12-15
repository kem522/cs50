#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr,"Usage: ./recover infile\n");
        return 1;
    }

    //assign file names
    char *infile = argv[1];

     // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    //initialize jpeg count
    int jpg_count = 0;

    //store byte count
    uint8_t buffer[512];

    //create outfile indicator
    FILE *ptr = NULL;
    int open = 0;



    //iterate over bytes
     while (fread(buffer, 512, 1, inptr) > 0 )
     {

        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
            {

             //create filename
            char filename[8];
            sprintf(filename, "%03i.jpg", jpg_count);

            if (open == 0)
            {
                 //alert open jpeg
                 open = 1;

                 //create file to write to
                 ptr = fopen(filename, "w");

                 //write 512 bytes to file
                 fwrite(buffer,sizeof(buffer),1,ptr);
            }

            if (open == 1) {
                //close current file
                fclose(ptr);

                //open a new one to write to
                ptr = fopen(filename, "w");
                fwrite(buffer,sizeof(buffer),1,ptr);
                jpg_count++;
            }


            }

            else
            {
                if (open == 1)
                {
                fwrite(buffer,sizeof(buffer),1,ptr);
                }
            }

     }
     if(ptr) {
         fclose(ptr);
     }

     fclose(inptr);
     return 0;


}