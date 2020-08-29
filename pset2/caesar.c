#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int main(int argc, char const *argv[]) {
  if (argc == 2){
    int key = atoi(argv[1]);
    if (key > 26){
        key = key % 26;
    }
    
    char* inputString = GetString();

    int stringLength = strlen(inputString);
    for (int i = 0; i < stringLength; i++){
        if (inputString[i] >= 'a' && inputString[i] <= 'z'){
            inputString[i] = ((inputString[i] - 97) + key);
            if (inputString[i] >= 26){
               inputString[i] -= 26;
            }
            inputString[i] += 97;
            printf("%c", inputString[i]);
        }else if (inputString[i] >= 'A' && inputString[i] <= 'Z'){
            inputString[i] = ((inputString[i] - 65) + key);
            if (inputString[i] >= 26){
              inputString[i] -= 26;
            }
            inputString[i] += 65;
            printf("%c", inputString[i]);
        }else{
            printf("%c", inputString[i]);
        }
    }
    printf("\n");
  }else{
    printf("You must enter one int value\n");
    return 1;
  }
  return 0;
}
