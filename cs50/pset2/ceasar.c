#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  if (argc == 2){
    int key = atoi(argv[1]);

    char inputString[] = "Be sure to drink your Ovaltine";

    int stringLength = strlen(inputString);

    //Intentionally did not use the cs50 library.
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
  }else{
    return 1;
  }
  return 0;
}

// Or fher gb qevax lbhe Binygvar!
