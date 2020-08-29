#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


bool validateKey(string key, int len);

int main(int argc, char *argv[]) {
    if (argc != 2){
        printf("You must enter a keyword\n");
        return 1;
    }
    string key = argv[1];
    int keyLength = strlen(key);
    for (int i = 0; i < keyLength; i++){
        key[i] = tolower(key[i]);
    }
    bool valid = validateKey(key, keyLength);
    if (!valid){
        printf("Please enter a keyword as plain text only\n");
        return 1;
    }
    string inputString = GetString();

    int stringLength = strlen(inputString);
    int counter = 0;

    for (int i = 0; i < stringLength; i++){
        if (inputString[i] >= 'a' && inputString[i] <= 'z'){
            int keyWordIndex = counter % keyLength;
            char thisChar = key[keyWordIndex] - 97;
            inputString[i] = ((inputString[i] - 97) + thisChar);
            if (inputString[i] >= 26){
              inputString[i] -= 26;
            }
            inputString[i] += 97;
            printf("%c", inputString[i]);
            counter++;
        }else if (inputString[i] >= 'A' && inputString[i] <= 'Z'){
            int keyWordIndex = counter % keyLength;
            char thisChar = key[keyWordIndex] - 97;
            inputString[i] = ((inputString[i] - 65) + thisChar);
            if (inputString[i] >= 26){
              inputString[i] -= 26;
            }
            inputString[i] += 65;
            printf("%c", inputString[i]);
            counter++;
        }else{
            printf("%c", inputString[i]);
        }
    }
    printf("\n");
    return 0;
}

bool validateKey(string key, int len){
    for (int i = 0; i < len; i++){
        if ((key[i] > 122) || (key[i] < 97 && key[i] > 90) || key[i] < 65){
            return false;
        }
    }
    return true;
}

// Negh zf av huf pcfx bt gzrwep oz
