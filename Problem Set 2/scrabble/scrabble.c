#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int calculatepoints(string s);

int main(void)
{
    // Prompt the user for two words
    string s1 = get_string("Player 1: ");
    string s2 = get_string("Player 2: ");

    // Compute the score of each word
    int points1 = calculatepoints(s1);
    int points2 = calculatepoints(s2);

    // Print the winner
    if (points1 > points2)
    {
        printf("Player 1 wins!\n");
    }
    else if (points1 < points2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int calculatepoints(string s)
{
    // Tabela de pontuação baseada nos valores do Scrabble
    int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int r = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++)
    {
        if (isalpha(s[i])) // Só processa letras
        {
            char upper = toupper(s[i]);
            r += points[upper - 'A'];
        }
    }
    return r;
}
