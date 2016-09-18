#include <stdio.h>


void ccChecker(long cc);

 // cc: 378282246310005
int main(void){
  // printf("Enter a credit card number\n");
  // int cc = GetInt()
  long cc = 378282246310005;
  ccChecker(cc);
}

void ccChecker(long cc) {
  printf("%ld\n", cc);
  //get the length of the cc number:
  int counter = 0;
  double lenInterator = (double) cc;
  do{
    lenInterator = lenInterator /10;
    counter++;
  }while (lenInterator > 1);
  printf("%i\n", counter);
  printf("%lg\n", lenInterator);

}
