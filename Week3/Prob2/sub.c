#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

/**
 *
 * and implement a program, substitution, that encrypts messages using a substitution cipher.
 *
 * Implement your program in a file called substitution.c in a directory called substitution.
 * Your program must accept a single command-line argument, the key to use for the substitution. The key itself should be case-insensitive, so whether any character in the key is uppercase or lowercase should not affect the behavior of your program.
 * If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
 * If the key is invalid (as by not containing 26 characters, containing any character that is not an alphabetic character, or not containing each letter exactly once), your program should print an error message of your choice (with printf) and return from main a value of 1 immediately.
 * Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string).
 * Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext substituted for the corresponding character in the ciphertext; non-alphabetical characters should be outputted unchanged.
 * Your program must preserve case: capitalized letters must remain capitalized letters; lowercase letters must remain lowercase letters.
 * After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.
 */

// This translates a character's value to it's place in the array
const int CHARACTER_OFFSET = 65;

string cipher(string text, string key);
bool valid(string key);
int make_digit(char letter);

int main(int argc, string argv[]) {
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (!valid(argv[1])) {
        printf("Key must contain all 26 characters once.\n");
        return 2;
    }

    string plain = get_string("plaintext:");
    printf("\nCiphertext: %s \n", cipher(plain, argv[1]));

    return 0;
}

bool valid(string key) {
    int check[26] = {0};
    for (int i = 0; i < 26; i++) {
        if (isalpha(key[i]) == 0 || ++check[make_digit(key[i])] > 1) {
            return false;
        }
    }

    return true;
}

int make_digit(char letter) {
    return toupper(letter) - CHARACTER_OFFSET;
}

string cipher(string text, string key) {
    string ciphered = text;
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int index = make_digit(text[i]);
            ciphered[i] = islower(text[i]) ? tolower(key[index]) : toupper(key[index]);
        } else {
            ciphered[i] = text[i];
        }
    }

    return ciphered;
}