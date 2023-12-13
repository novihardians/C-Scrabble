#include <stdio.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char word[]); // you running this function with string input

int main(void)
{
    // Get input words from both players
    char word1[50];
    printf("Player 1: ");
    gets(word1);

    char word2[50];
    printf("Player 2: ");
    gets(word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
        printf("Player 1 wins! \n");
    else if (score1 < score2)
        printf("Player 2 wins! \n");
    else
        printf("Tie! \n");
}

int compute_score(char word[])
{
    // TODO: Compute and return score for char, ingore none letter chars
    int score = 0;
    int len = strlen(word);

    for (int i = 0; i < len; i++)
    {
        /*
        In ASCII, the upper and lowercase letters (also, digits) are runs of encoding values assigned in consecutive, increasing order.
        Once you know where the start of the run is, you can get to any other character by simple addition. Likewise, you can reverse that trick using simple subtraction:
        */
        if (isupper(word[i]))
            score += POINTS[word[i] - 'A']; // POINTS['C' - 'A'] equals 3.
        else if (islower(word[i]))
            score += POINTS[word[i] - 'a'];
    }
    return score;
}
