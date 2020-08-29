/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: Check if the uswer as entered at least one or two args. 
    // If not, print the usage and end the program returning 1. 
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // TODO: Targe the first arg entered by the user and put it variable n.
    int n = atoi(argv[1]);

    // TODO: If the user passed a second arg execute srand48 with that value,
    // else use the value of the current time in seconds to execute srand48. 
    // srand48 will basically create a number as a seed for which drand48 can
    // then generate the random number.
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // TODO: Call drand() * LIMIT n times. As drand48 returns a double
    //(a decimal number less than one & greater than 0) it is multiplied by the limit
    // variable which means the output random number will never be larger than the limit variable. 
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}