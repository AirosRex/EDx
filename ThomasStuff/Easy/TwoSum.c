#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

/**
 * Given an array of integers nums and an integer target,
 * return indices of the two numbers such that they add up to target.
 */


int twoSumV1(int length, int values[], int target);
int twoSumV2(int length, int values[], int target);
int main(void) {

    int values[] = {0, 1, 2, 3, 4, 5};
    int target = 2;
    int length = sizeof(values) / sizeof(int);

    // return twoSumV1(length, values, target);
    return twoSumV2(length, values, target);
}

int twoSumV2(int length, int values[], int target) {
    int val1, val2;
    int counter = 0;
    for (int i = 0; i < length; i++) {
        val1 = values[i];
        if (val1 > target) {
            continue;
        }
        
        for (int j = i; j < length; j++) {
            val2 = values[j];
            if (val1 + val2 == target) {
                printf("Target is hit with index %i and %i, making %i + %i = %i\n", i, j, val1, val2, target);
                counter++;
            }
        }
    }
    
    if (counter > 0) {
        printf("There were %i solutions\n", counter);
        return 0;
    }
    
    printf("Sum is not possible\n");
    return 1;
}

// -------------------------------------------------

int twoSumV1(int length, int values[], int target) {
    int END = length - 1;

    int int1, int2;

    for (int1 = 0, int2 = 1; (values[int1] + values[int2]) != target;) {

        // Oh No clause
        if (int1 == (END)) {
            printf("Sum is not possible\n");
            return 1;
        }

       // Check if it is time to reset, otherwise proceed
        if (int2 == END) {
            int1++;
            int2 = int1 + 1;
        } else (int2++);
    }
    printf("Target is hit with index %i and %i, making %i + %i = %i\n", int1, int2, values[int1], values[int2], target);
    return 0;
}