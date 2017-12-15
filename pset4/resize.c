/**
 * Copies a BMP piece by piece, just because.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);


    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf, bfnew;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    bfnew = bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi, binew;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    binew = bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //Set up all new heading and padding variables
     binew.biWidth = bi.biWidth * n;
     binew.biHeight = bi.biHeight * n;
     int newpadding = (4 - (binew.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
     binew.biSizeImage = ((sizeof(RGBTRIPLE) * binew.biWidth) + newpadding) * abs(binew.biHeight);
     bfnew.bfSize = bf.bfSize - bi.biSizeImage + binew.biSizeImage;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfnew, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&binew, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // iterate over infile's scanlines
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {
            for (int z = 0; z < n; z++) {
                // iterate over pixels in scanline
                for (int j = 0; j < bi.biWidth; j++)
                {
                    // temporary storage
                    RGBTRIPLE triple;

                    // read RGB triple from infile
                    fread(&triple, sizeof(RGBTRIPLE), 1, inptr);


                    // write RGB triple to outfile
                    for (int y = 0; y < n; y++) {
                        fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    }
                }

                // then add it back (to demonstrate how)
                for (int k = 0; k < newpadding; k++)
                {
                    fputc(0x00, outptr);
                }

                if (z < n - 1) {
                fseek(inptr, -bi.biWidth*sizeof(RGBTRIPLE), SEEK_CUR);
                }

            }

            fseek(inptr, padding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
