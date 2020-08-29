#include <cs50.h>
#include <stdio.h>


int main(void)
//Get length of shower from the user as a positive number and then print how much water is used in terms of bottles:
{

    int showerTime = 0;
    do
    {
    printf("Please enter the length of your shower in minutes: \n");
    showerTime = GetInt();
    
    }while(showerTime < 1);
  
    int bottle = 16;
    int gallon = 128;
    int minute = gallon * 1.5;
    int bottlesUsed = (showerTime * minute) / bottle;
    
    printf("You used %i number of bottles of water in your shower\n", bottlesUsed);
}