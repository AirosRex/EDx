#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int fib(int);
int main(int argc, string argv[]) {

    // DID YOU FUCK IT UP??
    if (argc < 2) {
        printf("Usage: fib [integer]\n");
        return 1;
    }

    //Which digit?
    int digit = atoi(argv[1]);

    // Make the thing
    int answer = fib(digit);
    printf("%i\n", answer);
    return 0;
}

// O(n^2)
int fib(n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    return (fib(n - 1) + fib(n - 2));
}