#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct {
    string name;
    int votes;
} candidate;

/**********************************************
 * THOMAS: GLOBAL VARIABLES?! YOU NAUGHTY BOY *
 **********************************************/

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);
void print_results(void);

int main(int argc, string argv[]) {
    
    // Check for invalid usage
    if (argc < 2) {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // THOMAS: It's debatable, but my gut says this loop is technically more about argv than candidates. I'd personally do the following:
    // THOMAS: for (int i = 1; i < argc; i++) {
    // THOMAS:    candidates[i - 1].name = argv[i];
    // THOMAS: Both are the same... obviously. Main benefit is that the reader doesn't have to hunt for candidate_count's value.
    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    //At this point we have an array of candidates with 0 votes each

    int voter_count = get_int("Number of voters: ");
    for (int i = 0; i < voter_count; i++) {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (vote(name) == false) {
            printf("Invalid vote.\n");
        }
    }

    //At this point we have an array of candidates with accurate votes
    // Display winner of election
    //print_winner();
    print_results();
}

// Update vote totals given a new vote
bool vote(string name) {

    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(name, candidates[i].name) == 0) {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void) {

    int winning = 0;
    string winners;
    for (int i = 0; i < candidate_count; i++){
        if (candidates[i].votes > winning) {
            winning = candidates[i].votes;
            winners = candidates[i].name;
        } else  if (candidates[i].votes == winning) {
            // Nit: Spacing
                    strcat(winners, candidates[i].name);
                }
    }

    printf("Winner(s): %s \n", winners);
    return;
}

// THOMAS: BONUS ROUND
// THOMAS: Print out all the results, ordered from most votes to least
// O(n^2)
void print_results(void) {
    int temp_votes;
    string temp_name;
    for (int i = 0; i < candidate_count; i++) {
        // Nit: no need for parens
        for (int j = (i + 1); j < candidate_count; j++) {
            if (candidates[i].votes < candidates[j].votes) {
                temp_votes = candidates[i].votes;
                temp_name = candidates[i].name;
                candidates[i].votes = candidates[j].votes;
                candidates[i].name = candidates[j].name;
                candidates[j].votes = temp_votes;
                candidates[j].name = temp_name;
            }
        }
    }
    for (int i = 0; i < candidate_count; i++) {
        // Nit: Parens here as well
        printf("%i: %s with %i votes \n", (i+1), candidates[i].name, candidates[i].votes);
    }
    return;
}

