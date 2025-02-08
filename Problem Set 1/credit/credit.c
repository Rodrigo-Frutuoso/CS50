#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

long getNumber(void);
bool isValid(long n);
void result(long numbercard);

int main(void)
{
    long n = getNumber();
    result(n);
}

long getNumber(void)
{
    long n;
    do
    {
        n = get_long("Number:");
    }
    while (n < 0);

    return n;
}

bool isValid(long n)
{
    int sum1 = 0;
    int sum2 = 0;
    int sec = 0;
    int resto = 0;

    while (n > 0)
    {
        if (sec == 0)
        {
            resto = n % 10;
            n = n / 10;
            sum2 = sum2 + resto;
            sec = 1;
        }
        else
        {
            resto = 2 * (n % 10);
            n = n / 10;
            sum1 = sum1 + resto % 10 + (resto / 10) % 10;
            sec = 0;
        }
    }

    return (sum1 + sum2) % 10 == 0;
}

void result(long numbercard)
{
    if (!isValid(numbercard))
    {
        printf("INVALID\n");
        return;
    }

    int length = 0;
    for (long l = numbercard; l > 0; l /= 10, length++)
        ;

    int firsts = 0;
    while (numbercard >= 100)
    {
        numbercard = numbercard / 10;
    }
    firsts = numbercard;

    printf("%i %i\n", firsts, length);

    if ((firsts == 34 || firsts == 37) && length == 15)
    {
        printf("AMEX\n");
    }
    else if ((firsts >= 51 && firsts <= 55) && length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if (firsts / 10 == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
