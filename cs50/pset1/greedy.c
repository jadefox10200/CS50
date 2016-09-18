#include <stdio.h>
#include <math.h>

int main(void){
  //GetFloat. The value is hardcoded in this example as
  //I am not using the CS50 appliance
  float change = 0.25;
  
  int counter = 0;
  double new = round(change * 100);
  int remainderValue = new;
  printf("%i\n", remainderValue);
  while (remainderValue > 0){
   if (remainderValue >= 25) {
     remainderValue = remainderValue - 25;
     printf("I was bigger\n");
   }else if (remainderValue >= 10){
     remainderValue = remainderValue - 10;
   }else if (remainderValue >= 5){
     remainderValue = remainderValue - 5;
   }else if (remainderValue >= 1){
     remainderValue = remainderValue - 1;
   }
   counter++;
 }

 if (counter < 2) {
   printf("1 coin was used\n");
 }else{
    printf("%i coins were used\n", counter);
 }
}
