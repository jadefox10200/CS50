#include <stdio.h>

int collatz(int n);

int main(void){

    int n = 50;
    int steps = collatz(n);
    printf("%i is the number of steps for %i\n", steps, n);
}

int collatz(int n){
    
    if (n == 1){
        return 0;
    }
    if ((n % 2) != 0){
        return 1 + collatz((n*3)+1);
    }else{
        return 1 + collatz(n/2);    
    }
}


// int collatz(int n){
//     if (n == 1){
//         return 1;
//     }
//     if ((n % 2) != 0){
//         counter++;
//         return collatz((n*3)+1);
//     }else{
//         counter++;
//         collatz(n/2);    
//     }
//     return n;
// }

