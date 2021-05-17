#include <cs50.h>
#include <stdio.h>

/**
 * FizzBuzz with N = 15
 * 
 * 1:
 * 2:
 * 3: Fizz
 * 4:
 * 5: Buzz
 * 6:
 * 7:
 * ...
 * 15: FizzBuzz
 */
int get_pos_int(void);
int main(void) {

    // Naming Inputs
    int n = get_pos_int();
    
    for (int x = 1; x <= n; x++) {
        
        // Write the number, colon, and space for each line
        printf("%d: " , x);
        
        // Write Fizz if the number we're at is divisible by 3
        if (x % 3 == 0) {
            printf("Fizz");
        }
        
        // Write Buzz if the number we're at is divisible by 5
        if (x % 5 == 0) {
            printf("Buzz");
        }
        
        // New line
        printf("\n");
    }
    
}

// Makes sure a positive number is given
int get_pos_int(void) {
    int n;
    do {
        n = get_int("Positive Integer: ");
    }
    while (n < 1);
    return n;
}