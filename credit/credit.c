#include <cs50.h>
#include <stdio.h>

bool checkCARD(long num, int len);

int main(void)
{
    long num = get_long("Number: ");
    bool bad = true;

    // Check for a 4 at the front and is 13 digits
    if (num / 1000000000000 == 4 && num < 10000000000000)
    {
        if (checkCARD(num, 13))
        {
            printf("VISA\n");
            bad = false;
        }
    }
    // Check for 37 or 34 at the front and is 15 digits
    else if (num < 1000000000000000 && (num / 10000000000000 == 34 || num / 10000000000000 == 37))
    {
        if (checkCARD(num, 15))
        {
            printf("AMEX\n");
            bad = false;
        }
    }
    // Check for 51-55 at the front and is 16 digits
    else if (num < 10000000000000000 && (num / 100000000000000 >= 51 && num / 100000000000000 <= 55))
    {
        if (checkCARD(num, 16))
        {
            printf("MASTERCARD\n");
            bad = false;
        }
    }
    // Check for a 4 at the front and is 16 digits
    else if (num < 10000000000000000 && num / 1000000000000000 == 4)
    {
        if (checkCARD(num, 16))
        {
            printf("VISA\n");
            bad = false;
        }
    }

    if (bad)
    {
        printf("INVALID\n");
    }
}

bool checkCARD(long num, int len)
{
    long pos = 1;
    long temp = 0;
    long odds = 0;
    long evens = 0;

    // Build position to correct length
    for (int i = 0; i < len - 1; i++)
    {
        pos = pos * 10;
    }

    // make loop length depending on even or odd
    int loop = 0;
    if (len % 2 == 0)
    {
        loop = len / 2;
    }
    else
    {
        loop = (len / 2) + 1;
    }

    // loop through each digit an execute algo
    for (int i = 0; i < loop; i++)
    {
        // need to skip this first time around for odd len
        if (len == 16)
        {
            // Get current digit
            temp = num / pos;
            // if 2x current digit is more than 10 add digits not total else add 2x digit
            if (temp * 2 >= 10)
            {
                evens += 1 + ((temp * 2) - 10);
            }
            else
            {
                evens += temp * 2;
            }
            // Remove digit from num
            num = num - (temp * pos);
            // advance position
            pos = pos / 10;
        }

        // Get next digit
        temp = num / pos;
        // add to odd total
        odds += temp;
        // Remove digit from num
        num = num - (temp * posls );
        // advance position
        pos = pos / 10;
        // ensures evens get hit after first loop
        len = 16;
    }

    // Test validity
    return (odds + evens) % 10 == 0;
}