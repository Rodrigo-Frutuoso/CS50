#include <cs50.h>
#include <stdio.h>

int getHeight(void);
void printPyramid(int n);

int main(void)
{
    int n = getHeight();
    printPyramid(n);
}

int getHeight(void)
{
    int n;
    do
    {
        n = get_int("Height:");
    }
    while (n < 1);

    return n;
}

void printPyramid(int n)
{
    for (int row = 1; row <= n; row++)
    {
        for (int j = 0; j < n - row; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < row; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
