/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n < 0){
		return false;
	}
    //TODO: implement O(log n):
    int start = 0;
    int listLen = n;
    while (listLen >= start){
        int middle = (listLen+start) / 2;
        if (value == values[middle]){
            return true;
        }else if (value > values[middle]){
            start = middle + 1;
        }else{
            listLen = middle - 1;
        }
    }
    return false;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int counter = 0;
    do{
        counter = 0;
        for (int i = 0; i < n; i++){
            if (values[i] > values[i+1]){
                int temp = values[i];
                values[i] = values[i+1];
                values[i+1] = temp;
                counter++;
            }
        }
    }while(counter > 0);
    return;
}