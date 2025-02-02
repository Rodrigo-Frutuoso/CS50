#include <cs50.h>
#include <stdio.h>

int getChange(void);
int getMinimumCoins(int n);

int main(void)
{
    int n = getChange();
    int result = getMinimumCoins(n);
    printf("%i\n", result);
}

int getChange(void)
{
    int n;
    do
    {
        n = get_int("Change owed:");
    }
    while (n < 0);

    return n;
}

int getMinimumCoins(int n)
{
    int coins = 0;
    while (n > 0)
    {
        if (n >= 25)
        {
            n = n - 25;
            coins++;
        }
        else if (n >= 10)
        {
            n = n - 10;
            coins++;
        }
        else if (n >= 5)
        {
            n = n - 5;
            coins++;
        }
        else
        {
            coins = coins + n;
            break;
        }
    }
    return coins;
}
