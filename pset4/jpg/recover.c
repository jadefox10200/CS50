/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef uint8_t BYTE;

//SET VARIABLES
bool fileFound = false;
char fileName[8];
int nameCounter = 0;
unsigned char buffer[512];

int main(int argc, char* argv[])
{
    
    // PREPARE FILES
    FILE* file = fopen("card.raw", "r");
    FILE* outptr = NULL;
    
    //REPEAT UNTIL END OF CARD
    //READ 512 BYTES INTO A BUFFER
    while(fread(&buffer, sizeof(buffer), 1, file) == 1){
        //START OF NEW JPEG?
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && buffer[3] >= 0xe0 && buffer[3] <= 0xef){
            //YES
            if (fileFound == true){
                fclose(outptr);
            }
            fileFound = true;
            sprintf(fileName, "%03d.jpg", nameCounter);
            
            outptr = fopen(fileName, "w");
            //WRITE THE CONTENTS OF THE BUFFER TO THE FILE. 
            fwrite(&buffer, sizeof(buffer), 1, outptr);
            nameCounter++;
            
            //ALREADY FOUND A JPEG
            //NO
            //YES
        } else {
            //NO
            if (fileFound == true){
                fwrite(&buffer, sizeof(buffer), 1, outptr);
            }else{
                continue;
            }
            //ALREADY FOUND A JPEG
            //NO
            //YES
        }
    }
    fclose(outptr);
    fclose(file);
    //CLOSE ANY REMAINING FILES    
}
