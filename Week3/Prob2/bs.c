#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>


int make_digit(char letter);

int main(void) {
    char test = 'z';
    int value = test;
    printf("Integer value is %i, %i\n", value, make_digit(value));
    
    
}

int make_digit(char letter) {

    int place = 65; //This translates a character's value to it's place in the array
    return toupper(letter) - place;
}
