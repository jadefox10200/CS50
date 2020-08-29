#include <stdio.h>

void buildHashes(int height);

int main(void){
  //Get int value from user between 1 and 23.
  int height = 23;
  buildHashes(height);
}

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
