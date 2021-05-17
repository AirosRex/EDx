#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

/**
 * Jump! This is the hardest problem you've tackled yet; You can do it!
 * Take your time to read the examples and truly understand what needs to happen.
 * If it gets too frustrating try tackling some more lab problems and return to this one.
 *
 * Problem:
 *      Given an array of non-negative integers arr, you are initially positioned at start index of the array.
 *      When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
 *
 * Notice:
 *      You can NOT jump outside of the array at any time.
 *
 * Example 1:
 *      Input: arr = [4,2,3,0,3,1,2], start = 5
 *      Output: true
 *      Explanation:
 *          All possible ways to reach index 3 with value 0 are:
 *          index 5 -> index 4 -> index 1 -> index 3
 *          index 5 -> index 6 -> index 4 -> index 1 -> index 3
 *
 * Example 2:
 *      Input: arr = [4,2,3,0,3,1,2], start = 0
 *      Output: true
 *      Explanation:
 *          One possible way to reach index 3 with value 0 is:
 *          index 0 -> index 4 -> index 1 -> index 3
 *
 * Example 3:
 *      Input: arr = [3,0,2,1,2], start = 2
 *      Output: false
 *      Explanation: There is no way to reach index 1 with value 0.
 */
int jumpCount(int arr[], int start, int size);
bool jump(int arr[], int start, int size);


int main(void) {
    int arr[] = {4, 7, 3, 0, 3, 1, 2};
    // int arr[] = {1,1,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 1;
    printf("Numbers of possible ways: %i\n", jumpCount(arr, start, size));
    return 0;
}

/**
 * Complexity Analysis
 * -------------------
 * Time:   O(n)
 * Memory: O(n)
 */
int jumpCount(int arr[], int start, int size) {
    if (start < 0 || start >= size || arr[start] >= size) {
        return 0;
    }

    int up = start + arr[start];
    int down = start - arr[start];
    int count = arr[start] == 0 ? 1 : 0;

    // Mark cell as visited
    arr[start] = size;
    return count + jumpCount(arr, up, size) + jumpCount(arr, down, size);
}

/**
 * Complexity Analysis
 * -------------------
 * Time:   O(n)
 * Memory: O(n)
 */
bool jump(int arr[], int start, int size) {
    // Kill switch
    if (start < 0 || start >= size || arr[start] >= size) {
        return false;
    }

    int up = start + arr[start];
    int down = start - arr[start];

    // Mark cell as visited
    arr[start] = size;

    return arr[start] == 0 || jump(arr, up, size) || jump(arr, down, size);
}
