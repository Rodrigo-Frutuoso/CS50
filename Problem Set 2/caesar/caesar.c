#include <ctype.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Make sure program was run with just one command-line argument
    if(argc!=2)
    {
        printf("Usage: %s key \n", argv[0]);
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    for(int i=0; i< strlen(argv[1]);i++)
    {
        if(!isdigit(argv[1][i])){
            printf("Usage: %s key \n", argv[0]);
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    if (key <= 0)
    {
        printf("Usage: %s key \n", argv[0]);
        return 1;
    }

    // Prompt user for plaintext
    string s= get_string("plaintext: ");

    // Rotate the character if it's a letter
    for(int i=0; i< strlen(s);i++)
    {
        if(isalpha(s[i]))
        {
            if(islower(s[i])){
                s[i]=(s[i]-97+key)%26+97;
            }
            else
            {
                s[i]=(s[i]-65+key)%26+65;
            }
        }
    }

    printf("ciphertext: %s\n", s);
}
