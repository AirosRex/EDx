#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
                    //a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q,  r, s, t, u, v, w, x, y, z

const int MAKE_POINT = 97;
/**
 * my_little_variable
 *  - Functions
 * 
 * MY_LITTLE_VARIABLE
 *  - Constants
 * 
 * MyLittleVariable
 *  - Classes
 * 
 * myLittleVariable
 *  - Variables
 */
int compute_score(string word);

int main(int argc, string argv[]) {
    if (argc != 3) { 
        printf("Please give two words\n");
        return 1;
    }
    
    // Get words
    string word1 = argv[1];
    string word2 = argv[2];
    
    // Get scores
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 == score2) {
        printf("The game is a tie, with a score of %i\n", score1);
    } else if (score1 > score2) {
        printf("Player 1 wins: %s = %i\n", word1, score1);
    } else {
        printf("Player 2 wins: %s = %i\n", word2, score2);
    }
}

int compute_score(string word) {
    int score = 0;

    for (int i = 0, length = strlen(word); i < length; i++) {
        if (isalpha(word[i])) {
            score += POINTS[tolower(word[i]) - MAKE_POINT];
        }
    }
    
    return score;
}