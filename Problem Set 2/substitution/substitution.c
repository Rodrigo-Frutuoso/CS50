#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool has_duplicate_characters(string key);

int main(int argc, char *argv[])
{
    // Make sure program was run with just one command-line argument
    if(argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Make sure every character in argv[1] is an alphabetic character
    for(int i = 0; i < strlen(argv[1]); i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }

    // Check if the key has duplicate characters
    if (has_duplicate_characters(argv[1]))
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    string key = argv[1];

    // Prompt user for plaintext
    string s = get_string("plaintext: ");

    int k = 0;
    // Rotate the character
    for(int i = 0; i < strlen(s); i++)
    {
        if(isalpha(s[i]))
        {
            if(islower(s[i]))
            {
                k = s[i] - 97;
                s[i] = tolower(key[k]);
            }
            else
            {
                k = s[i] - 65;
                s[i] = toupper(key[k]);
            }
        }
    }

    printf("ciphertext: %s\n", s);
}

// Function to check if there are duplicate characters in the key
bool has_duplicate_characters(string key)
{
    for(int i = 0; i < 25; i++)
    {
        for(int j = i + 1; j < 26; j++)
        {
            if(toupper(key[i]) == toupper(key[j]))
            {
                return true;
            }
        }
    }
    return false;
}
