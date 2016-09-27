/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bmp.h"

bool checkInt(char* n);

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }else if(!checkInt(argv[1])){
        printf("Please use a value of 1 - 100\n");
        return 1;
    }

    // remember filenames
    int factor = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    fseek(inptr, 0, SEEK_SET);
    

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // read infile's BITMAPFILEHEADER to a new file
    BITMAPFILEHEADER bfNew;
    fread(&bfNew, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER biNew;
    fread(&biNew, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // determine new file padding
    
    
    //update variables for new BITMAPFILEHEADER & BITMAPINFOHEADER:
    biNew.biHeight = bi.biHeight * factor;
    biNew.biWidth = bi.biWidth * factor;
    int newPadding = (4 - (biNew.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    biNew.biSizeImage = (biNew.biWidth * sizeof(RGBTRIPLE) + newPadding) * abs(biNew.biHeight);
    bfNew.bfSize = biNew.biSizeImage + bf.bfOffBits;

    // write outfile's BITMAPFILEHEADER
    fwrite(&bfNew, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&biNew, sizeof(BITMAPINFOHEADER), 1, outptr);

    //create an array for each row to then write out <factor> times:
    RGBTRIPLE* dataRow = malloc(biNew.biWidth);
    // int RGBTRIPLE l_matrix[factor][bi.biWidth];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++){
        
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++){
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            // put the data into an array 
            dataRow[j] = triple;
            
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        //implement multiple writes
        for (int l = 0; l < factor; l++){
            // write out a line of data into the outptr file
            for (int m = 0; m < bi.biWidth; m++){
                //for every 
                for (int k = 0; k< factor; k++){
                    fwrite(&dataRow[m], sizeof(RGBTRIPLE), 1, outptr);        
                }
            
            }
            // add padding if needed:
            for (int n = 0; n < newPadding; n++)
            {
                fputc(0x00, outptr);
            } 
        }
        
    }
    
    free(dataRow);

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}

bool checkInt(char* n){
    int check = atoi(n);
    if (check < 1 || check > 100){
        return false;
    }
    return true;
}
