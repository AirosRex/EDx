#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

/**
 * Problem: Convert a Roman Numeral string into an Integer
 *
 * Example 1:
 *  - Input: "III"
 *  - Output: 3
 * Example 2:
 *  - Input: "IX"
 *  - Output: 9
 * Example 3:
 *  - Input: "MCMXCIV"
 *  - Output: 1994
 *  - Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 * Symbol Value
 * I      1
 * V      5
 * X      10
 * L      50
 * C      100
 * D      500
 * M      1000
 *
 * You are guaranteed that input argv[1] will be valid
 *  - No need to handle "VVV" for example.
 *
 * make character to number changer
 * look at first number, compare to second
 * if second is less than or equal to, add positive value
 * if second is greater than, subtract value
 */
int translate(char letter);

int main(int argc, string argv[]) {
    string roman = argv[1];
    int length = strlen(roman);
    int sum = 0;

    for (int i = 0, cur = translate(roman[i]); i < length; i++) {
        int next = translate(roman[i + 1]);
        if (cur < next) {
            sum -= cur;
        } else {
            sum += cur;
        }
        cur = next;
    }
    printf("%d \n", sum);
}

int translate(char letter) {
    switch(letter) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}