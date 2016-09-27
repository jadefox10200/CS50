#include <cs50.h>
#include <stdio.h>

void buildHashes(int height);

int main(void){
    //Get int value from user between 1 and 23.
    int height = 0;
    do
    {
        printf("Height:");
        height = GetInt();
    
    }while(height < 0 || height > 23);
    
    buildHashes(height);
}

//Build the half-pyramid with a function:
void buildHashes(int height){
    for (int i = 0; i < height; i++){
        int hashes = i + 2;
        int whiteSpace = height - hashes + 1;
        while (whiteSpace > 0){
            printf(" ");
            whiteSpace--;
        }
        while (hashes > 0){
            printf("#");
            hashes--;
        }
        printf("\n");
    }
}
