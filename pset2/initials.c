#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    
    
    char* name = GetString();;
    
    int n = strlen(name);
    printf("%c", toupper(name[0]));
    for (int i = 0; i < n; i++){
        char current = name[i];
        if (isspace(current)){
            printf("%c",toupper(name[i+1]));
        }
    }
    printf("\n");
}