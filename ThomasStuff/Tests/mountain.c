#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<cs50.h>
/**
 * Alex Test Problem #1
 *
 * Given an array of integers arr, return true if it is a valid mountain array.
 *
 * arr is considered a mountain array if:
 *    arr.length >= 3
 *    There exists some i (mountain peak) with 0 < i < arr.length - 1 such that:
 *       arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
 *       arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 *
 * Examples:
 * Input: [0,2,3,4,5,3,2]
 * Output: true
 * Reason: Values are strictly increasing to a peak (5) then strictly decreasing
 *
 * Input: [0,2,2,4,5,3,2]
 * Output: false
 * Reason: 2 -> 2 is a plateau and is not strictly increasing
 *
 * Input: [0,2]
 * Output: false
 * Reason: Not enough elements
 */

struct TestCase {
  int *input;
  int size;
  bool expected;
};
void printIntArray(int arr[], int n);
bool isMountainThomas(int arr[], int n);
bool isMountainAlex(int arr[], int n);
int main() {
    struct TestCase matrix[] = {
        {(int[]){},          0, false},
        {(int[]){0},         1, false},
        {(int[]){0,1,0},     3, true },
        {(int[]){0,1,1},     3, false},
        {(int[]){1,1,0},     3, false},
        {(int[]){1,2,3},     3, false},
        {(int[]){3,2,1},     3, false},
        {(int[]){0,2,3,2,1}, 5, true },
        {(int[]){1,2,3,2,1}, 5, true },
        {(int[]){1,1,3,2,1}, 5, false},
        {(int[]){1,2,3,3,1}, 5, false},
        {(int[]){1,2,3,2,3,2,1}, 7, false },
    };

    for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++) {
        struct TestCase test = matrix[i];
        if (isMountainAlex(test.input, test.size) == test.expected) {
            printf("PASS - ");
        } else {
            printf("FAIL - ");
        }
        printIntArray(test.input, test.size);
    }

    return 0;
}

void printIntArray(int arr[], int n) {
   printf("{");
   for (int i = 0; i < n; i++) {
      printf(i > 0 ? ",%d" : "%d", arr[i]);
   }
   printf("}\n");
}

bool isMountainAlex(int arr[], int n) {
    bool peak_check = false;

    // Going over the mountain
    for (int i = 0; i < n - 1; i++) {
        // If there's a plateau
        if (arr[i] == arr[i + 1]) {
            return false;
        }

        // Have we found a peak?
        if (arr[i] > arr[i + 1]) {
            peak_check = true;
            if (i == 0) {
                return false;
            }
        }

        // Do we have strictly descending after peak
        if (arr[i] < arr[i + 1] && peak_check) {
            return false;
        }
    }

    return peak_check;
}

bool isMountainThomas(int arr[], int n) {
    int i = 0;
    while (i + 1 < n && arr[i] < arr[i + 1]) {
        i++;
    }

    int j = n - 1;
    while (j > 0 && arr[j] < arr[j + 1]) {
        j--;
    }

    return i > 0 && j < n - 1 && i == j;
}