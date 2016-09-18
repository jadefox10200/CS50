#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  for (int i = 1; i < argc ; i++ ){
    int stringLength = strlen(argv[i]);
    char letter = argv[i][0];
    printf("%c", letter);
    // for (int j = 0; j < stringLength; j++){
    //   if (j == 0){
    //     char letter = argv[i][j];
    //     printf("%c", letter);
    //   }
    // }
  }
  return 0;
}
