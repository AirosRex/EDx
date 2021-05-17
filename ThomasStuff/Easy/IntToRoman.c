#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


/*
 * Symbol Value
 * I      1
 * V      5
 * X      10
 * L      50
 * C      100
 * D      500
 * M      1000
 *
 *   // 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 1
 *   // M,    CM,  D,   CD,   C, XC,  L,  XL, X, IX, V, I
 */
int get_valid_value(void);
int main(int argc, string argv[]) {
    int int_values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 1};
    string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX","V","I"};

    int number = get_int("Enter Integer: ");
    int digit = 0, index = 0;
    string solution[26];


    while (index < 12) {
        while (number >= int_values[index]) {
            number -= int_values[index];
            solution[digit++] = numerals[index];
        }
        index++;
    }

    /*
    for (int i = 0; i < 12; i++) {
        int remain = number % int_values[i];
        int repeat = number / int_values[i];
        for (int j = 0; j < repeat; j++){
            solution[place] = (numerals[i]);
            place++;
        }
        number = remain;
    }
    */

    for (int i = 0; i < digit; i++) {
        printf("%s", solution[i]);
    }

    printf("\n");
    return 0;
}
