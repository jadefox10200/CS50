#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    char bacon[] = "bacon";
    int key = 13;

    char inputString[] = "Meet me at the park at eleven am";

    int stringLength = strlen(inputString);
    int keyLength = strlen(bacon);
    int counter = 0;

    //Intentionally did not use the cs50 library.
    for (int i = 0; i < stringLength; i++){
      if (inputString[i] >= 'a' && inputString[i] <= 'z'){
        int keyWordIndex = counter % keyLength;
        char thisChar = bacon[keyWordIndex] - 97;
        // printf("%c\n", thisChar);
        inputString[i] = ((inputString[i] - 97) + thisChar);
        if (inputString[i] >= 26){
          inputString[i] -= 26;
        }
        inputString[i] += 97;
        printf("%c", inputString[i]);
        // printf("%c is index %d\n", bacon[keyWordIndex], keyWordIndex);
        counter++;
      }else if (inputString[i] >= 'A' && inputString[i] <= 'Z'){
        int keyWordIndex = counter % keyLength;
        char thisChar = bacon[keyWordIndex] - 97;
        printf("%c\n", thisChar);
        inputString[i] = ((inputString[i] - 65) + thisChar);
        if (inputString[i] >= 26){
          inputString[i] -= 26;
        }
        inputString[i] += 65;
        printf("%c", inputString[i]);
        // printf("%c is index %d\n", bacon[keyWordIndex], keyWordIndex);
        counter++;
      }else{
        printf("%c", inputString[i]);
      }
    }
  return 0;
}

// Negh zf av huf pcfx bt gzrwep oz
