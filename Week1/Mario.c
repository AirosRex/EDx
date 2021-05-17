#include <cs50.h>
#include <stdio.h>

/**
 * The problem is to create an ascending and descending staircase of
 * height - h with one tile gap in the middle
 */
int get_pos_int(void);
int main(void) {

    // Naming Inputs
    int height = get_pos_int();
    int blocks = 1;

    while (height > 0) {
        // Empty Space
        for (int x = 0; x < height; x++) {
            printf(" ");
        }

        // First blocks
        for (int y = 0; y < blocks; y++) {
            printf("X");
        }

        // Mind the gap
        printf(" ");

        // Second set of blocks
        for (int y = 0; y < blocks; y++) {
            printf("X");
        }
        
        // New line and upkeep
        printf("\n");
        height--;
        blocks++;
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