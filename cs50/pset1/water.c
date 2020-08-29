#include <stdio.h>
#include <cd50.h>

int main(void)
//Get length of shower from the user as a positive number and then print how much water is used in terms of bottles:
{

  int showerTime = 0
  do
  {
    printf("Please enter the length of your shower in minutes: \n", );
    showerTime = GetInt()
    
  }while(showerTime < 1)
  int bottle = 16
  int gallon = 128
  int minute = gallon * 1.5
  int bottlesUsed = (showerTime * minute) / bottle
  printf("You used %i number of bottles of water in your shower\n", bottlesUsed);
}


// shower spits out 1.5 gallons of water per minute.
// A gallon, meanwhile, is 128 ounces,
// and so that shower spits out 1.5 × 128 = 192 ounces of water per minute.
 // A typical bottle of water (that you might have for a drink, not a shower), meanwhile, might be 16 ounces. So taking a 1-minute shower is akin to using 192 ÷ 16 = 12 bottles of water. Taking (more realistically, perhaps!) a 10-minute shower, then, is like using 120 bottles of water. Deer Park, that’s a lot of water! Of course, bottled water itself is wasteful; best to use reusable containers when you can! But it does put into perspective what’s being spent in a shower!
